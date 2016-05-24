LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

# Here we give our module name and source file(s)
LOCAL_MODULE    := hello-android-jni
LOCAL_SRC_FILES := hello-android-jni.c

include $(BUILD_SHARED_LIBRARY)