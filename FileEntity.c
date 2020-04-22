/*
 *
 * FileEntity.c
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

#include "FileEntity.h"

char * FileEntity_charClone(char * arg) {
    int l = strlen(arg) + 1;
    char * ret = (char *) malloc(l);
    for (int i = 0; l > i; ++i) { ret[i] = 0; }
    for (int j = 0; l > j; ++j) { ret[j] = arg[j]; }
    return ret;
}

int endsWithLineFeed(char * arg) {
    if ('\n' == arg[strlen(arg) - 1]) {
        return 1;
    }
    return 0;
}

FileEntity * FileEntity_setPath(FileEntity * fe, char * arg) {
    fe->path = FileEntity_charClone(arg);
    return fe;
}

FileEntity * FileEntity_open(FileEntity * fe) {
    fe->f = fopen(fe->path, "w");
    return fe;
}

FileEntity * FileEntity_writeLine(FileEntity * fe, char * arg) {
    if (endsWithLineFeed(arg)) {
        fprintf(fe->f, "%s", arg);
    }
    else {
        fprintf(fe->f, "%s\n", arg);
    }
    return fe;
}

void FileEntity_dispose(FileEntity * fe) {
    fclose(fe->f);
    free(fe->path);
    free(fe);
}

FileEntity * FileEntity_init() {
    FileEntity * ret = (FileEntity *) malloc(sizeof(FileEntity));
    ret->path = NULL;
    ret->f = NULL;
    ret->setPath = FileEntity_setPath;
    ret->open = FileEntity_open;
    ret->writeLine = FileEntity_writeLine;
    ret->dispose = FileEntity_dispose;
    return ret;
}
