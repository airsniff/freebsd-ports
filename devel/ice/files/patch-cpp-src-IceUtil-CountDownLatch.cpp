--- cpp.orig/src/IceUtil/CountDownLatch.cpp	2011-06-15 21:43:59.000000000 +0200
+++ cpp/src/IceUtil/CountDownLatch.cpp	2012-03-04 20:14:53.000000000 +0100
@@ -44,10 +44,16 @@
 #ifdef _WIN32
     CloseHandle(_event);
 #else
+#ifndef NDEBUG
     int rc = 0;
-    rc = pthread_mutex_destroy(&_mutex);
+    rc = 
+#endif
+    pthread_mutex_destroy(&_mutex);
     assert(rc == 0);
-    rc = pthread_cond_destroy(&_cond);
+#ifndef NDEBUG
+    rc = 
+#endif
+    pthread_cond_destroy(&_cond);
     assert(rc == 0);
 #endif
 }
