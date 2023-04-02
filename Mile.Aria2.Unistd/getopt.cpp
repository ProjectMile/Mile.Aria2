/* NetBSD getopt.c   */

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

inline
const char* _getprogname()
{	return "getopt";
}

int opterr = 1;		/* if error message should be printed */
int optind = 1;		/* index into parent argv vector */
int optopt = 0;			/* character checked for validity */
int optreset = 0;		/* reset getopt */
const char	*optarg = "";		/* argument associated with option */

#define	BADCH	(int)'?'
#define	BADARG	(int)':'
#define	EMSG	""

/*
 * getopt --
 *	Parse argc/argv argument vector.
 */

int getopt(int nargc,char * const nargv[],const char *ostr)
{
	static const char *place = EMSG;		/* option letter processing */
	const char *oli;				/* option letter list index */

	if (optreset || *place == 0) {		/* update scanning pointer */
		optreset = 0;
		place = nargv[optind];
		if (optind >= nargc || *place++ != '-') {
			/* Argument is absent or is not an option */
			place = EMSG;
			return (-1);
		}
		optopt = *place++;
		if (optopt == '-' && *place == 0) {
			/* "--" => end of options */
			++optind;
			place = EMSG;
			return (-1);
		}
		if (optopt == 0) {
			/* Solitary '-', treat as a '-' option
			   if the program (eg su) is looking for it. */
			place = EMSG;
			if (strchr(ostr, '-') == NULL)
				return (-1);
			optopt = '-';
		}
	} else
		optopt = *place++;

	/* See if option letter is one the caller wanted... */
	if (optopt == ':' || (oli = strchr(ostr, optopt)) == NULL) {
		if (*place == 0)
			++optind;
		if (opterr && *ostr != ':')
			(void)fprintf(stderr,
			    "%s: illegal option -- %c\n", _getprogname(),
			    optopt);
		return (BADCH);
	}

	/* Does this option need an argument? */
	if (oli[1] != ':') {
		/* don't need argument */
		optarg = NULL;
		if (*place == 0)
			++optind;
	} else {
		/* Option-argument is either the rest of this argument or the
		   entire next argument. */
		if (*place)
			optarg = place;
		else if (nargc > ++optind)
			optarg = nargv[optind];
		else {
			/* option-argument absent */
			place = EMSG;
			if (*ostr == ':')
				return (BADARG);
			if (opterr)
				(void)fprintf(stderr,
				    "%s: option requires an argument -- %c\n",
				    _getprogname(), optopt);
			return (BADCH);
		}
		place = EMSG;
		++optind;
	}
	return (optopt);			/* return option letter */
}

int getopt_long(int argc, char *const argv[],
			const char *optstring,
			const struct option * longopts, int *longindex)
{
	static const char *place = EMSG;	/* option letter processing */
    const char *oli;			/* option letter list index */

	if (optreset || !*place)
	{							/* update scanning pointer */
		optreset = 0;

		if (optind >= argc)
		{
			place = EMSG;
			return -1;
		}

		place = argv[optind];

		if (place[0] != '-')
		{
			place = EMSG;
			return -1;
		}

		place++;

		if (place[0] && place[0] == '-' && place[1] == '\0')
		{						/* found "--" */
			++optind;
			place = EMSG;
			return -1;
		}

		if (place[0] && place[0] == '-' && place[1])
		{
			/* long option */
			size_t		namelen;
			int			i;

			place++;

			namelen = strcspn(place, "=");
			for (i = 0; longopts[i].name != NULL; i++)
			{
				if (strlen(longopts[i].name) == namelen
					&& strncmp(place, longopts[i].name, namelen) == 0)
				{
					if (longopts[i].has_arg)
					{
						if (place[namelen] == '=')
							optarg = place + namelen + 1;
						else if (optind < argc - 1)
						{
							optind++;
							optarg = argv[optind];
						}
						else
						{
							if (optstring[0] == ':')
								return BADARG;
							if (opterr)
								fprintf(stderr,
								   "%s: option requires an argument -- %s\n",
										argv[0], place);
							place = EMSG;
							optind++;
							return BADCH;
						}
					}
					else
					{
						optarg = NULL;
						if (place[namelen] != 0)
						{
							/* XXX error? */
						}
					}

					optind++;

					if (longindex)
						*longindex = i;

					place = EMSG;

					if (longopts[i].flag == NULL)
						return longopts[i].val;
					else
					{
						*longopts[i].flag = longopts[i].val;
						return 0;
					}
				}
			}

			if (opterr && optstring[0] != ':')
				fprintf(stderr,
						"%s: illegal option -- %s\n", argv[0], place);
			place = EMSG;
			optind++;
			return BADCH;
		}
	}

	/* short option */
	optopt = (int) *place++;

	oli = strchr(optstring, optopt);
	if (!oli)
	{
		if (!*place)
			++optind;
		if (opterr && *optstring != ':')
			fprintf(stderr,
					"%s: illegal option -- %c\n", argv[0], optopt);
		return BADCH;
	}

	if (oli[1] != ':')
	{							/* don't need argument */
		optarg = NULL;
		if (!*place)
			++optind;
	}
	else
	{							/* need an argument */
		if (*place)				/* no white space */
			optarg = place;
		else if (argc <= ++optind)
		{						/* no arg */
			place = EMSG;
			if (*optstring == ':')
				return BADARG;
			if (opterr)
				fprintf(stderr,
						"%s: option requires an argument -- %c\n",
						argv[0], optopt);
			return BADCH;
		}
		else
			/* white space */
			optarg = argv[optind];
		place = EMSG;
		++optind;
	}
	return optopt;
}
