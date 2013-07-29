/* librepo - A library providing (libcURL like) API to downloading repository
 * Copyright (C) 2013  Tomas Mlcoch
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 */

#ifndef LR_XMLPARSER_H
#define LR_XMLPARSER_H

#ifdef __cplusplus
extern "C" {
#endif

/** \defgroup xmlparser     Common stuff for XML parsers in Librepo (datatypes, etc.)
 *  \addtogroup xmlparser
 *  @{
 */

#define LR_CB_RET_OK    0 /*!< Return value for callbacks signalizing success */
#define LR_CB_RET_ERR   1 /*!< Return value for callbacks signalizing error */

/** Type of warnings reported by parsers by the warning callback.
 */
typedef enum {
    LR_XML_WARNING_UNKNOWNTAG,  /*!< Unknown tag */
    LR_XML_WARNING_MISSINGATTR, /*!< Missing attribute */
    LR_XML_WARNING_UNKNOWNVAL,  /*!< Unknown tag or attribute value */
    LR_XML_WARNING_BADATTRVAL,  /*!< Bad attribute value */
    LR_XML_WARNING_MISSINGVAL,  /*!< Missing tag value */
    LR_XML_WARNING_SENTINEL,
} lr_XmlParserWarningType;

/** Callback for XML parser warnings. All reported warnings are non-fatal,
 * and ignored by default. But if callback return LR_CB_RET_ERR instead of
 * LR_CB_RET_OK then parsing is immediately interrupted.
 * @param type      Type of warning
 * @param msg       Warning msg. The message is destroyed after the call.
 *                  If you want touse the message later, you have to copy it.
 * @param cbdata    User data.
 * @param err       GError **
 * @return          LR_CB_RET_OK (0) or LR_CB_RET_ERR (1) - stops the parsing
 */
typedef int (*lr_XmlParserWarningCb)(lr_XmlParserWarningType type,
                                     char *msg,
                                     void *cbdata,
                                     GError **err);

/** @} */

#ifdef __cplusplus
}
#endif

#endif