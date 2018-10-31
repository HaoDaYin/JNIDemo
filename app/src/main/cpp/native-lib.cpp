#include <jni.h>
#include <string>
#include <iostream>

using namespace std;
extern "C" JNIEXPORT jstring

JNICALL
Java_com_example_app_jnidemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
jobject user;

extern "C" JNIEXPORT jobject JNICALL
Java_com_example_app_jnidemo_MainActivity_getUser(
        JNIEnv *env,
        jobject /* this */
        ) {


    jstring name = env->NewStringUTF("Dain is a good man for getUserFun");
    jclass userClass = env->FindClass("com/example/app/jnidemo/User");
    jmethodID userMethod = env->GetMethodID(userClass, "<init>", "()V");
    jfieldID juserName = env->GetFieldID(userClass, "name", "Ljava/lang/String;");
    jobject userObject = env->NewObject(userClass, userMethod);
    env->SetObjectField(userObject, juserName, name);

//    cout<<"<<<<<"<<"dddd"<<endl;

    return userObject;
}
extern "C" JNIEXPORT jobject JNICALL
Java_com_example_app_jnidemo_MainActivity_getUserClassName(
        JNIEnv *env,
        jobject /* this */,
        jobject user) {


    jstring name = env->NewStringUTF("Dain is a good man for getUserClassName");
//    jclass userClass = env->FindClass("com/example/app/jnidemo/User");
    jclass userClass = env->GetObjectClass(user);
    jmethodID userMethod = env->GetMethodID(userClass, "<init>", "()V");
    jfieldID juserName = env->GetFieldID(userClass, "name", "Ljava/lang/String;");
    jobject userObject = env->NewObject(userClass, userMethod);
    env->SetObjectField(userObject, juserName, name);

    return userObject;
}

extern "C" JNIEXPORT jobject
JNICALL
Java_com_example_app_jnidemo_MainActivity_setUserName(
        JNIEnv *env,
        jobject /* this */,
        jstring userName) {


    jclass userClass = env->FindClass("com/example/app/jnidemo/User");
    jmethodID userMethod = env->GetMethodID(userClass, "<init>", "()V");
    jfieldID juserName = env->GetFieldID(userClass, "name", "Ljava/lang/String;");
    jobject userObject = env->NewObject(userClass, userMethod);
    env->SetObjectField(userObject, juserName, userName);

    user = userObject;

    return user;

}

