# Copyright (c) 2000, 2011, Oracle and/or its affiliates. All rights reserved.
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; version 2 of the License.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA

MYSQLDATAdir =		$(localstatedir)
MYSQLSHAREdir =		$(pkgdatadir)
MYSQLBASEdir=		$(prefix)
INCLUDES =		@ZLIB_INCLUDES@ -I$(top_builddir)/include \
			-I$(top_srcdir)/include -I$(srcdir)
pkglib_LIBRARIES =	libmysys.a
LDADD =			libmysys.a $(top_builddir)/strings/libmystrings.a $(top_builddir)/dbug/libdbug.a
noinst_HEADERS =	mysys_priv.h my_static.h my_handler_errors.h
libmysys_a_SOURCES =    my_init.c my_getwd.c mf_getdate.c my_mmap.c \
			mf_path.c mf_loadpath.c my_file.c \
			my_open.c my_create.c my_dup.c my_seek.c my_read.c \
			my_pread.c my_write.c my_getpagesize.c \
			mf_keycaches.c my_crc32.c \
			mf_iocache.c mf_iocache2.c mf_cache.c mf_tempfile.c \
			mf_tempdir.c my_lock.c mf_brkhant.c my_alarm.c \
			my_malloc.c my_realloc.c my_once.c mulalloc.c \
			my_alloc.c safemalloc.c my_new.cc \
			my_vle.c my_fopen.c my_fstream.c my_getsystime.c \
			my_error.c errors.c my_div.c my_messnc.c \
			mf_format.c mf_same.c mf_dirname.c mf_fn_ext.c \
			my_symlink.c my_symlink2.c \
			mf_pack.c mf_unixpath.c mf_arr_appstr.c \
			mf_wcomp.c mf_wfile.c my_gethwaddr.c \
			mf_qsort.c mf_qsort2.c mf_sort.c \
			ptr_cmp.c mf_radix.c queues.c my_getncpus.c \
			tree.c trie.c list.c hash.c array.c string.c typelib.c \
			my_copy.c my_append.c my_lib.c \
			my_delete.c my_rename.c my_redel.c \
			my_chsize.c my_clock.c \
			my_quick.c my_lockmem.c my_static.c \
			my_sync.c my_getopt.c my_mkdir.c \
			default_modify.c default.c \
                        my_compress.c checksum.c \
			my_net.c my_sleep.c \
			charset.c charset-def.c my_bitmap.c my_bit.c md5.c \
			rijndael.c my_aes.c sha1.c \
			my_compare.c my_netware.c my_largepage.c \
			my_memmem.c stacktrace.c \
			my_windac.c my_access.c base64.c my_libwrap.c

if NEED_THREAD
# mf_keycache is used only in the server, so it is safe to leave the file
# out of the non-threaded library.
# In fact, it will currently not compile without thread support.
libmysys_a_SOURCES +=   mf_keycache.c
endif

EXTRA_DIST =		thr_alarm.c thr_lock.c my_pthread.c my_thr_init.c \
			thr_mutex.c thr_rwlock.c \
			CMakeLists.txt mf_soundex.c \
			my_conio.c my_wincond.c my_winthread.c
libmysys_a_LIBADD =	@THREAD_LOBJECTS@
# test_dir_DEPENDENCIES=	$(LIBRARIES)
# testhash_DEPENDENCIES=	$(LIBRARIES)
# test_charset_DEPENDENCIES=	$(LIBRARIES)
# charset2html_DEPENDENCIES=	$(LIBRARIES)
DEFS =			-DDEFAULT_BASEDIR=\"$(prefix)\" \
			-DMYSQL_DATADIR="\"$(MYSQLDATAdir)\"" \
			-DDEFAULT_CHARSET_HOME="\"$(MYSQLBASEdir)\"" \
			-DSHAREDIR="\"$(MYSQLSHAREdir)\"" \
			-DDEFAULT_HOME_ENV=MYSQL_HOME \
			-DDEFAULT_GROUP_SUFFIX_ENV=MYSQL_GROUP_SUFFIX \
			-DDEFAULT_SYSCONFDIR="\"$(sysconfdir)\"" \
                        @DEFS@

libmysys_a_DEPENDENCIES= @THREAD_LOBJECTS@

# I hope this always does the right thing. Otherwise this is only test programs
FLAGS=$(DEFS) $(INCLUDES) $(CPPFLAGS) $(CFLAGS) @NOINST_LDFLAGS@

#
# The CP .. RM stuff is to avoid problems with some compilers (like alpha ccc)
# which automaticly removes the object files you use to compile a final program
#

test_bitmap$(EXEEXT): my_bitmap.c $(LIBRARIES)
	$(LINK) $(FLAGS) -DMAIN  ./my_bitmap.c $(LDADD) $(LIBS)

test_priority_queue$(EXEEXT): queues.c $(LIBRARIES)
	$(LINK) $(FLAGS) -DMAIN  ./queues.c $(LDADD) $(LIBS)

test_thr_alarm$(EXEEXT): thr_alarm.c $(LIBRARIES)
	$(CP) $(srcdir)/thr_alarm.c ./test_thr_alarm.c
	$(LINK) $(FLAGS) -DMAIN  ./test_thr_alarm.c $(LDADD) $(LIBS)
	$(RM) -f ./test_thr_alarm.c

test_thr_lock$(EXEEXT): thr_lock.c $(LIBRARIES)
	$(CP) $(srcdir)/thr_lock.c test_thr_lock.c
	$(LINK) $(FLAGS) -DMAIN  ./test_thr_lock.c $(LDADD) $(LIBS)
	$(RM) -f ./test_thr_lock.c

test_vsnprintf$(EXEEXT): my_vsnprintf.c $(LIBRARIES)
	$(CP) $(srcdir)/my_vsnprintf.c test_vsnprintf.c
	$(LINK) $(FLAGS) -DMAIN ./test_vsnprintf.c $(LDADD) $(LIBS)
	$(RM) -f test_vsnprintf.c

test_io_cache$(EXEEXT): mf_iocache.c $(LIBRARIES)
	$(CP) $(srcdir)/mf_iocache.c test_io_cache.c
	$(LINK) $(FLAGS) -DMAIN ./test_io_cache.c $(LDADD) $(LIBS)
	$(RM) -f test_io_cache.c

test_dir$(EXEEXT): test_dir.c $(LIBRARIES)
	$(LINK) $(FLAGS) -DMAIN $(srcdir)/test_dir.c $(LDADD) $(LIBS)

test_charset$(EXEEXT): test_charset.c $(LIBRARIES)
	$(LINK) $(FLAGS) -DMAIN $(srcdir)/test_charset.c $(LDADD) $(LIBS)

testhash$(EXEEXT): testhash.c $(LIBRARIES)
	$(LINK) $(FLAGS) -DMAIN $(srcdir)/testhash.c $(LDADD) $(LIBS)

test_gethwaddr$(EXEEXT): my_gethwaddr.c $(LIBRARIES)
	$(CP) $(srcdir)/my_gethwaddr.c ./test_gethwaddr.c
	$(LINK) $(FLAGS) -DMAIN  ./test_gethwaddr.c $(LDADD) $(LIBS)
	$(RM) -f ./test_gethwaddr.c

test_base64$(EXEEXT): base64.c $(LIBRARIES)
	$(CP) $(srcdir)/base64.c ./test_base64.c
	$(LINK) $(FLAGS) -DMAIN  ./test_base64.c $(LDADD) $(LIBS)
	$(RM) -f ./test_base64.c

# Don't update the files from bitkeeper
%::SCCS/s.%
