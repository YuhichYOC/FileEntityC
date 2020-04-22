/*
 *
 * FileEntity.h
 *
 * Copyright 2020 Yuichi Yoshii
 *     吉井雄一 @ 吉井産業  you.65535.kir@gmail.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef INCLUDE_STDIO_H
#define INCLUDE_STDIO_H
#include <stdio.h>
#endif

#ifndef INCLUDE_STDLIB_H
#define INCLUDE_STDLIB_H
#include <stdlib.h>
#endif

#ifndef INCLUDE_STRING_H
#define INCLUDE_STRING_H
#include <string.h>
#endif

#ifndef INCLUDE_ERRNO_H
#define INCLUDE_ERRNO_H
#include <errno.h>
#endif

#ifndef INCLUDE_LOCALE_H
#define INCLUDE_LOCALE_H
#include <locale.h>
#endif

#ifndef INCLUDE_WCHAR_H
#define INCLUDE_WCHAR_H
#include <wchar.h>
#endif

#ifndef DECLARE_FILEENTITY_H
#define DECLARE_FILEENTITY_H

typedef struct _fileEntity {
    char * path;
    FILE * f;
    struct _fileEntity * (* setPath)(struct _fileEntity *, char *);
    struct _fileEntity * (* open)(struct _fileEntity *);
    struct _fileEntity * (* writeLine)(struct _fileEntity *, char *);
    void (*dispose)(struct _fileEntity *);
} FileEntity;

FileEntity * FileEntity_init(void);

#endif
