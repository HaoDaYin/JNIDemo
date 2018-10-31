#include <jni.h>
#include <string>
#include <iostream>
#include<android/log.h>


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
Java_com_example_app_jnidemo_MainActivity_getUserClassForFindClass(
        JNIEnv *env,
        jobject /* this */
) {

    jstring name = env->NewStringUTF("Dain is a good man for getUserFun");
    jclass userClass = env->FindClass("com/example/app/jnidemo/User");
    jmethodID userMethod = env->GetMethodID(userClass, "<init>", "()V");
    jfieldID juserName = env->GetFieldID(userClass, "name", "Ljava/lang/String;");
    jobject userObject = env->NewObject(userClass, userMethod);
    env->SetObjectField(userObject, juserName, name);

//    __android_log_print(ANDROID_LOG_INFO, LOG, "111=%s\nname");


    return userObject;
}
extern "C" JNIEXPORT jobject JNICALL
Java_com_example_app_jnidemo_MainActivity_getUserClassForGetObjectClass(
        JNIEnv *env,
        jobject /* this */,
        jobject user) {


    jstring name = env->NewStringUTF("Dain is a good man for getUserClassName");
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
extern "C" JNIEXPORT jobject
JNICALL
Java_com_example_app_jnidemo_MainActivity_getArrayList(
        JNIEnv *env,
        jobject /* this */
) {


    jclass cls_ArrayList = env->FindClass("java/util/ArrayList");
    jmethodID construct = env->GetMethodID(cls_ArrayList, "<init>", "()V");
    jobject obj_ArrayList = env->NewObject(cls_ArrayList, construct, "");
    jmethodID arrayList_add = env->GetMethodID(cls_ArrayList, "add", "(Ljava/lang/Object;)Z");
    //User Object
    jclass cls_user = env->FindClass("com/example/app/jnidemo/User");
    //none argument construct function
    jmethodID construct_user = env->GetMethodID(cls_user, "<init>", "()V");
    //new a object
//    jobject obj_user = env->NewObject(cls_user,construct_user,"");
    //get method id
    jmethodID user_setUserName = env->GetMethodID(cls_user, "name", "(Ljava/lang/String;)V");


    return obj_ArrayList;

}
#include <vector>

extern "C" JNIEXPORT void
JNICALL
Java_com_example_app_jnidemo_MainActivity_setArrayList(
        JNIEnv *env,
        jobject /* this */,
        jobject userList) {
    int i;

//    vector<string> vectorStr;

    //class ArrayList
    jclass cls_arraylist = env->GetObjectClass(userList);
    //method in class ArrayList
    jmethodID arraylist_get = env->GetMethodID(cls_arraylist, "get", "(I)Ljava/lang/Object;");
    jmethodID arraylist_size = env->GetMethodID(cls_arraylist, "size", "()I");
    jint len = env->CallIntMethod(userList, arraylist_size);
    __android_log_print(ANDROID_LOG_INFO, "CPrint",
                        "get java ArrayList<User> object by C++ , then print it...../n");

    for (i = 0; i < len; i++) {
        //获取泛型类
        jobject obj_user = env->CallObjectMethod(userList, arraylist_get, i);
        jclass cls_user = env->GetObjectClass(obj_user);
        jmethodID user_getUserName = env->GetMethodID(cls_user, "getName", "()Ljava/lang/String;");
        jstring name = (jstring) env->CallObjectMethod(obj_user, user_getUserName);
        jboolean b = true;
        const char *namePtr = env->GetStringUTFChars(name, &b);
        __android_log_print(ANDROID_LOG_INFO,"TAG","name = %s",namePtr);

    }
}

