﻿/* <!-- copyright */
/*
 * aria2 - The high speed download utility
 *
 * Copyright (C) 2006 Tatsuhiro Tsujikawa
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */
/* copyright --> */
#include "common.h"

#include <unistd.h>

#include <aria2/aria2.h>
#include "Context.h"
#include "MultiUrlRequestInfo.h"
#include "message.h"
#include "Platform.h"
#include "Exception.h"
#include "console.h"
#include "LogFactory.h"

extern "C" int aria2_main(int argc, char** argv)
{
  aria2::error_code::Value r;
  aria2::global::initConsole(false);
  try {
    aria2::Platform platform;
    aria2::Context context(true, argc, argv, aria2::KeyVals());
    r = aria2::error_code::FINISHED;
    if (context.reqinfo) {
        r = context.reqinfo->execute();
    }
  }
  catch (aria2::Exception& ex) {
    aria2::global::cerr()->printf("%s\n%s\n", EX_EXCEPTION_CAUGHT,
                                  ex.stackTrace().c_str());
    r = ex.getErrorCode();
  }
  return r;
}
