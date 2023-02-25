/*
 * JNI glue code. You should not edit this file.
 * Generated from WebIDL model 'PhysXJni' by webidl-util.
 */
#include <jni.h>

static JavaVM * javaVm = NULL;

class JniThreadEnv {
    public:
        JniThreadEnv() : shouldDetach(false), env(NULL) { }
        JniThreadEnv(JNIEnv *env) : shouldDetach(false), env(env) { }
        ~JniThreadEnv() {
            if (shouldDetach) {
                javaVm->DetachCurrentThread();
            }
        }
        JNIEnv* getEnv() {
            if (env == NULL && javaVm != NULL) {
                javaVm->AttachCurrentThreadAsDaemon((void**) &env, NULL);
                shouldDetach = true;
            }
            return env;
        }
        
    private:
        bool shouldDetach;
        JNIEnv *env;
};

static thread_local JniThreadEnv jniThreadEnv;

class JniThreadManager {
    public:
        static bool init(JNIEnv *env) {
            if (env->GetJavaVM(&javaVm) != 0) {
                return false;
            }
            jniThreadEnv = JniThreadEnv(env);
            return true;
        }
};

class JavaNativeRef {
    public:
        JavaNativeRef(JNIEnv *env, jobject javaRef) {
            javaGlobalRef = env->NewGlobalRef(javaRef);
        }
        
        ~JavaNativeRef() {
            jniThreadEnv.getEnv()->DeleteGlobalRef(javaGlobalRef);
        }
        
        jobject javaGlobalRef;
};

class PxControllerBehaviorCallbackImpl : SimpleControllerBehaviorCallback {
    public:
        PxControllerBehaviorCallbackImpl(JNIEnv* env, jobject javaLocalRef) {
            javaGlobalRef = env->NewGlobalRef(javaLocalRef);
            jclass javaClass = env->GetObjectClass(javaLocalRef);
            getShapeBehaviorFlagsMethodId = env->GetMethodID(javaClass, "_getShapeBehaviorFlags", "(JJ)I");
            getControllerBehaviorFlagsMethodId = env->GetMethodID(javaClass, "_getControllerBehaviorFlags", "(J)I");
            getObstacleBehaviorFlagsMethodId = env->GetMethodID(javaClass, "_getObstacleBehaviorFlags", "(J)I");
        }
        
        ~PxControllerBehaviorCallbackImpl() {
            jniThreadEnv.getEnv()->DeleteGlobalRef(javaGlobalRef);
        }
        
        virtual unsigned int getShapeBehaviorFlags(const physx::PxShape& shape, const physx::PxActor& actor) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            return _env->CallIntMethod(javaGlobalRef, getShapeBehaviorFlagsMethodId, (jlong) &shape, (jlong) &actor);
        }

        virtual unsigned int getControllerBehaviorFlags(const physx::PxController& controller) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            return _env->CallIntMethod(javaGlobalRef, getControllerBehaviorFlagsMethodId, (jlong) &controller);
        }

        virtual unsigned int getObstacleBehaviorFlags(const physx::PxObstacle& obstacle) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            return _env->CallIntMethod(javaGlobalRef, getObstacleBehaviorFlagsMethodId, (jlong) &obstacle);
        }

    private:
        jobject javaGlobalRef;
        jmethodID getShapeBehaviorFlagsMethodId;
        jmethodID getControllerBehaviorFlagsMethodId;
        jmethodID getObstacleBehaviorFlagsMethodId;
};

class PxControllerFilterCallbackImpl : physx::PxControllerFilterCallback {
    public:
        PxControllerFilterCallbackImpl(JNIEnv* env, jobject javaLocalRef) {
            javaGlobalRef = env->NewGlobalRef(javaLocalRef);
            jclass javaClass = env->GetObjectClass(javaLocalRef);
            filterMethodId = env->GetMethodID(javaClass, "_filter", "(JJ)Z");
        }
        
        ~PxControllerFilterCallbackImpl() {
            jniThreadEnv.getEnv()->DeleteGlobalRef(javaGlobalRef);
        }
        
        virtual bool filter(const physx::PxController& a, const physx::PxController& b) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            return _env->CallBooleanMethod(javaGlobalRef, filterMethodId, (jlong) &a, (jlong) &b);
        }

    private:
        jobject javaGlobalRef;
        jmethodID filterMethodId;
};

class PxUserControllerHitReportImpl : physx::PxUserControllerHitReport {
    public:
        PxUserControllerHitReportImpl(JNIEnv* env, jobject javaLocalRef) {
            javaGlobalRef = env->NewGlobalRef(javaLocalRef);
            jclass javaClass = env->GetObjectClass(javaLocalRef);
            onShapeHitMethodId = env->GetMethodID(javaClass, "_onShapeHit", "(J)V");
            onControllerHitMethodId = env->GetMethodID(javaClass, "_onControllerHit", "(J)V");
            onObstacleHitMethodId = env->GetMethodID(javaClass, "_onObstacleHit", "(J)V");
        }
        
        ~PxUserControllerHitReportImpl() {
            jniThreadEnv.getEnv()->DeleteGlobalRef(javaGlobalRef);
        }
        
        virtual void onShapeHit(const physx::PxControllerShapeHit& hit) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, onShapeHitMethodId, (jlong) &hit);
        }

        virtual void onControllerHit(const physx::PxControllersHit& hit) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, onControllerHitMethodId, (jlong) &hit);
        }

        virtual void onObstacleHit(const physx::PxControllerObstacleHit& hit) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, onObstacleHitMethodId, (jlong) &hit);
        }

    private:
        jobject javaGlobalRef;
        jmethodID onShapeHitMethodId;
        jmethodID onControllerHitMethodId;
        jmethodID onObstacleHitMethodId;
};

class PxErrorCallbackImpl : physx::PxErrorCallback {
    public:
        PxErrorCallbackImpl(JNIEnv* env, jobject javaLocalRef) {
            javaGlobalRef = env->NewGlobalRef(javaLocalRef);
            jclass javaClass = env->GetObjectClass(javaLocalRef);
            reportErrorMethodId = env->GetMethodID(javaClass, "_reportError", "(ILjava/lang/String;Ljava/lang/String;I)V");
        }
        
        ~PxErrorCallbackImpl() {
            jniThreadEnv.getEnv()->DeleteGlobalRef(javaGlobalRef);
        }
        
        virtual void reportError(PxErrorCodeEnum code, const char* message, const char* file, int line) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, reportErrorMethodId, (jint) code, _env->NewStringUTF(message), _env->NewStringUTF(file), (jint) line);
        }

    private:
        jobject javaGlobalRef;
        jmethodID reportErrorMethodId;
};

class SimpleCustomGeometryCallbacksImpl : SimpleCustomGeometryCallbacks {
    public:
        SimpleCustomGeometryCallbacksImpl(JNIEnv* env, jobject javaLocalRef) {
            javaGlobalRef = env->NewGlobalRef(javaLocalRef);
            jclass javaClass = env->GetObjectClass(javaLocalRef);
            getLocalBoundsImplMethodId = env->GetMethodID(javaClass, "_getLocalBoundsImpl", "(J)J");
            generateContactsImplMethodId = env->GetMethodID(javaClass, "_generateContactsImpl", "(JJJJFFFJ)Z");
            raycastImplMethodId = env->GetMethodID(javaClass, "_raycastImpl", "(JJJJFJIJI)I");
            overlapImplMethodId = env->GetMethodID(javaClass, "_overlapImpl", "(JJJJ)Z");
            sweepImplMethodId = env->GetMethodID(javaClass, "_sweepImpl", "(JFJJJJJJF)Z");
            computeMassPropertiesImplMethodId = env->GetMethodID(javaClass, "_computeMassPropertiesImpl", "(JJ)V");
            usePersistentContactManifoldImplMethodId = env->GetMethodID(javaClass, "_usePersistentContactManifoldImpl", "(J)Z");
        }
        
        ~SimpleCustomGeometryCallbacksImpl() {
            jniThreadEnv.getEnv()->DeleteGlobalRef(javaGlobalRef);
        }
        
        virtual physx::PxBounds3* getLocalBoundsImpl(const physx::PxGeometry& geometry) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            return (physx::PxBounds3*) _env->CallLongMethod(javaGlobalRef, getLocalBoundsImplMethodId, (jlong) &geometry);
        }

        virtual bool generateContactsImpl(const physx::PxGeometry& geom0, const physx::PxGeometry& geom1, const physx::PxTransform& pose0, const physx::PxTransform& pose1, float contactDistance, float meshContactMargin, float toleranceLength, physx::PxContactBuffer& contactBuffer) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            return _env->CallBooleanMethod(javaGlobalRef, generateContactsImplMethodId, (jlong) &geom0, (jlong) &geom1, (jlong) &pose0, (jlong) &pose1, (jfloat) contactDistance, (jfloat) meshContactMargin, (jfloat) toleranceLength, (jlong) &contactBuffer);
        }

        virtual unsigned int raycastImpl(const physx::PxVec3& origin, const physx::PxVec3& unitDir, const physx::PxGeometry& geom, const physx::PxTransform& pose, float maxDist, physx::PxHitFlags& hitFlags, unsigned int maxHits, physx::PxGeomRaycastHit* rayHits, unsigned int stride) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            return _env->CallIntMethod(javaGlobalRef, raycastImplMethodId, (jlong) &origin, (jlong) &unitDir, (jlong) &geom, (jlong) &pose, (jfloat) maxDist, (jlong) &hitFlags, (jint) maxHits, (jlong) rayHits, (jint) stride);
        }

        virtual bool overlapImpl(const physx::PxGeometry& geom0, const physx::PxTransform& pose0, const physx::PxGeometry& geom1, const physx::PxTransform& pose1) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            return _env->CallBooleanMethod(javaGlobalRef, overlapImplMethodId, (jlong) &geom0, (jlong) &pose0, (jlong) &geom1, (jlong) &pose1);
        }

        virtual bool sweepImpl(const physx::PxVec3& unitDir, float maxDist, const physx::PxGeometry& geom0, const physx::PxTransform& pose0, const physx::PxGeometry& geom1, const physx::PxTransform& pose1, physx::PxGeomSweepHit& sweepHit, physx::PxHitFlags& hitFlags, float inflation) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            return _env->CallBooleanMethod(javaGlobalRef, sweepImplMethodId, (jlong) &unitDir, (jfloat) maxDist, (jlong) &geom0, (jlong) &pose0, (jlong) &geom1, (jlong) &pose1, (jlong) &sweepHit, (jlong) &hitFlags, (jfloat) inflation);
        }

        virtual void computeMassPropertiesImpl(const physx::PxGeometry& geometry, physx::PxMassProperties& massProperties) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, computeMassPropertiesImplMethodId, (jlong) &geometry, (jlong) &massProperties);
        }

        virtual bool usePersistentContactManifoldImpl(const physx::PxGeometry& geometry) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            return _env->CallBooleanMethod(javaGlobalRef, usePersistentContactManifoldImplMethodId, (jlong) &geometry);
        }

    private:
        jobject javaGlobalRef;
        jmethodID getLocalBoundsImplMethodId;
        jmethodID generateContactsImplMethodId;
        jmethodID raycastImplMethodId;
        jmethodID overlapImplMethodId;
        jmethodID sweepImplMethodId;
        jmethodID computeMassPropertiesImplMethodId;
        jmethodID usePersistentContactManifoldImplMethodId;
};

class PxSimulationEventCallbackImpl : SimpleSimulationEventCallback {
    public:
        PxSimulationEventCallbackImpl(JNIEnv* env, jobject javaLocalRef) {
            javaGlobalRef = env->NewGlobalRef(javaLocalRef);
            jclass javaClass = env->GetObjectClass(javaLocalRef);
            onConstraintBreakMethodId = env->GetMethodID(javaClass, "_onConstraintBreak", "(JI)V");
            onWakeMethodId = env->GetMethodID(javaClass, "_onWake", "(JI)V");
            onSleepMethodId = env->GetMethodID(javaClass, "_onSleep", "(JI)V");
            onContactMethodId = env->GetMethodID(javaClass, "_onContact", "(JJI)V");
            onTriggerMethodId = env->GetMethodID(javaClass, "_onTrigger", "(JI)V");
        }
        
        ~PxSimulationEventCallbackImpl() {
            jniThreadEnv.getEnv()->DeleteGlobalRef(javaGlobalRef);
        }
        
        virtual void onConstraintBreak(physx::PxConstraintInfo* constraints, unsigned int count) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, onConstraintBreakMethodId, (jlong) constraints, (jint) count);
        }

        virtual void onWake(PxActorPtr* actors, unsigned int count) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, onWakeMethodId, (jlong) actors, (jint) count);
        }

        virtual void onSleep(PxActorPtr* actors, unsigned int count) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, onSleepMethodId, (jlong) actors, (jint) count);
        }

        virtual void onContact(const physx::PxContactPairHeader& pairHeader, const physx::PxContactPair* pairs, unsigned int nbPairs) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, onContactMethodId, (jlong) &pairHeader, (jlong) pairs, (jint) nbPairs);
        }

        virtual void onTrigger(physx::PxTriggerPair* pairs, unsigned int count) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, onTriggerMethodId, (jlong) pairs, (jint) count);
        }

    private:
        jobject javaGlobalRef;
        jmethodID onConstraintBreakMethodId;
        jmethodID onWakeMethodId;
        jmethodID onSleepMethodId;
        jmethodID onContactMethodId;
        jmethodID onTriggerMethodId;
};

class PxQueryFilterCallbackImpl : SimpleQueryFilterCallback {
    public:
        PxQueryFilterCallbackImpl(JNIEnv* env, jobject javaLocalRef) {
            javaGlobalRef = env->NewGlobalRef(javaLocalRef);
            jclass javaClass = env->GetObjectClass(javaLocalRef);
            simplePreFilterMethodId = env->GetMethodID(javaClass, "_simplePreFilter", "(JJJJ)I");
            simplePostFilterMethodId = env->GetMethodID(javaClass, "_simplePostFilter", "(JJ)I");
        }
        
        ~PxQueryFilterCallbackImpl() {
            jniThreadEnv.getEnv()->DeleteGlobalRef(javaGlobalRef);
        }
        
        virtual unsigned int simplePreFilter(const physx::PxFilterData& filterData, const physx::PxShape* shape, const physx::PxRigidActor* actor, physx::PxHitFlags& queryFlags) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            return _env->CallIntMethod(javaGlobalRef, simplePreFilterMethodId, (jlong) &filterData, (jlong) shape, (jlong) actor, (jlong) &queryFlags);
        }

        virtual unsigned int simplePostFilter(const physx::PxFilterData& filterData, const physx::PxQueryHit& hit) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            return _env->CallIntMethod(javaGlobalRef, simplePostFilterMethodId, (jlong) &filterData, (jlong) &hit);
        }

    private:
        jobject javaGlobalRef;
        jmethodID simplePreFilterMethodId;
        jmethodID simplePostFilterMethodId;
};

class PassThroughFilterShaderImpl : PassThroughFilterShader {
    public:
        PassThroughFilterShaderImpl(JNIEnv* env, jobject javaLocalRef) {
            javaGlobalRef = env->NewGlobalRef(javaLocalRef);
            jclass javaClass = env->GetObjectClass(javaLocalRef);
            filterShaderMethodId = env->GetMethodID(javaClass, "_filterShader", "(IIIIIIIIII)I");
        }
        
        ~PassThroughFilterShaderImpl() {
            jniThreadEnv.getEnv()->DeleteGlobalRef(javaGlobalRef);
        }
        
        virtual unsigned int filterShader(unsigned int attributes0, unsigned int filterData0w0, unsigned int filterData0w1, unsigned int filterData0w2, unsigned int filterData0w3, unsigned int attributes1, unsigned int filterData1w0, unsigned int filterData1w1, unsigned int filterData1w2, unsigned int filterData1w3) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            return _env->CallIntMethod(javaGlobalRef, filterShaderMethodId, (jint) attributes0, (jint) filterData0w0, (jint) filterData0w1, (jint) filterData0w2, (jint) filterData0w3, (jint) attributes1, (jint) filterData1w0, (jint) filterData1w1, (jint) filterData1w2, (jint) filterData1w3);
        }

    private:
        jobject javaGlobalRef;
        jmethodID filterShaderMethodId;
};

class SimplPvdTransportImpl : SimplePvdTransport {
    public:
        SimplPvdTransportImpl(JNIEnv* env, jobject javaLocalRef) {
            javaGlobalRef = env->NewGlobalRef(javaLocalRef);
            jclass javaClass = env->GetObjectClass(javaLocalRef);
            connectMethodId = env->GetMethodID(javaClass, "_connect", "()Z");
            isConnectedMethodId = env->GetMethodID(javaClass, "_isConnected", "()Z");
            disconnectMethodId = env->GetMethodID(javaClass, "_disconnect", "()V");
            sendMethodId = env->GetMethodID(javaClass, "_send", "(JI)V");
            flushMethodId = env->GetMethodID(javaClass, "_flush", "()V");
        }
        
        ~SimplPvdTransportImpl() {
            jniThreadEnv.getEnv()->DeleteGlobalRef(javaGlobalRef);
        }
        
        virtual bool connect() {
            JNIEnv* _env = jniThreadEnv.getEnv();
            return _env->CallBooleanMethod(javaGlobalRef, connectMethodId);
        }

        virtual bool isConnected() {
            JNIEnv* _env = jniThreadEnv.getEnv();
            return _env->CallBooleanMethod(javaGlobalRef, isConnectedMethodId);
        }

        virtual void disconnect() {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, disconnectMethodId);
        }

        virtual void send(void* inBytes, unsigned int inLength) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, sendMethodId, (jlong) inBytes, (jint) inLength);
        }

        virtual void flush() {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, flushMethodId);
        }

    private:
        jobject javaGlobalRef;
        jmethodID connectMethodId;
        jmethodID isConnectedMethodId;
        jmethodID disconnectMethodId;
        jmethodID sendMethodId;
        jmethodID flushMethodId;
};

extern "C" {
JNIEXPORT jint JNICALL Java_physx_NativeObject__1_1sizeOfPointer(JNIEnv*, jclass) {
    return sizeof(void*);
}

// JniThreadManager
JNIEXPORT jboolean JNICALL Java_physx_JniThreadManager__1init(JNIEnv* env, jclass) {
    return (jboolean) JniThreadManager::init(env);
}
JNIEXPORT void JNICALL Java_physx_JniThreadManager__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (JniThreadManager*) address;
}
// JavaNativeRef
JNIEXPORT jlong JNICALL Java_physx_JavaNativeRef__1new_1instance(JNIEnv* env, jclass, jobject javaRef) {
    return (jlong) new JavaNativeRef(env, javaRef);
}
JNIEXPORT void JNICALL Java_physx_JavaNativeRef__1delete_1instance(JNIEnv*, jclass, jlong address) {
    delete (JavaNativeRef*) address;
}
JNIEXPORT jobject JNICALL Java_physx_JavaNativeRef__1get_1java_1ref(JNIEnv*, jclass, jlong address) {
    return ((JavaNativeRef*) address)->javaGlobalRef;
}

// PxTopLevelFunctions
JNIEXPORT jint JNICALL Java_physx_PxTopLevelFunctions__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxTopLevelFunctions);
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1DefaultFilterShader(JNIEnv*, jclass) {
    static thread_local physx::PxSimulationFilterShader _cache = PxTopLevelFunctions::DefaultFilterShader();
    _cache = PxTopLevelFunctions::DefaultFilterShader();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_PxTopLevelFunctions__1setupPassThroughFilterShader(JNIEnv*, jclass, jlong sceneDesc, jlong filterShader) {
    PxTopLevelFunctions::setupPassThroughFilterShader((physx::PxSceneDesc*) sceneDesc, (PassThroughFilterShader*) filterShader);
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1CreateControllerManager__J(JNIEnv*, jclass, jlong scene) {
    return (jlong) PxTopLevelFunctions::CreateControllerManager(*((physx::PxScene*) scene));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1CreateControllerManager__JZ(JNIEnv*, jclass, jlong scene, jboolean lockingEnabled) {
    return (jlong) PxTopLevelFunctions::CreateControllerManager(*((physx::PxScene*) scene), lockingEnabled);
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1CreateFoundation(JNIEnv*, jclass, jint version, jlong allocator, jlong errorCallback) {
    return (jlong) PxTopLevelFunctions::CreateFoundation(version, *((physx::PxDefaultAllocator*) allocator), *((physx::PxErrorCallback*) errorCallback));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1CreatePhysics__IJJ(JNIEnv*, jclass, jint version, jlong foundation, jlong params) {
    return (jlong) PxTopLevelFunctions::CreatePhysics(version, *((physx::PxFoundation*) foundation), *((physx::PxTolerancesScale*) params));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1CreatePhysics__IJJJ(JNIEnv*, jclass, jint version, jlong foundation, jlong params, jlong pvd) {
    return (jlong) PxTopLevelFunctions::CreatePhysics(version, *((physx::PxFoundation*) foundation), *((physx::PxTolerancesScale*) params), (physx::PxPvd*) pvd);
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1CreatePhysics__IJJJJ(JNIEnv*, jclass, jint version, jlong foundation, jlong params, jlong pvd, jlong omniPvd) {
    return (jlong) PxTopLevelFunctions::CreatePhysics(version, *((physx::PxFoundation*) foundation), *((physx::PxTolerancesScale*) params), (physx::PxPvd*) pvd, (physx::PxOmniPvd*) omniPvd);
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1DefaultCpuDispatcherCreate(JNIEnv*, jclass, jint numThreads) {
    return (jlong) PxTopLevelFunctions::DefaultCpuDispatcherCreate(numThreads);
}
JNIEXPORT jboolean JNICALL Java_physx_PxTopLevelFunctions__1InitExtensions(JNIEnv*, jclass, jlong physics) {
    return (jboolean) PxTopLevelFunctions::InitExtensions(*((physx::PxPhysics*) physics));
}
JNIEXPORT void JNICALL Java_physx_PxTopLevelFunctions__1CloseExtensions(JNIEnv*, jclass) {
    PxTopLevelFunctions::CloseExtensions();
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1CreatePvd(JNIEnv*, jclass, jlong foundation) {
    return (jlong) PxTopLevelFunctions::CreatePvd(*((physx::PxFoundation*) foundation));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1DefaultPvdSocketTransportCreate(JNIEnv* _env, jclass, jstring host, jint port, jint timeoutInMilliseconds) {
    return (jlong) PxTopLevelFunctions::DefaultPvdSocketTransportCreate(_env->GetStringUTFChars(host, 0), port, timeoutInMilliseconds);
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1CreateOmniPvd(JNIEnv*, jclass, jlong foundation) {
    return (jlong) PxTopLevelFunctions::CreateOmniPvd(*((physx::PxFoundation*) foundation));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1D6JointCreate(JNIEnv*, jclass, jlong physics, jlong actor0, jlong localFrame0, jlong actor1, jlong localFrame1) {
    return (jlong) PxTopLevelFunctions::D6JointCreate(*((physx::PxPhysics*) physics), (physx::PxRigidActor*) actor0, *((physx::PxTransform*) localFrame0), (physx::PxRigidActor*) actor1, *((physx::PxTransform*) localFrame1));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1DistanceJointCreate(JNIEnv*, jclass, jlong physics, jlong actor0, jlong localFrame0, jlong actor1, jlong localFrame1) {
    return (jlong) PxTopLevelFunctions::DistanceJointCreate(*((physx::PxPhysics*) physics), (physx::PxRigidActor*) actor0, *((physx::PxTransform*) localFrame0), (physx::PxRigidActor*) actor1, *((physx::PxTransform*) localFrame1));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1FixedJointCreate(JNIEnv*, jclass, jlong physics, jlong actor0, jlong localFrame0, jlong actor1, jlong localFrame1) {
    return (jlong) PxTopLevelFunctions::FixedJointCreate(*((physx::PxPhysics*) physics), (physx::PxRigidActor*) actor0, *((physx::PxTransform*) localFrame0), (physx::PxRigidActor*) actor1, *((physx::PxTransform*) localFrame1));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1PrismaticJointCreate(JNIEnv*, jclass, jlong physics, jlong actor0, jlong localFrame0, jlong actor1, jlong localFrame1) {
    return (jlong) PxTopLevelFunctions::PrismaticJointCreate(*((physx::PxPhysics*) physics), (physx::PxRigidActor*) actor0, *((physx::PxTransform*) localFrame0), (physx::PxRigidActor*) actor1, *((physx::PxTransform*) localFrame1));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1RevoluteJointCreate(JNIEnv*, jclass, jlong physics, jlong actor0, jlong localFrame0, jlong actor1, jlong localFrame1) {
    return (jlong) PxTopLevelFunctions::RevoluteJointCreate(*((physx::PxPhysics*) physics), (physx::PxRigidActor*) actor0, *((physx::PxTransform*) localFrame0), (physx::PxRigidActor*) actor1, *((physx::PxTransform*) localFrame1));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1SphericalJointCreate(JNIEnv*, jclass, jlong physics, jlong actor0, jlong localFrame0, jlong actor1, jlong localFrame1) {
    return (jlong) PxTopLevelFunctions::SphericalJointCreate(*((physx::PxPhysics*) physics), (physx::PxRigidActor*) actor0, *((physx::PxTransform*) localFrame0), (physx::PxRigidActor*) actor1, *((physx::PxTransform*) localFrame1));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1CreateConvexMesh(JNIEnv*, jclass, jlong params, jlong desc) {
    return (jlong) PxTopLevelFunctions::CreateConvexMesh(*((physx::PxCookingParams*) params), *((physx::PxConvexMeshDesc*) desc));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1CreateTriangleMesh(JNIEnv*, jclass, jlong params, jlong desc) {
    return (jlong) PxTopLevelFunctions::CreateTriangleMesh(*((physx::PxCookingParams*) params), *((physx::PxTriangleMeshDesc*) desc));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1CreateHeightField(JNIEnv*, jclass, jlong desc) {
    return (jlong) PxTopLevelFunctions::CreateHeightField(*((physx::PxHeightFieldDesc*) desc));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1CreateCooking(JNIEnv*, jclass, jint version, jlong foundation, jlong scale) {
    return (jlong) PxTopLevelFunctions::CreateCooking(version, *((physx::PxFoundation*) foundation), *((physx::PxCookingParams*) scale));
}
JNIEXPORT jint JNICALL Java_physx_PxTopLevelFunctions__1getPHYSICS_1VERSION(JNIEnv*, jclass) {
    return (jint) PxTopLevelFunctions::PHYSICS_VERSION;
}

// PxBoxController
JNIEXPORT jint JNICALL Java_physx_character_PxBoxController__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxBoxController);
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxBoxController__1getHalfHeight(JNIEnv*, jclass, jlong _address) {
    physx::PxBoxController* self = (physx::PxBoxController*) _address;
    return (jfloat) self->getHalfHeight();
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxBoxController__1getHalfSideExtent(JNIEnv*, jclass, jlong _address) {
    physx::PxBoxController* self = (physx::PxBoxController*) _address;
    return (jfloat) self->getHalfSideExtent();
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxBoxController__1getHalfForwardExtent(JNIEnv*, jclass, jlong _address) {
    physx::PxBoxController* self = (physx::PxBoxController*) _address;
    return (jfloat) self->getHalfForwardExtent();
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxBoxController__1setHalfHeight(JNIEnv*, jclass, jlong _address, jfloat halfHeight) {
    physx::PxBoxController* self = (physx::PxBoxController*) _address;
    return (jboolean) self->setHalfHeight(halfHeight);
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxBoxController__1setHalfSideExtent(JNIEnv*, jclass, jlong _address, jfloat halfSideExtent) {
    physx::PxBoxController* self = (physx::PxBoxController*) _address;
    return (jboolean) self->setHalfSideExtent(halfSideExtent);
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxBoxController__1setHalfForwardExtent(JNIEnv*, jclass, jlong _address, jfloat halfForwardExtent) {
    physx::PxBoxController* self = (physx::PxBoxController*) _address;
    return (jboolean) self->setHalfForwardExtent(halfForwardExtent);
}

// PxBoxControllerDesc
JNIEXPORT jint JNICALL Java_physx_character_PxBoxControllerDesc__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxBoxControllerDesc);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxBoxControllerDesc__1_1placement_1new_1PxBoxControllerDesc(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxBoxControllerDesc();
}
JNIEXPORT jlong JNICALL Java_physx_character_PxBoxControllerDesc__1PxBoxControllerDesc(JNIEnv*, jclass) {
    return (jlong) new physx::PxBoxControllerDesc();
}
JNIEXPORT void JNICALL Java_physx_character_PxBoxControllerDesc__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::PxBoxControllerDesc* self = (physx::PxBoxControllerDesc*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_character_PxBoxControllerDesc__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBoxControllerDesc*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxBoxControllerDesc__1getHalfHeight(JNIEnv*, jclass, jlong _address) {
    physx::PxBoxControllerDesc* _self = (physx::PxBoxControllerDesc*) _address;
    return (jfloat) _self->halfHeight;
}
JNIEXPORT void JNICALL Java_physx_character_PxBoxControllerDesc__1setHalfHeight(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxBoxControllerDesc* _self = (physx::PxBoxControllerDesc*) _address;
    _self->halfHeight = value;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxBoxControllerDesc__1getHalfSideExtent(JNIEnv*, jclass, jlong _address) {
    physx::PxBoxControllerDesc* _self = (physx::PxBoxControllerDesc*) _address;
    return (jfloat) _self->halfSideExtent;
}
JNIEXPORT void JNICALL Java_physx_character_PxBoxControllerDesc__1setHalfSideExtent(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxBoxControllerDesc* _self = (physx::PxBoxControllerDesc*) _address;
    _self->halfSideExtent = value;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxBoxControllerDesc__1getHalfForwardExtent(JNIEnv*, jclass, jlong _address) {
    physx::PxBoxControllerDesc* _self = (physx::PxBoxControllerDesc*) _address;
    return (jfloat) _self->halfForwardExtent;
}
JNIEXPORT void JNICALL Java_physx_character_PxBoxControllerDesc__1setHalfForwardExtent(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxBoxControllerDesc* _self = (physx::PxBoxControllerDesc*) _address;
    _self->halfForwardExtent = value;
}

// PxBoxObstacle
JNIEXPORT jint JNICALL Java_physx_character_PxBoxObstacle__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxBoxObstacle);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxBoxObstacle__1PxBoxObstacle(JNIEnv*, jclass) {
    return (jlong) new physx::PxBoxObstacle();
}
JNIEXPORT void JNICALL Java_physx_character_PxBoxObstacle__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBoxObstacle*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxBoxObstacle__1getMHalfExtents(JNIEnv*, jclass, jlong _address) {
    physx::PxBoxObstacle* _self = (physx::PxBoxObstacle*) _address;
    return (jlong) &_self->mHalfExtents;
}
JNIEXPORT void JNICALL Java_physx_character_PxBoxObstacle__1setMHalfExtents(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxBoxObstacle* _self = (physx::PxBoxObstacle*) _address;
    _self->mHalfExtents = *((physx::PxVec3*) value);
}

// PxCapsuleController
JNIEXPORT jint JNICALL Java_physx_character_PxCapsuleController__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxCapsuleController);
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxCapsuleController__1getRadius(JNIEnv*, jclass, jlong _address) {
    physx::PxCapsuleController* self = (physx::PxCapsuleController*) _address;
    return (jfloat) self->getRadius();
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxCapsuleController__1setRadius(JNIEnv*, jclass, jlong _address, jfloat radius) {
    physx::PxCapsuleController* self = (physx::PxCapsuleController*) _address;
    return (jboolean) self->setRadius(radius);
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxCapsuleController__1getHeight(JNIEnv*, jclass, jlong _address) {
    physx::PxCapsuleController* self = (physx::PxCapsuleController*) _address;
    return (jfloat) self->getHeight();
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxCapsuleController__1setHeight(JNIEnv*, jclass, jlong _address, jfloat height) {
    physx::PxCapsuleController* self = (physx::PxCapsuleController*) _address;
    return (jboolean) self->setHeight(height);
}
JNIEXPORT jint JNICALL Java_physx_character_PxCapsuleController__1getClimbingMode(JNIEnv*, jclass, jlong _address) {
    physx::PxCapsuleController* self = (physx::PxCapsuleController*) _address;
    return (jint) self->getClimbingMode();
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxCapsuleController__1setClimbingMode(JNIEnv*, jclass, jlong _address, jint mode) {
    physx::PxCapsuleController* self = (physx::PxCapsuleController*) _address;
    return (jboolean) self->setClimbingMode((PxCapsuleClimbingModeEnum) mode);
}

// PxCapsuleControllerDesc
JNIEXPORT jint JNICALL Java_physx_character_PxCapsuleControllerDesc__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxCapsuleControllerDesc);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxCapsuleControllerDesc__1_1placement_1new_1PxCapsuleControllerDesc(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxCapsuleControllerDesc();
}
JNIEXPORT jlong JNICALL Java_physx_character_PxCapsuleControllerDesc__1PxCapsuleControllerDesc(JNIEnv*, jclass) {
    return (jlong) new physx::PxCapsuleControllerDesc();
}
JNIEXPORT void JNICALL Java_physx_character_PxCapsuleControllerDesc__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::PxCapsuleControllerDesc* self = (physx::PxCapsuleControllerDesc*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_character_PxCapsuleControllerDesc__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxCapsuleControllerDesc*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxCapsuleControllerDesc__1getRadius(JNIEnv*, jclass, jlong _address) {
    physx::PxCapsuleControllerDesc* _self = (physx::PxCapsuleControllerDesc*) _address;
    return (jfloat) _self->radius;
}
JNIEXPORT void JNICALL Java_physx_character_PxCapsuleControllerDesc__1setRadius(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxCapsuleControllerDesc* _self = (physx::PxCapsuleControllerDesc*) _address;
    _self->radius = value;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxCapsuleControllerDesc__1getHeight(JNIEnv*, jclass, jlong _address) {
    physx::PxCapsuleControllerDesc* _self = (physx::PxCapsuleControllerDesc*) _address;
    return (jfloat) _self->height;
}
JNIEXPORT void JNICALL Java_physx_character_PxCapsuleControllerDesc__1setHeight(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxCapsuleControllerDesc* _self = (physx::PxCapsuleControllerDesc*) _address;
    _self->height = value;
}
JNIEXPORT jint JNICALL Java_physx_character_PxCapsuleControllerDesc__1getClimbingMode(JNIEnv*, jclass, jlong _address) {
    physx::PxCapsuleControllerDesc* _self = (physx::PxCapsuleControllerDesc*) _address;
    return (jint) _self->climbingMode;
}
JNIEXPORT void JNICALL Java_physx_character_PxCapsuleControllerDesc__1setClimbingMode(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxCapsuleControllerDesc* _self = (physx::PxCapsuleControllerDesc*) _address;
    _self->climbingMode = (PxCapsuleClimbingModeEnum) value;
}

// PxCapsuleObstacle
JNIEXPORT jint JNICALL Java_physx_character_PxCapsuleObstacle__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxCapsuleObstacle);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxCapsuleObstacle__1PxCapsuleObstacle(JNIEnv*, jclass) {
    return (jlong) new physx::PxCapsuleObstacle();
}
JNIEXPORT void JNICALL Java_physx_character_PxCapsuleObstacle__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxCapsuleObstacle*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxCapsuleObstacle__1getMHalfHeight(JNIEnv*, jclass, jlong _address) {
    physx::PxCapsuleObstacle* _self = (physx::PxCapsuleObstacle*) _address;
    return (jfloat) _self->mHalfHeight;
}
JNIEXPORT void JNICALL Java_physx_character_PxCapsuleObstacle__1setMHalfHeight(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxCapsuleObstacle* _self = (physx::PxCapsuleObstacle*) _address;
    _self->mHalfHeight = value;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxCapsuleObstacle__1getMRadius(JNIEnv*, jclass, jlong _address) {
    physx::PxCapsuleObstacle* _self = (physx::PxCapsuleObstacle*) _address;
    return (jfloat) _self->mRadius;
}
JNIEXPORT void JNICALL Java_physx_character_PxCapsuleObstacle__1setMRadius(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxCapsuleObstacle* _self = (physx::PxCapsuleObstacle*) _address;
    _self->mRadius = value;
}

// PxController
JNIEXPORT jint JNICALL Java_physx_character_PxController__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxController);
}
JNIEXPORT jint JNICALL Java_physx_character_PxController__1getType(JNIEnv*, jclass, jlong _address) {
    physx::PxController* self = (physx::PxController*) _address;
    return (jint) self->getType();
}
JNIEXPORT void JNICALL Java_physx_character_PxController__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxController* self = (physx::PxController*) _address;
    self->release();
}
JNIEXPORT jlong JNICALL Java_physx_character_PxController__1move__JJFFJ(JNIEnv*, jclass, jlong _address, jlong disp, jfloat minDist, jfloat elapsedTime, jlong filters) {
    physx::PxController* self = (physx::PxController*) _address;
    static thread_local physx::PxControllerCollisionFlags _cache = self->move(*((physx::PxVec3*) disp), minDist, elapsedTime, *((physx::PxControllerFilters*) filters));
    _cache = self->move(*((physx::PxVec3*) disp), minDist, elapsedTime, *((physx::PxControllerFilters*) filters));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxController__1move__JJFFJJ(JNIEnv*, jclass, jlong _address, jlong disp, jfloat minDist, jfloat elapsedTime, jlong filters, jlong obstacles) {
    physx::PxController* self = (physx::PxController*) _address;
    static thread_local physx::PxControllerCollisionFlags _cache = self->move(*((physx::PxVec3*) disp), minDist, elapsedTime, *((physx::PxControllerFilters*) filters), (physx::PxObstacleContext*) obstacles);
    _cache = self->move(*((physx::PxVec3*) disp), minDist, elapsedTime, *((physx::PxControllerFilters*) filters), (physx::PxObstacleContext*) obstacles);
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxController__1setPosition(JNIEnv*, jclass, jlong _address, jlong position) {
    physx::PxController* self = (physx::PxController*) _address;
    return (jboolean) self->setPosition(*((physx::PxExtendedVec3*) position));
}
JNIEXPORT jlong JNICALL Java_physx_character_PxController__1getPosition(JNIEnv*, jclass, jlong _address) {
    physx::PxController* self = (physx::PxController*) _address;
    return (jlong) &self->getPosition();
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxController__1setFootPosition(JNIEnv*, jclass, jlong _address, jlong position) {
    physx::PxController* self = (physx::PxController*) _address;
    return (jboolean) self->setFootPosition(*((physx::PxExtendedVec3*) position));
}
JNIEXPORT jlong JNICALL Java_physx_character_PxController__1getFootPosition(JNIEnv*, jclass, jlong _address) {
    physx::PxController* self = (physx::PxController*) _address;
    static thread_local physx::PxExtendedVec3 _cache = self->getFootPosition();
    _cache = self->getFootPosition();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxController__1getActor(JNIEnv*, jclass, jlong _address) {
    physx::PxController* self = (physx::PxController*) _address;
    return (jlong) self->getActor();
}
JNIEXPORT void JNICALL Java_physx_character_PxController__1setStepOffset(JNIEnv*, jclass, jlong _address, jfloat offset) {
    physx::PxController* self = (physx::PxController*) _address;
    self->setStepOffset(offset);
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxController__1getStepOffset(JNIEnv*, jclass, jlong _address) {
    physx::PxController* self = (physx::PxController*) _address;
    return (jfloat) self->getStepOffset();
}
JNIEXPORT void JNICALL Java_physx_character_PxController__1setNonWalkableMode(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxController* self = (physx::PxController*) _address;
    self->setNonWalkableMode((PxControllerNonWalkableModeEnum) flag);
}
JNIEXPORT jint JNICALL Java_physx_character_PxController__1getNonWalkableMode(JNIEnv*, jclass, jlong _address) {
    physx::PxController* self = (physx::PxController*) _address;
    return (jint) self->getNonWalkableMode();
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxController__1getContactOffset(JNIEnv*, jclass, jlong _address) {
    physx::PxController* self = (physx::PxController*) _address;
    return (jfloat) self->getContactOffset();
}
JNIEXPORT void JNICALL Java_physx_character_PxController__1setContactOffset(JNIEnv*, jclass, jlong _address, jfloat offset) {
    physx::PxController* self = (physx::PxController*) _address;
    self->setContactOffset(offset);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxController__1getUpDirection(JNIEnv*, jclass, jlong _address) {
    physx::PxController* self = (physx::PxController*) _address;
    static thread_local physx::PxVec3 _cache = self->getUpDirection();
    _cache = self->getUpDirection();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_character_PxController__1setUpDirection(JNIEnv*, jclass, jlong _address, jlong up) {
    physx::PxController* self = (physx::PxController*) _address;
    self->setUpDirection(*((physx::PxVec3*) up));
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxController__1getSlopeLimit(JNIEnv*, jclass, jlong _address) {
    physx::PxController* self = (physx::PxController*) _address;
    return (jfloat) self->getSlopeLimit();
}
JNIEXPORT void JNICALL Java_physx_character_PxController__1setSlopeLimit(JNIEnv*, jclass, jlong _address, jfloat slopeLimit) {
    physx::PxController* self = (physx::PxController*) _address;
    self->setSlopeLimit(slopeLimit);
}
JNIEXPORT void JNICALL Java_physx_character_PxController__1invalidateCache(JNIEnv*, jclass, jlong _address) {
    physx::PxController* self = (physx::PxController*) _address;
    self->invalidateCache();
}
JNIEXPORT jlong JNICALL Java_physx_character_PxController__1getScene(JNIEnv*, jclass, jlong _address) {
    physx::PxController* self = (physx::PxController*) _address;
    return (jlong) self->getScene();
}
JNIEXPORT jlong JNICALL Java_physx_character_PxController__1getUserData(JNIEnv*, jclass, jlong _address) {
    physx::PxController* self = (physx::PxController*) _address;
    return (jlong) self->getUserData();
}
JNIEXPORT void JNICALL Java_physx_character_PxController__1setUserData(JNIEnv*, jclass, jlong _address, jlong userData) {
    physx::PxController* self = (physx::PxController*) _address;
    self->setUserData((void*) userData);
}
JNIEXPORT void JNICALL Java_physx_character_PxController__1getState(JNIEnv*, jclass, jlong _address, jlong state) {
    physx::PxController* self = (physx::PxController*) _address;
    self->getState(*((physx::PxControllerState*) state));
}
JNIEXPORT void JNICALL Java_physx_character_PxController__1getStats(JNIEnv*, jclass, jlong _address, jlong stats) {
    physx::PxController* self = (physx::PxController*) _address;
    self->getStats(*((physx::PxControllerStats*) stats));
}
JNIEXPORT void JNICALL Java_physx_character_PxController__1resize(JNIEnv*, jclass, jlong _address, jfloat height) {
    physx::PxController* self = (physx::PxController*) _address;
    self->resize(height);
}

// PxControllerBehaviorCallback
JNIEXPORT jint JNICALL Java_physx_character_PxControllerBehaviorCallback__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxControllerBehaviorCallback);
}

// SimpleControllerBehaviorCallback
JNIEXPORT jint JNICALL Java_physx_character_SimpleControllerBehaviorCallback__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(SimpleControllerBehaviorCallback);
}
JNIEXPORT jint JNICALL Java_physx_character_SimpleControllerBehaviorCallback__1getShapeBehaviorFlags(JNIEnv*, jclass, jlong _address, jlong shape, jlong actor) {
    SimpleControllerBehaviorCallback* self = (SimpleControllerBehaviorCallback*) _address;
    return (jint) self->getShapeBehaviorFlags(*((physx::PxShape*) shape), *((physx::PxActor*) actor));
}
JNIEXPORT jint JNICALL Java_physx_character_SimpleControllerBehaviorCallback__1getControllerBehaviorFlags(JNIEnv*, jclass, jlong _address, jlong controller) {
    SimpleControllerBehaviorCallback* self = (SimpleControllerBehaviorCallback*) _address;
    return (jint) self->getControllerBehaviorFlags(*((physx::PxController*) controller));
}
JNIEXPORT jint JNICALL Java_physx_character_SimpleControllerBehaviorCallback__1getObstacleBehaviorFlags(JNIEnv*, jclass, jlong _address, jlong obstacle) {
    SimpleControllerBehaviorCallback* self = (SimpleControllerBehaviorCallback*) _address;
    return (jint) self->getObstacleBehaviorFlags(*((physx::PxObstacle*) obstacle));
}
JNIEXPORT void JNICALL Java_physx_character_SimpleControllerBehaviorCallback__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (SimpleControllerBehaviorCallback*) _address;
}

// PxControllerBehaviorCallbackImpl
JNIEXPORT jint JNICALL Java_physx_character_PxControllerBehaviorCallbackImpl__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxControllerBehaviorCallbackImpl);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerBehaviorCallbackImpl__1PxControllerBehaviorCallbackImpl(JNIEnv* env, jobject obj) {
    return (jlong) new PxControllerBehaviorCallbackImpl(env, obj);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerBehaviorCallbackImpl__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (PxControllerBehaviorCallbackImpl*) address;
}

// PxControllerBehaviorFlags
JNIEXPORT jint JNICALL Java_physx_character_PxControllerBehaviorFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxControllerBehaviorFlags);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerBehaviorFlags__1_1placement_1new_1PxControllerBehaviorFlags(JNIEnv*, jclass, jlong _placement_address, jbyte flags) {
    return (jlong) new((void*)_placement_address) physx::PxControllerBehaviorFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerBehaviorFlags__1PxControllerBehaviorFlags(JNIEnv*, jclass, jbyte flags) {
    return (jlong) new physx::PxControllerBehaviorFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxControllerBehaviorFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxControllerBehaviorFlags* self = (physx::PxControllerBehaviorFlags*) _address;
    return (jboolean) self->isSet((PxControllerBehaviorFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerBehaviorFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxControllerBehaviorFlags* self = (physx::PxControllerBehaviorFlags*) _address;
    self->raise((PxControllerBehaviorFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerBehaviorFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxControllerBehaviorFlags* self = (physx::PxControllerBehaviorFlags*) _address;
    self->clear((PxControllerBehaviorFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerBehaviorFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxControllerBehaviorFlags*) _address;
}

// PxControllerCollisionFlags
JNIEXPORT jint JNICALL Java_physx_character_PxControllerCollisionFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxControllerCollisionFlags);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerCollisionFlags__1_1placement_1new_1PxControllerCollisionFlags(JNIEnv*, jclass, jlong _placement_address, jbyte flags) {
    return (jlong) new((void*)_placement_address) physx::PxControllerCollisionFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerCollisionFlags__1PxControllerCollisionFlags(JNIEnv*, jclass, jbyte flags) {
    return (jlong) new physx::PxControllerCollisionFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxControllerCollisionFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxControllerCollisionFlags* self = (physx::PxControllerCollisionFlags*) _address;
    return (jboolean) self->isSet((PxControllerCollisionFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerCollisionFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxControllerCollisionFlags* self = (physx::PxControllerCollisionFlags*) _address;
    self->raise((PxControllerCollisionFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerCollisionFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxControllerCollisionFlags* self = (physx::PxControllerCollisionFlags*) _address;
    self->clear((PxControllerCollisionFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerCollisionFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxControllerCollisionFlags*) _address;
}

// PxControllerDesc
JNIEXPORT jint JNICALL Java_physx_character_PxControllerDesc__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxControllerDesc);
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxControllerDesc__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* self = (physx::PxControllerDesc*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT jint JNICALL Java_physx_character_PxControllerDesc__1getType(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* self = (physx::PxControllerDesc*) _address;
    return (jint) self->getType();
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerDesc__1getPosition(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jlong) &_self->position;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setPosition(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->position = *((physx::PxExtendedVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerDesc__1getUpDirection(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jlong) &_self->upDirection;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setUpDirection(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->upDirection = *((physx::PxVec3*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxControllerDesc__1getSlopeLimit(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jfloat) _self->slopeLimit;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setSlopeLimit(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->slopeLimit = value;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxControllerDesc__1getInvisibleWallHeight(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jfloat) _self->invisibleWallHeight;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setInvisibleWallHeight(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->invisibleWallHeight = value;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxControllerDesc__1getMaxJumpHeight(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jfloat) _self->maxJumpHeight;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setMaxJumpHeight(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->maxJumpHeight = value;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxControllerDesc__1getContactOffset(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jfloat) _self->contactOffset;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setContactOffset(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->contactOffset = value;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxControllerDesc__1getStepOffset(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jfloat) _self->stepOffset;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setStepOffset(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->stepOffset = value;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxControllerDesc__1getDensity(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jfloat) _self->density;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setDensity(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->density = value;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxControllerDesc__1getScaleCoeff(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jfloat) _self->scaleCoeff;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setScaleCoeff(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->scaleCoeff = value;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxControllerDesc__1getVolumeGrowth(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jfloat) _self->volumeGrowth;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setVolumeGrowth(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->volumeGrowth = value;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerDesc__1getReportCallback(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jlong) _self->reportCallback;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setReportCallback(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->reportCallback = (physx::PxUserControllerHitReport*) value;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerDesc__1getBehaviorCallback(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jlong) _self->behaviorCallback;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setBehaviorCallback(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->behaviorCallback = (physx::PxControllerBehaviorCallback*) value;
}
JNIEXPORT jint JNICALL Java_physx_character_PxControllerDesc__1getNonWalkableMode(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jint) _self->nonWalkableMode;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setNonWalkableMode(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->nonWalkableMode = (PxControllerNonWalkableModeEnum) value;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerDesc__1getMaterial(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jlong) _self->material;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setMaterial(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->material = (physx::PxMaterial*) value;
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxControllerDesc__1getRegisterDeletionListener(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jboolean) _self->registerDeletionListener;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setRegisterDeletionListener(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->registerDeletionListener = value;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerDesc__1getUserData(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->userData = (void*) value;
}

// PxControllerFilters
JNIEXPORT jint JNICALL Java_physx_character_PxControllerFilters__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxControllerFilters);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerFilters__1PxControllerFilters__(JNIEnv*, jclass) {
    return (jlong) new physx::PxControllerFilters();
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerFilters__1PxControllerFilters__J(JNIEnv*, jclass, jlong filterData) {
    return (jlong) new physx::PxControllerFilters((physx::PxFilterData*) filterData);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerFilters__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxControllerFilters*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerFilters__1getMFilterData(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerFilters* _self = (physx::PxControllerFilters*) _address;
    return (jlong) _self->mFilterData;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerFilters__1setMFilterData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerFilters* _self = (physx::PxControllerFilters*) _address;
    _self->mFilterData = (physx::PxFilterData*) value;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerFilters__1getMFilterCallback(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerFilters* _self = (physx::PxControllerFilters*) _address;
    return (jlong) _self->mFilterCallback;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerFilters__1setMFilterCallback(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerFilters* _self = (physx::PxControllerFilters*) _address;
    _self->mFilterCallback = (physx::PxQueryFilterCallback*) value;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerFilters__1getMFilterFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerFilters* _self = (physx::PxControllerFilters*) _address;
    return (jlong) &_self->mFilterFlags;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerFilters__1setMFilterFlags(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerFilters* _self = (physx::PxControllerFilters*) _address;
    _self->mFilterFlags = *((physx::PxQueryFlags*) value);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerFilters__1getMCCTFilterCallback(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerFilters* _self = (physx::PxControllerFilters*) _address;
    return (jlong) _self->mCCTFilterCallback;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerFilters__1setMCCTFilterCallback(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerFilters* _self = (physx::PxControllerFilters*) _address;
    _self->mCCTFilterCallback = (physx::PxControllerFilterCallback*) value;
}

// PxControllerFilterCallback
JNIEXPORT jint JNICALL Java_physx_character_PxControllerFilterCallback__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxControllerFilterCallback);
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxControllerFilterCallback__1filter(JNIEnv*, jclass, jlong _address, jlong a, jlong b) {
    physx::PxControllerFilterCallback* self = (physx::PxControllerFilterCallback*) _address;
    return (jboolean) self->filter(*((physx::PxController*) a), *((physx::PxController*) b));
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerFilterCallback__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxControllerFilterCallback*) _address;
}

// PxControllerFilterCallbackImpl
JNIEXPORT jint JNICALL Java_physx_character_PxControllerFilterCallbackImpl__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxControllerFilterCallbackImpl);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerFilterCallbackImpl__1PxControllerFilterCallbackImpl(JNIEnv* env, jobject obj) {
    return (jlong) new PxControllerFilterCallbackImpl(env, obj);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerFilterCallbackImpl__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (PxControllerFilterCallbackImpl*) address;
}

// PxControllerHit
JNIEXPORT jint JNICALL Java_physx_character_PxControllerHit__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxControllerHit);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerHit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxControllerHit*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerHit__1getController(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerHit* _self = (physx::PxControllerHit*) _address;
    return (jlong) _self->controller;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerHit__1setController(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerHit* _self = (physx::PxControllerHit*) _address;
    _self->controller = (physx::PxController*) value;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerHit__1getWorldPos(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerHit* _self = (physx::PxControllerHit*) _address;
    return (jlong) &_self->worldPos;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerHit__1setWorldPos(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerHit* _self = (physx::PxControllerHit*) _address;
    _self->worldPos = *((physx::PxExtendedVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerHit__1getWorldNormal(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerHit* _self = (physx::PxControllerHit*) _address;
    return (jlong) &_self->worldNormal;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerHit__1setWorldNormal(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerHit* _self = (physx::PxControllerHit*) _address;
    _self->worldNormal = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerHit__1getDir(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerHit* _self = (physx::PxControllerHit*) _address;
    return (jlong) &_self->dir;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerHit__1setDir(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerHit* _self = (physx::PxControllerHit*) _address;
    _self->dir = *((physx::PxVec3*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxControllerHit__1getLength(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerHit* _self = (physx::PxControllerHit*) _address;
    return (jfloat) _self->length;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerHit__1setLength(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxControllerHit* _self = (physx::PxControllerHit*) _address;
    _self->length = value;
}

// PxControllerManager
JNIEXPORT jint JNICALL Java_physx_character_PxControllerManager__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxControllerManager);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerManager__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    self->release();
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerManager__1getScene(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    return (jlong) &self->getScene();
}
JNIEXPORT jint JNICALL Java_physx_character_PxControllerManager__1getNbControllers(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    return (jint) self->getNbControllers();
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerManager__1getController(JNIEnv*, jclass, jlong _address, jint index) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    return (jlong) self->getController(index);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerManager__1createController(JNIEnv*, jclass, jlong _address, jlong desc) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    return (jlong) self->createController(*((physx::PxControllerDesc*) desc));
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerManager__1purgeControllers(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    self->purgeControllers();
}
JNIEXPORT jint JNICALL Java_physx_character_PxControllerManager__1getNbObstacleContexts(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    return (jint) self->getNbObstacleContexts();
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerManager__1getObstacleContext(JNIEnv*, jclass, jlong _address, jint index) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    return (jlong) self->getObstacleContext(index);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerManager__1createObstacleContext(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    return (jlong) self->createObstacleContext();
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerManager__1computeInteractions(JNIEnv*, jclass, jlong _address, jfloat elapsedTime) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    self->computeInteractions(elapsedTime);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerManager__1setTessellation(JNIEnv*, jclass, jlong _address, jboolean flag, jfloat maxEdgeLength) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    self->setTessellation(flag, maxEdgeLength);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerManager__1setOverlapRecoveryModule(JNIEnv*, jclass, jlong _address, jboolean flag) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    self->setOverlapRecoveryModule(flag);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerManager__1setPreciseSweeps(JNIEnv*, jclass, jlong _address, jboolean flags) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    self->setPreciseSweeps(flags);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerManager__1setPreventVerticalSlidingAgainstCeiling(JNIEnv*, jclass, jlong _address, jboolean flag) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    self->setPreventVerticalSlidingAgainstCeiling(flag);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerManager__1shiftOrigin(JNIEnv*, jclass, jlong _address, jlong shift) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    self->shiftOrigin(*((physx::PxVec3*) shift));
}

// PxControllerObstacleHit
JNIEXPORT jint JNICALL Java_physx_character_PxControllerObstacleHit__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxControllerObstacleHit);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerObstacleHit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxControllerObstacleHit*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerObstacleHit__1getUserData(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerObstacleHit* _self = (physx::PxControllerObstacleHit*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerObstacleHit__1setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerObstacleHit* _self = (physx::PxControllerObstacleHit*) _address;
    _self->userData = (void*) value;
}

// PxControllerShapeHit
JNIEXPORT jint JNICALL Java_physx_character_PxControllerShapeHit__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxControllerShapeHit);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerShapeHit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxControllerShapeHit*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerShapeHit__1getShape(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerShapeHit* _self = (physx::PxControllerShapeHit*) _address;
    return (jlong) _self->shape;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerShapeHit__1setShape(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerShapeHit* _self = (physx::PxControllerShapeHit*) _address;
    _self->shape = (physx::PxShape*) value;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerShapeHit__1getActor(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerShapeHit* _self = (physx::PxControllerShapeHit*) _address;
    return (jlong) _self->actor;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerShapeHit__1setActor(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerShapeHit* _self = (physx::PxControllerShapeHit*) _address;
    _self->actor = (physx::PxRigidActor*) value;
}
JNIEXPORT jint JNICALL Java_physx_character_PxControllerShapeHit__1getTriangleIndex(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerShapeHit* _self = (physx::PxControllerShapeHit*) _address;
    return (jint) _self->triangleIndex;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerShapeHit__1setTriangleIndex(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxControllerShapeHit* _self = (physx::PxControllerShapeHit*) _address;
    _self->triangleIndex = value;
}

// PxControllersHit
JNIEXPORT jint JNICALL Java_physx_character_PxControllersHit__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxControllersHit);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllersHit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxControllersHit*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllersHit__1getOther(JNIEnv*, jclass, jlong _address) {
    physx::PxControllersHit* _self = (physx::PxControllersHit*) _address;
    return (jlong) _self->other;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllersHit__1setOther(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllersHit* _self = (physx::PxControllersHit*) _address;
    _self->other = (physx::PxController*) value;
}

// PxControllerState
JNIEXPORT jint JNICALL Java_physx_character_PxControllerState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxControllerState);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerState__1PxControllerState(JNIEnv*, jclass) {
    return (jlong) new physx::PxControllerState();
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxControllerState*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerState__1getDeltaXP(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    return (jlong) &_self->deltaXP;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerState__1setDeltaXP(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    _self->deltaXP = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerState__1getTouchedShape(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    return (jlong) _self->touchedShape;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerState__1setTouchedShape(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    _self->touchedShape = (physx::PxShape*) value;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerState__1getTouchedActor(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    return (jlong) _self->touchedActor;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerState__1setTouchedActor(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    _self->touchedActor = (physx::PxRigidActor*) value;
}
JNIEXPORT jint JNICALL Java_physx_character_PxControllerState__1getTouchedObstacleHandle(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    return (jint) _self->touchedObstacleHandle;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerState__1setTouchedObstacleHandle(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    _self->touchedObstacleHandle = value;
}
JNIEXPORT jint JNICALL Java_physx_character_PxControllerState__1getCollisionFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    return (jint) _self->collisionFlags;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerState__1setCollisionFlags(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    _self->collisionFlags = value;
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxControllerState__1getStandOnAnotherCCT(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    return (jboolean) _self->standOnAnotherCCT;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerState__1setStandOnAnotherCCT(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    _self->standOnAnotherCCT = value;
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxControllerState__1getStandOnObstacle(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    return (jboolean) _self->standOnObstacle;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerState__1setStandOnObstacle(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    _self->standOnObstacle = value;
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxControllerState__1getIsMovingUp(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    return (jboolean) _self->isMovingUp;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerState__1setIsMovingUp(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    _self->isMovingUp = value;
}

// PxControllerStats
JNIEXPORT jint JNICALL Java_physx_character_PxControllerStats__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxControllerStats);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerStats__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxControllerStats*) _address;
}
JNIEXPORT jshort JNICALL Java_physx_character_PxControllerStats__1getNbIterations(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerStats* _self = (physx::PxControllerStats*) _address;
    return (jshort) _self->nbIterations;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerStats__1setNbIterations(JNIEnv*, jclass, jlong _address, jshort value) {
    physx::PxControllerStats* _self = (physx::PxControllerStats*) _address;
    _self->nbIterations = value;
}
JNIEXPORT jshort JNICALL Java_physx_character_PxControllerStats__1getNbFullUpdates(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerStats* _self = (physx::PxControllerStats*) _address;
    return (jshort) _self->nbFullUpdates;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerStats__1setNbFullUpdates(JNIEnv*, jclass, jlong _address, jshort value) {
    physx::PxControllerStats* _self = (physx::PxControllerStats*) _address;
    _self->nbFullUpdates = value;
}
JNIEXPORT jshort JNICALL Java_physx_character_PxControllerStats__1getNbPartialUpdates(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerStats* _self = (physx::PxControllerStats*) _address;
    return (jshort) _self->nbPartialUpdates;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerStats__1setNbPartialUpdates(JNIEnv*, jclass, jlong _address, jshort value) {
    physx::PxControllerStats* _self = (physx::PxControllerStats*) _address;
    _self->nbPartialUpdates = value;
}
JNIEXPORT jshort JNICALL Java_physx_character_PxControllerStats__1getNbTessellation(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerStats* _self = (physx::PxControllerStats*) _address;
    return (jshort) _self->nbTessellation;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerStats__1setNbTessellation(JNIEnv*, jclass, jlong _address, jshort value) {
    physx::PxControllerStats* _self = (physx::PxControllerStats*) _address;
    _self->nbTessellation = value;
}

// PxExtendedVec3
JNIEXPORT jint JNICALL Java_physx_character_PxExtendedVec3__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxExtendedVec3);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxExtendedVec3__1_1placement_1new_1PxExtendedVec3__J(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxExtendedVec3();
}
JNIEXPORT jlong JNICALL Java_physx_character_PxExtendedVec3__1_1placement_1new_1PxExtendedVec3__JDDD(JNIEnv*, jclass, jlong _placement_address, jdouble x, jdouble y, jdouble z) {
    return (jlong) new((void*)_placement_address) physx::PxExtendedVec3(x, y, z);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxExtendedVec3__1PxExtendedVec3__(JNIEnv*, jclass) {
    return (jlong) new physx::PxExtendedVec3();
}
JNIEXPORT jlong JNICALL Java_physx_character_PxExtendedVec3__1PxExtendedVec3__DDD(JNIEnv*, jclass, jdouble x, jdouble y, jdouble z) {
    return (jlong) new physx::PxExtendedVec3(x, y, z);
}
JNIEXPORT void JNICALL Java_physx_character_PxExtendedVec3__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxExtendedVec3*) _address;
}
JNIEXPORT jdouble JNICALL Java_physx_character_PxExtendedVec3__1getX(JNIEnv*, jclass, jlong _address) {
    physx::PxExtendedVec3* _self = (physx::PxExtendedVec3*) _address;
    return (jdouble) _self->x;
}
JNIEXPORT void JNICALL Java_physx_character_PxExtendedVec3__1setX(JNIEnv*, jclass, jlong _address, jdouble value) {
    physx::PxExtendedVec3* _self = (physx::PxExtendedVec3*) _address;
    _self->x = value;
}
JNIEXPORT jdouble JNICALL Java_physx_character_PxExtendedVec3__1getY(JNIEnv*, jclass, jlong _address) {
    physx::PxExtendedVec3* _self = (physx::PxExtendedVec3*) _address;
    return (jdouble) _self->y;
}
JNIEXPORT void JNICALL Java_physx_character_PxExtendedVec3__1setY(JNIEnv*, jclass, jlong _address, jdouble value) {
    physx::PxExtendedVec3* _self = (physx::PxExtendedVec3*) _address;
    _self->y = value;
}
JNIEXPORT jdouble JNICALL Java_physx_character_PxExtendedVec3__1getZ(JNIEnv*, jclass, jlong _address) {
    physx::PxExtendedVec3* _self = (physx::PxExtendedVec3*) _address;
    return (jdouble) _self->z;
}
JNIEXPORT void JNICALL Java_physx_character_PxExtendedVec3__1setZ(JNIEnv*, jclass, jlong _address, jdouble value) {
    physx::PxExtendedVec3* _self = (physx::PxExtendedVec3*) _address;
    _self->z = value;
}

// PxObstacle
JNIEXPORT jint JNICALL Java_physx_character_PxObstacle__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxObstacle);
}
JNIEXPORT jint JNICALL Java_physx_character_PxObstacle__1getType(JNIEnv*, jclass, jlong _address) {
    physx::PxObstacle* self = (physx::PxObstacle*) _address;
    return (jint) self->getType();
}
JNIEXPORT void JNICALL Java_physx_character_PxObstacle__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxObstacle*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxObstacle__1getMUserData(JNIEnv*, jclass, jlong _address) {
    physx::PxObstacle* _self = (physx::PxObstacle*) _address;
    return (jlong) _self->mUserData;
}
JNIEXPORT void JNICALL Java_physx_character_PxObstacle__1setMUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxObstacle* _self = (physx::PxObstacle*) _address;
    _self->mUserData = (void*) value;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxObstacle__1getMPos(JNIEnv*, jclass, jlong _address) {
    physx::PxObstacle* _self = (physx::PxObstacle*) _address;
    return (jlong) &_self->mPos;
}
JNIEXPORT void JNICALL Java_physx_character_PxObstacle__1setMPos(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxObstacle* _self = (physx::PxObstacle*) _address;
    _self->mPos = *((physx::PxExtendedVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxObstacle__1getMRot(JNIEnv*, jclass, jlong _address) {
    physx::PxObstacle* _self = (physx::PxObstacle*) _address;
    return (jlong) &_self->mRot;
}
JNIEXPORT void JNICALL Java_physx_character_PxObstacle__1setMRot(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxObstacle* _self = (physx::PxObstacle*) _address;
    _self->mRot = *((physx::PxQuat*) value);
}

// PxObstacleContext
JNIEXPORT jint JNICALL Java_physx_character_PxObstacleContext__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxObstacleContext);
}
JNIEXPORT void JNICALL Java_physx_character_PxObstacleContext__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxObstacleContext* self = (physx::PxObstacleContext*) _address;
    self->release();
}
JNIEXPORT jlong JNICALL Java_physx_character_PxObstacleContext__1getControllerManager(JNIEnv*, jclass, jlong _address) {
    physx::PxObstacleContext* self = (physx::PxObstacleContext*) _address;
    return (jlong) &self->getControllerManager();
}
JNIEXPORT jint JNICALL Java_physx_character_PxObstacleContext__1addObstacle(JNIEnv*, jclass, jlong _address, jlong obstacle) {
    physx::PxObstacleContext* self = (physx::PxObstacleContext*) _address;
    return (jint) self->addObstacle(*((physx::PxObstacle*) obstacle));
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxObstacleContext__1removeObstacle(JNIEnv*, jclass, jlong _address, jint handle) {
    physx::PxObstacleContext* self = (physx::PxObstacleContext*) _address;
    return (jboolean) self->removeObstacle(handle);
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxObstacleContext__1updateObstacle(JNIEnv*, jclass, jlong _address, jint handle, jlong obstacle) {
    physx::PxObstacleContext* self = (physx::PxObstacleContext*) _address;
    return (jboolean) self->updateObstacle(handle, *((physx::PxObstacle*) obstacle));
}
JNIEXPORT jint JNICALL Java_physx_character_PxObstacleContext__1getNbObstacles(JNIEnv*, jclass, jlong _address) {
    physx::PxObstacleContext* self = (physx::PxObstacleContext*) _address;
    return (jint) self->getNbObstacles();
}
JNIEXPORT jlong JNICALL Java_physx_character_PxObstacleContext__1getObstacle(JNIEnv*, jclass, jlong _address, jint i) {
    physx::PxObstacleContext* self = (physx::PxObstacleContext*) _address;
    return (jlong) self->getObstacle(i);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxObstacleContext__1getObstacleByHandle(JNIEnv*, jclass, jlong _address, jint handle) {
    physx::PxObstacleContext* self = (physx::PxObstacleContext*) _address;
    return (jlong) self->getObstacleByHandle(handle);
}
JNIEXPORT void JNICALL Java_physx_character_PxObstacleContext__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxObstacleContext*) _address;
}

// PxUserControllerHitReport
JNIEXPORT jint JNICALL Java_physx_character_PxUserControllerHitReport__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxUserControllerHitReport);
}
JNIEXPORT void JNICALL Java_physx_character_PxUserControllerHitReport__1onShapeHit(JNIEnv*, jclass, jlong _address, jlong hit) {
    physx::PxUserControllerHitReport* self = (physx::PxUserControllerHitReport*) _address;
    self->onShapeHit(*((physx::PxControllerShapeHit*) hit));
}
JNIEXPORT void JNICALL Java_physx_character_PxUserControllerHitReport__1onControllerHit(JNIEnv*, jclass, jlong _address, jlong hit) {
    physx::PxUserControllerHitReport* self = (physx::PxUserControllerHitReport*) _address;
    self->onControllerHit(*((physx::PxControllersHit*) hit));
}
JNIEXPORT void JNICALL Java_physx_character_PxUserControllerHitReport__1onObstacleHit(JNIEnv*, jclass, jlong _address, jlong hit) {
    physx::PxUserControllerHitReport* self = (physx::PxUserControllerHitReport*) _address;
    self->onObstacleHit(*((physx::PxControllerObstacleHit*) hit));
}

// PxUserControllerHitReportImpl
JNIEXPORT jint JNICALL Java_physx_character_PxUserControllerHitReportImpl__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxUserControllerHitReportImpl);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxUserControllerHitReportImpl__1PxUserControllerHitReportImpl(JNIEnv* env, jobject obj) {
    return (jlong) new PxUserControllerHitReportImpl(env, obj);
}
JNIEXPORT void JNICALL Java_physx_character_PxUserControllerHitReportImpl__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (PxUserControllerHitReportImpl*) address;
}

// PxCapsuleClimbingModeEnum
JNIEXPORT jint JNICALL Java_physx_character_PxCapsuleClimbingModeEnum__1geteEASY(JNIEnv*, jclass) {
    return PxCapsuleClimbingModeEnum::eEASY;
}
JNIEXPORT jint JNICALL Java_physx_character_PxCapsuleClimbingModeEnum__1geteCONSTRAINED(JNIEnv*, jclass) {
    return PxCapsuleClimbingModeEnum::eCONSTRAINED;
}

// PxControllerBehaviorFlagEnum
JNIEXPORT jint JNICALL Java_physx_character_PxControllerBehaviorFlagEnum__1geteCCT_1CAN_1RIDE_1ON_1OBJECT(JNIEnv*, jclass) {
    return PxControllerBehaviorFlagEnum::eCCT_CAN_RIDE_ON_OBJECT;
}
JNIEXPORT jint JNICALL Java_physx_character_PxControllerBehaviorFlagEnum__1geteCCT_1SLIDE(JNIEnv*, jclass) {
    return PxControllerBehaviorFlagEnum::eCCT_SLIDE;
}
JNIEXPORT jint JNICALL Java_physx_character_PxControllerBehaviorFlagEnum__1geteCCT_1USER_1DEFINED_1RIDE(JNIEnv*, jclass) {
    return PxControllerBehaviorFlagEnum::eCCT_USER_DEFINED_RIDE;
}

// PxControllerCollisionFlagEnum
JNIEXPORT jint JNICALL Java_physx_character_PxControllerCollisionFlagEnum__1geteCOLLISION_1SIDES(JNIEnv*, jclass) {
    return PxControllerCollisionFlagEnum::eCOLLISION_SIDES;
}
JNIEXPORT jint JNICALL Java_physx_character_PxControllerCollisionFlagEnum__1geteCOLLISION_1UP(JNIEnv*, jclass) {
    return PxControllerCollisionFlagEnum::eCOLLISION_UP;
}
JNIEXPORT jint JNICALL Java_physx_character_PxControllerCollisionFlagEnum__1geteCOLLISION_1DOWN(JNIEnv*, jclass) {
    return PxControllerCollisionFlagEnum::eCOLLISION_DOWN;
}

// PxControllerNonWalkableModeEnum
JNIEXPORT jint JNICALL Java_physx_character_PxControllerNonWalkableModeEnum__1getePREVENT_1CLIMBING(JNIEnv*, jclass) {
    return PxControllerNonWalkableModeEnum::ePREVENT_CLIMBING;
}
JNIEXPORT jint JNICALL Java_physx_character_PxControllerNonWalkableModeEnum__1getePREVENT_1CLIMBING_1AND_1FORCE_1SLIDING(JNIEnv*, jclass) {
    return PxControllerNonWalkableModeEnum::ePREVENT_CLIMBING_AND_FORCE_SLIDING;
}

// PxControllerShapeTypeEnum
JNIEXPORT jint JNICALL Java_physx_character_PxControllerShapeTypeEnum__1geteBOX(JNIEnv*, jclass) {
    return PxControllerShapeTypeEnum::eBOX;
}
JNIEXPORT jint JNICALL Java_physx_character_PxControllerShapeTypeEnum__1geteCAPSULE(JNIEnv*, jclass) {
    return PxControllerShapeTypeEnum::eCAPSULE;
}

// PxBase
JNIEXPORT jint JNICALL Java_physx_common_PxBase__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxBase);
}
JNIEXPORT void JNICALL Java_physx_common_PxBase__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxBase* self = (physx::PxBase*) _address;
    self->release();
}
JNIEXPORT jstring JNICALL Java_physx_common_PxBase__1getConcreteTypeName(JNIEnv* _env, jclass, jlong _address) {
    physx::PxBase* self = (physx::PxBase*) _address;
    return _env->NewStringUTF(self->getConcreteTypeName());
}
JNIEXPORT jint JNICALL Java_physx_common_PxBase__1getConcreteType(JNIEnv*, jclass, jlong _address) {
    physx::PxBase* self = (physx::PxBase*) _address;
    return (jint) self->getConcreteType();
}
JNIEXPORT void JNICALL Java_physx_common_PxBase__1setBaseFlag(JNIEnv*, jclass, jlong _address, jint flag, jboolean value) {
    physx::PxBase* self = (physx::PxBase*) _address;
    self->setBaseFlag((PxBaseFlagEnum) flag, value);
}
JNIEXPORT void JNICALL Java_physx_common_PxBase__1setBaseFlags(JNIEnv*, jclass, jlong _address, jlong inFlags) {
    physx::PxBase* self = (physx::PxBase*) _address;
    self->setBaseFlags(*((physx::PxBaseFlags*) inFlags));
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBase__1getBaseFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxBase* self = (physx::PxBase*) _address;
    static thread_local physx::PxBaseFlags _cache = self->getBaseFlags();
    _cache = self->getBaseFlags();
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxBase__1isReleasable(JNIEnv*, jclass, jlong _address) {
    physx::PxBase* self = (physx::PxBase*) _address;
    return (jboolean) self->isReleasable();
}

// PxBaseFlags
JNIEXPORT jint JNICALL Java_physx_common_PxBaseFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxBaseFlags);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBaseFlags__1_1placement_1new_1PxBaseFlags(JNIEnv*, jclass, jlong _placement_address, jshort flags) {
    return (jlong) new((void*)_placement_address) physx::PxBaseFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBaseFlags__1PxBaseFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxBaseFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxBaseFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxBaseFlags* self = (physx::PxBaseFlags*) _address;
    return (jboolean) self->isSet((PxBaseFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_common_PxBaseFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxBaseFlags* self = (physx::PxBaseFlags*) _address;
    self->raise((PxBaseFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_common_PxBaseFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxBaseFlags* self = (physx::PxBaseFlags*) _address;
    self->clear((PxBaseFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_common_PxBaseFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBaseFlags*) _address;
}

// PxBaseTask
JNIEXPORT jint JNICALL Java_physx_common_PxBaseTask__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxBaseTask);
}
JNIEXPORT void JNICALL Java_physx_common_PxBaseTask__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBaseTask*) _address;
}

// PxBoundedData
JNIEXPORT jint JNICALL Java_physx_common_PxBoundedData__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxBoundedData);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBoundedData__1_1placement_1new_1PxBoundedData(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxBoundedData();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBoundedData__1PxBoundedData(JNIEnv*, jclass) {
    return (jlong) new physx::PxBoundedData();
}
JNIEXPORT void JNICALL Java_physx_common_PxBoundedData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBoundedData*) _address;
}
JNIEXPORT jint JNICALL Java_physx_common_PxBoundedData__1getCount(JNIEnv*, jclass, jlong _address) {
    physx::PxBoundedData* _self = (physx::PxBoundedData*) _address;
    return (jint) _self->count;
}
JNIEXPORT void JNICALL Java_physx_common_PxBoundedData__1setCount(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxBoundedData* _self = (physx::PxBoundedData*) _address;
    _self->count = value;
}

// PxBounds3
JNIEXPORT jint JNICALL Java_physx_common_PxBounds3__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxBounds3);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBounds3__1_1placement_1new_1PxBounds3__J(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxBounds3();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBounds3__1_1placement_1new_1PxBounds3__JJJ(JNIEnv*, jclass, jlong _placement_address, jlong minimum, jlong maximum) {
    return (jlong) new((void*)_placement_address) physx::PxBounds3(*((physx::PxVec3*) minimum), *((physx::PxVec3*) maximum));
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBounds3__1PxBounds3__(JNIEnv*, jclass) {
    return (jlong) new physx::PxBounds3();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBounds3__1PxBounds3__JJ(JNIEnv*, jclass, jlong minimum, jlong maximum) {
    return (jlong) new physx::PxBounds3(*((physx::PxVec3*) minimum), *((physx::PxVec3*) maximum));
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1setEmpty(JNIEnv*, jclass, jlong _address) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    self->setEmpty();
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1setMaximal(JNIEnv*, jclass, jlong _address) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    self->setMaximal();
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1include(JNIEnv*, jclass, jlong _address, jlong v) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    self->include(*((physx::PxVec3*) v));
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxBounds3__1isEmpty(JNIEnv*, jclass, jlong _address) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    return (jboolean) self->isEmpty();
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxBounds3__1intersects(JNIEnv*, jclass, jlong _address, jlong b) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    return (jboolean) self->intersects(*((physx::PxBounds3*) b));
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxBounds3__1intersects1D(JNIEnv*, jclass, jlong _address, jlong b, jint axis) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    return (jboolean) self->intersects1D(*((physx::PxBounds3*) b), axis);
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxBounds3__1contains(JNIEnv*, jclass, jlong _address, jlong v) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    return (jboolean) self->contains(*((physx::PxVec3*) v));
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxBounds3__1isInside(JNIEnv*, jclass, jlong _address, jlong box) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    return (jboolean) self->isInside(*((physx::PxBounds3*) box));
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBounds3__1getCenter(JNIEnv*, jclass, jlong _address) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    static thread_local physx::PxVec3 _cache = self->getCenter();
    _cache = self->getCenter();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBounds3__1getDimensions(JNIEnv*, jclass, jlong _address) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    static thread_local physx::PxVec3 _cache = self->getDimensions();
    _cache = self->getDimensions();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBounds3__1getExtents(JNIEnv*, jclass, jlong _address) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    static thread_local physx::PxVec3 _cache = self->getExtents();
    _cache = self->getExtents();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1scaleSafe(JNIEnv*, jclass, jlong _address, jfloat scale) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    self->scaleSafe(scale);
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1scaleFast(JNIEnv*, jclass, jlong _address, jfloat scale) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    self->scaleFast(scale);
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1fattenSafe(JNIEnv*, jclass, jlong _address, jfloat distance) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    self->fattenSafe(distance);
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1fattenFast(JNIEnv*, jclass, jlong _address, jfloat distance) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    self->fattenFast(distance);
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxBounds3__1isFinite(JNIEnv*, jclass, jlong _address) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    return (jboolean) self->isFinite();
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxBounds3__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBounds3*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBounds3__1getMinimum(JNIEnv*, jclass, jlong _address) {
    physx::PxBounds3* _self = (physx::PxBounds3*) _address;
    return (jlong) &_self->minimum;
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1setMinimum(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxBounds3* _self = (physx::PxBounds3*) _address;
    _self->minimum = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBounds3__1getMaximum(JNIEnv*, jclass, jlong _address) {
    physx::PxBounds3* _self = (physx::PxBounds3*) _address;
    return (jlong) &_self->maximum;
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1setMaximum(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxBounds3* _self = (physx::PxBounds3*) _address;
    _self->maximum = *((physx::PxVec3*) value);
}

// PxCollection
JNIEXPORT jint JNICALL Java_physx_common_PxCollection__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxCollection);
}
JNIEXPORT void JNICALL Java_physx_common_PxCollection__1add__JJ(JNIEnv*, jclass, jlong _address, jlong obj) {
    physx::PxCollection* self = (physx::PxCollection*) _address;
    self->add(*((physx::PxBase*) obj));
}
JNIEXPORT void JNICALL Java_physx_common_PxCollection__1add__JJJ(JNIEnv*, jclass, jlong _address, jlong obj, jlong id) {
    physx::PxCollection* self = (physx::PxCollection*) _address;
    self->add(*((physx::PxBase*) obj), id);
}
JNIEXPORT void JNICALL Java_physx_common_PxCollection__1remove(JNIEnv*, jclass, jlong _address, jlong obj) {
    physx::PxCollection* self = (physx::PxCollection*) _address;
    self->remove(*((physx::PxBase*) obj));
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxCollection__1contains(JNIEnv*, jclass, jlong _address, jlong obj) {
    physx::PxCollection* self = (physx::PxCollection*) _address;
    return (jboolean) self->contains(*((physx::PxBase*) obj));
}
JNIEXPORT void JNICALL Java_physx_common_PxCollection__1addId(JNIEnv*, jclass, jlong _address, jlong obj, jlong id) {
    physx::PxCollection* self = (physx::PxCollection*) _address;
    self->addId(*((physx::PxBase*) obj), id);
}
JNIEXPORT void JNICALL Java_physx_common_PxCollection__1removeId(JNIEnv*, jclass, jlong _address, jlong id) {
    physx::PxCollection* self = (physx::PxCollection*) _address;
    self->removeId(id);
}
JNIEXPORT jint JNICALL Java_physx_common_PxCollection__1getNbObjects(JNIEnv*, jclass, jlong _address) {
    physx::PxCollection* self = (physx::PxCollection*) _address;
    return (jint) self->getNbObjects();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxCollection__1getObject(JNIEnv*, jclass, jlong _address, jint index) {
    physx::PxCollection* self = (physx::PxCollection*) _address;
    return (jlong) &self->getObject(index);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxCollection__1find(JNIEnv*, jclass, jlong _address, jlong id) {
    physx::PxCollection* self = (physx::PxCollection*) _address;
    return (jlong) self->find(id);
}
JNIEXPORT jint JNICALL Java_physx_common_PxCollection__1getNbIds(JNIEnv*, jclass, jlong _address) {
    physx::PxCollection* self = (physx::PxCollection*) _address;
    return (jint) self->getNbIds();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxCollection__1getId(JNIEnv*, jclass, jlong _address, jlong obj) {
    physx::PxCollection* self = (physx::PxCollection*) _address;
    return (jlong) self->getId(*((physx::PxBase*) obj));
}
JNIEXPORT void JNICALL Java_physx_common_PxCollection__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxCollection* self = (physx::PxCollection*) _address;
    self->release();
}

// PxCpuDispatcher
JNIEXPORT jint JNICALL Java_physx_common_PxCpuDispatcher__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxCpuDispatcher);
}
JNIEXPORT void JNICALL Java_physx_common_PxCpuDispatcher__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxCpuDispatcher*) _address;
}

// PxDefaultAllocator
JNIEXPORT jint JNICALL Java_physx_common_PxDefaultAllocator__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxDefaultAllocator);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxDefaultAllocator__1PxDefaultAllocator(JNIEnv*, jclass) {
    return (jlong) new physx::PxDefaultAllocator();
}
JNIEXPORT void JNICALL Java_physx_common_PxDefaultAllocator__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxDefaultAllocator*) _address;
}

// PxDefaultCpuDispatcher
JNIEXPORT jint JNICALL Java_physx_common_PxDefaultCpuDispatcher__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxDefaultCpuDispatcher);
}
JNIEXPORT void JNICALL Java_physx_common_PxDefaultCpuDispatcher__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxDefaultCpuDispatcher*) _address;
}

// PxDefaultErrorCallback
JNIEXPORT jint JNICALL Java_physx_common_PxDefaultErrorCallback__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxDefaultErrorCallback);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxDefaultErrorCallback__1PxDefaultErrorCallback(JNIEnv*, jclass) {
    return (jlong) new physx::PxDefaultErrorCallback();
}
JNIEXPORT void JNICALL Java_physx_common_PxDefaultErrorCallback__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxDefaultErrorCallback*) _address;
}

// PxErrorCallback
JNIEXPORT jint JNICALL Java_physx_common_PxErrorCallback__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxErrorCallback);
}
JNIEXPORT void JNICALL Java_physx_common_PxErrorCallback__1reportError(JNIEnv* _env, jclass, jlong _address, jint code, jstring message, jstring file, jint line) {
    physx::PxErrorCallback* self = (physx::PxErrorCallback*) _address;
    self->reportError((PxErrorCodeEnum) code, _env->GetStringUTFChars(message, 0), _env->GetStringUTFChars(file, 0), line);
}
JNIEXPORT void JNICALL Java_physx_common_PxErrorCallback__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxErrorCallback*) _address;
}

// PxErrorCallbackImpl
JNIEXPORT jint JNICALL Java_physx_common_PxErrorCallbackImpl__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxErrorCallbackImpl);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxErrorCallbackImpl__1PxErrorCallbackImpl(JNIEnv* env, jobject obj) {
    return (jlong) new PxErrorCallbackImpl(env, obj);
}
JNIEXPORT void JNICALL Java_physx_common_PxErrorCallbackImpl__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (PxErrorCallbackImpl*) address;
}

// PxFoundation
JNIEXPORT jint JNICALL Java_physx_common_PxFoundation__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxFoundation);
}
JNIEXPORT void JNICALL Java_physx_common_PxFoundation__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxFoundation* self = (physx::PxFoundation*) _address;
    self->release();
}

// PxInputData
JNIEXPORT jint JNICALL Java_physx_common_PxInputData__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxInputData);
}
JNIEXPORT void JNICALL Java_physx_common_PxInputData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxInputData*) _address;
}

// PxInsertionCallback
JNIEXPORT jint JNICALL Java_physx_common_PxInsertionCallback__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxInsertionCallback);
}

// PxMat33
JNIEXPORT jint JNICALL Java_physx_common_PxMat33__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxMat33);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxMat33__1PxMat33__(JNIEnv*, jclass) {
    return (jlong) new physx::PxMat33();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxMat33__1PxMat33__I(JNIEnv*, jclass, jint r) {
    return (jlong) new physx::PxMat33((PxIDENTITYEnum) r);
}
JNIEXPORT void JNICALL Java_physx_common_PxMat33__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxMat33*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxMat33__1getColumn0(JNIEnv*, jclass, jlong _address) {
    physx::PxMat33* _self = (physx::PxMat33*) _address;
    return (jlong) &_self->column0;
}
JNIEXPORT void JNICALL Java_physx_common_PxMat33__1setColumn0(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxMat33* _self = (physx::PxMat33*) _address;
    _self->column0 = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxMat33__1getColumn1(JNIEnv*, jclass, jlong _address) {
    physx::PxMat33* _self = (physx::PxMat33*) _address;
    return (jlong) &_self->column1;
}
JNIEXPORT void JNICALL Java_physx_common_PxMat33__1setColumn1(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxMat33* _self = (physx::PxMat33*) _address;
    _self->column1 = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxMat33__1getColumn2(JNIEnv*, jclass, jlong _address) {
    physx::PxMat33* _self = (physx::PxMat33*) _address;
    return (jlong) &_self->column2;
}
JNIEXPORT void JNICALL Java_physx_common_PxMat33__1setColumn2(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxMat33* _self = (physx::PxMat33*) _address;
    _self->column2 = *((physx::PxVec3*) value);
}

// PxOutputStream
JNIEXPORT jint JNICALL Java_physx_common_PxOutputStream__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxOutputStream);
}
JNIEXPORT void JNICALL Java_physx_common_PxOutputStream__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxOutputStream*) _address;
}

// PxPlane
JNIEXPORT jint JNICALL Java_physx_common_PxPlane__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxPlane);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxPlane__1PxPlane__(JNIEnv*, jclass) {
    return (jlong) new physx::PxPlane();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxPlane__1PxPlane__FFFF(JNIEnv*, jclass, jfloat nx, jfloat ny, jfloat nz, jfloat distance) {
    return (jlong) new physx::PxPlane(nx, ny, nz, distance);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxPlane__1PxPlane__JF(JNIEnv*, jclass, jlong normal, jfloat distance) {
    return (jlong) new physx::PxPlane(*((physx::PxVec3*) normal), distance);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxPlane__1PxPlane__JJJ(JNIEnv*, jclass, jlong p0, jlong p1, jlong p2) {
    return (jlong) new physx::PxPlane(*((physx::PxVec3*) p0), *((physx::PxVec3*) p1), *((physx::PxVec3*) p2));
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxPlane__1distance(JNIEnv*, jclass, jlong _address, jlong p) {
    physx::PxPlane* self = (physx::PxPlane*) _address;
    return (jfloat) self->distance(*((physx::PxVec3*) p));
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxPlane__1contains(JNIEnv*, jclass, jlong _address, jlong p) {
    physx::PxPlane* self = (physx::PxPlane*) _address;
    return (jboolean) self->contains(*((physx::PxVec3*) p));
}
JNIEXPORT jlong JNICALL Java_physx_common_PxPlane__1project(JNIEnv*, jclass, jlong _address, jlong p) {
    physx::PxPlane* self = (physx::PxPlane*) _address;
    static thread_local physx::PxVec3 _cache = self->project(*((physx::PxVec3*) p));
    _cache = self->project(*((physx::PxVec3*) p));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxPlane__1pointInPlane(JNIEnv*, jclass, jlong _address) {
    physx::PxPlane* self = (physx::PxPlane*) _address;
    static thread_local physx::PxVec3 _cache = self->pointInPlane();
    _cache = self->pointInPlane();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_common_PxPlane__1normalize(JNIEnv*, jclass, jlong _address) {
    physx::PxPlane* self = (physx::PxPlane*) _address;
    self->normalize();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxPlane__1transform(JNIEnv*, jclass, jlong _address, jlong pose) {
    physx::PxPlane* self = (physx::PxPlane*) _address;
    static thread_local physx::PxPlane _cache = self->transform(*((physx::PxTransform*) pose));
    _cache = self->transform(*((physx::PxTransform*) pose));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxPlane__1inverseTransform(JNIEnv*, jclass, jlong _address, jlong pose) {
    physx::PxPlane* self = (physx::PxPlane*) _address;
    static thread_local physx::PxPlane _cache = self->inverseTransform(*((physx::PxTransform*) pose));
    _cache = self->inverseTransform(*((physx::PxTransform*) pose));
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_common_PxPlane__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxPlane*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxPlane__1getN(JNIEnv*, jclass, jlong _address) {
    physx::PxPlane* _self = (physx::PxPlane*) _address;
    return (jlong) &_self->n;
}
JNIEXPORT void JNICALL Java_physx_common_PxPlane__1setN(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxPlane* _self = (physx::PxPlane*) _address;
    _self->n = *((physx::PxVec3*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxPlane__1getD(JNIEnv*, jclass, jlong _address) {
    physx::PxPlane* _self = (physx::PxPlane*) _address;
    return (jfloat) _self->d;
}
JNIEXPORT void JNICALL Java_physx_common_PxPlane__1setD(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxPlane* _self = (physx::PxPlane*) _address;
    _self->d = value;
}

// PxQuat
JNIEXPORT jint JNICALL Java_physx_common_PxQuat__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxQuat);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxQuat__1_1placement_1new_1PxQuat__J(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxQuat();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxQuat__1_1placement_1new_1PxQuat__JI(JNIEnv*, jclass, jlong _placement_address, jint r) {
    return (jlong) new((void*)_placement_address) physx::PxQuat((PxIDENTITYEnum) r);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxQuat__1_1placement_1new_1PxQuat__JFFFF(JNIEnv*, jclass, jlong _placement_address, jfloat x, jfloat y, jfloat z, jfloat w) {
    return (jlong) new((void*)_placement_address) physx::PxQuat(x, y, z, w);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxQuat__1PxQuat__(JNIEnv*, jclass) {
    return (jlong) new physx::PxQuat();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxQuat__1PxQuat__I(JNIEnv*, jclass, jint r) {
    return (jlong) new physx::PxQuat((PxIDENTITYEnum) r);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxQuat__1PxQuat__FFFF(JNIEnv*, jclass, jfloat x, jfloat y, jfloat z, jfloat w) {
    return (jlong) new physx::PxQuat(x, y, z, w);
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxQuat__1isIdentity(JNIEnv*, jclass, jlong _address) {
    physx::PxQuat* self = (physx::PxQuat*) _address;
    return (jboolean) self->isIdentity();
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxQuat__1isFinite(JNIEnv*, jclass, jlong _address) {
    physx::PxQuat* self = (physx::PxQuat*) _address;
    return (jboolean) self->isFinite();
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxQuat__1isUnit(JNIEnv*, jclass, jlong _address) {
    physx::PxQuat* self = (physx::PxQuat*) _address;
    return (jboolean) self->isUnit();
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxQuat__1isSane(JNIEnv*, jclass, jlong _address) {
    physx::PxQuat* self = (physx::PxQuat*) _address;
    return (jboolean) self->isSane();
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxQuat__1getAngle__J(JNIEnv*, jclass, jlong _address) {
    physx::PxQuat* self = (physx::PxQuat*) _address;
    return (jfloat) self->getAngle();
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxQuat__1getAngle__JJ(JNIEnv*, jclass, jlong _address, jlong q) {
    physx::PxQuat* self = (physx::PxQuat*) _address;
    return (jfloat) self->getAngle(*((physx::PxQuat*) q));
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxQuat__1magnitudeSquared(JNIEnv*, jclass, jlong _address) {
    physx::PxQuat* self = (physx::PxQuat*) _address;
    return (jfloat) self->magnitudeSquared();
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxQuat__1dot(JNIEnv*, jclass, jlong _address, jlong q) {
    physx::PxQuat* self = (physx::PxQuat*) _address;
    return (jfloat) self->dot(*((physx::PxQuat*) q));
}
JNIEXPORT jlong JNICALL Java_physx_common_PxQuat__1getNormalized(JNIEnv*, jclass, jlong _address) {
    physx::PxQuat* self = (physx::PxQuat*) _address;
    static thread_local physx::PxQuat _cache = self->getNormalized();
    _cache = self->getNormalized();
    return (jlong) &_cache;
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxQuat__1magnitude(JNIEnv*, jclass, jlong _address) {
    physx::PxQuat* self = (physx::PxQuat*) _address;
    return (jfloat) self->magnitude();
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxQuat__1normalize(JNIEnv*, jclass, jlong _address) {
    physx::PxQuat* self = (physx::PxQuat*) _address;
    return (jfloat) self->normalize();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxQuat__1getConjugate(JNIEnv*, jclass, jlong _address) {
    physx::PxQuat* self = (physx::PxQuat*) _address;
    static thread_local physx::PxQuat _cache = self->getConjugate();
    _cache = self->getConjugate();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxQuat__1getImaginaryPart(JNIEnv*, jclass, jlong _address) {
    physx::PxQuat* self = (physx::PxQuat*) _address;
    static thread_local physx::PxVec3 _cache = self->getImaginaryPart();
    _cache = self->getImaginaryPart();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxQuat__1getBasisVector0(JNIEnv*, jclass, jlong _address) {
    physx::PxQuat* self = (physx::PxQuat*) _address;
    static thread_local physx::PxVec3 _cache = self->getBasisVector0();
    _cache = self->getBasisVector0();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxQuat__1getBasisVector1(JNIEnv*, jclass, jlong _address) {
    physx::PxQuat* self = (physx::PxQuat*) _address;
    static thread_local physx::PxVec3 _cache = self->getBasisVector1();
    _cache = self->getBasisVector1();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxQuat__1getBasisVector2(JNIEnv*, jclass, jlong _address) {
    physx::PxQuat* self = (physx::PxQuat*) _address;
    static thread_local physx::PxVec3 _cache = self->getBasisVector2();
    _cache = self->getBasisVector2();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxQuat__1rotate(JNIEnv*, jclass, jlong _address, jlong v) {
    physx::PxQuat* self = (physx::PxQuat*) _address;
    static thread_local physx::PxVec3 _cache = self->rotate(*((physx::PxVec3*) v));
    _cache = self->rotate(*((physx::PxVec3*) v));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxQuat__1rotateInv(JNIEnv*, jclass, jlong _address, jlong v) {
    physx::PxQuat* self = (physx::PxQuat*) _address;
    static thread_local physx::PxVec3 _cache = self->rotateInv(*((physx::PxVec3*) v));
    _cache = self->rotateInv(*((physx::PxVec3*) v));
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_common_PxQuat__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxQuat*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxQuat__1getX(JNIEnv*, jclass, jlong _address) {
    physx::PxQuat* _self = (physx::PxQuat*) _address;
    return (jfloat) _self->x;
}
JNIEXPORT void JNICALL Java_physx_common_PxQuat__1setX(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxQuat* _self = (physx::PxQuat*) _address;
    _self->x = value;
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxQuat__1getY(JNIEnv*, jclass, jlong _address) {
    physx::PxQuat* _self = (physx::PxQuat*) _address;
    return (jfloat) _self->y;
}
JNIEXPORT void JNICALL Java_physx_common_PxQuat__1setY(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxQuat* _self = (physx::PxQuat*) _address;
    _self->y = value;
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxQuat__1getZ(JNIEnv*, jclass, jlong _address) {
    physx::PxQuat* _self = (physx::PxQuat*) _address;
    return (jfloat) _self->z;
}
JNIEXPORT void JNICALL Java_physx_common_PxQuat__1setZ(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxQuat* _self = (physx::PxQuat*) _address;
    _self->z = value;
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxQuat__1getW(JNIEnv*, jclass, jlong _address) {
    physx::PxQuat* _self = (physx::PxQuat*) _address;
    return (jfloat) _self->w;
}
JNIEXPORT void JNICALL Java_physx_common_PxQuat__1setW(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxQuat* _self = (physx::PxQuat*) _address;
    _self->w = value;
}

// PxRefCounted
JNIEXPORT jint JNICALL Java_physx_common_PxRefCounted__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxRefCounted);
}
JNIEXPORT jint JNICALL Java_physx_common_PxRefCounted__1getReferenceCount(JNIEnv*, jclass, jlong _address) {
    physx::PxRefCounted* self = (physx::PxRefCounted*) _address;
    return (jint) self->getReferenceCount();
}
JNIEXPORT void JNICALL Java_physx_common_PxRefCounted__1acquireReference(JNIEnv*, jclass, jlong _address) {
    physx::PxRefCounted* self = (physx::PxRefCounted*) _address;
    self->acquireReference();
}

// PxStridedData
JNIEXPORT jint JNICALL Java_physx_common_PxStridedData__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxStridedData);
}
JNIEXPORT void JNICALL Java_physx_common_PxStridedData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxStridedData*) _address;
}
JNIEXPORT jint JNICALL Java_physx_common_PxStridedData__1getStride(JNIEnv*, jclass, jlong _address) {
    physx::PxStridedData* _self = (physx::PxStridedData*) _address;
    return (jint) _self->stride;
}
JNIEXPORT void JNICALL Java_physx_common_PxStridedData__1setStride(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxStridedData* _self = (physx::PxStridedData*) _address;
    _self->stride = value;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxStridedData__1getData(JNIEnv*, jclass, jlong _address) {
    physx::PxStridedData* _self = (physx::PxStridedData*) _address;
    return (jlong) _self->data;
}
JNIEXPORT void JNICALL Java_physx_common_PxStridedData__1setData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxStridedData* _self = (physx::PxStridedData*) _address;
    _self->data = (void*) value;
}

// PxTolerancesScale
JNIEXPORT jint JNICALL Java_physx_common_PxTolerancesScale__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxTolerancesScale);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxTolerancesScale__1PxTolerancesScale(JNIEnv*, jclass) {
    return (jlong) new physx::PxTolerancesScale();
}
JNIEXPORT void JNICALL Java_physx_common_PxTolerancesScale__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxTolerancesScale*) _address;
}

// PxTransform
JNIEXPORT jint JNICALL Java_physx_common_PxTransform__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxTransform);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxTransform__1_1placement_1new_1PxTransform__J(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxTransform();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxTransform__1_1placement_1new_1PxTransform__JI(JNIEnv*, jclass, jlong _placement_address, jint r) {
    return (jlong) new((void*)_placement_address) physx::PxTransform((PxIDENTITYEnum) r);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxTransform__1_1placement_1new_1PxTransform__JJJ(JNIEnv*, jclass, jlong _placement_address, jlong p0, jlong q0) {
    return (jlong) new((void*)_placement_address) physx::PxTransform(*((physx::PxVec3*) p0), *((physx::PxQuat*) q0));
}
JNIEXPORT jlong JNICALL Java_physx_common_PxTransform__1PxTransform__(JNIEnv*, jclass) {
    return (jlong) new physx::PxTransform();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxTransform__1PxTransform__I(JNIEnv*, jclass, jint r) {
    return (jlong) new physx::PxTransform((PxIDENTITYEnum) r);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxTransform__1PxTransform__JJ(JNIEnv*, jclass, jlong p0, jlong q0) {
    return (jlong) new physx::PxTransform(*((physx::PxVec3*) p0), *((physx::PxQuat*) q0));
}
JNIEXPORT void JNICALL Java_physx_common_PxTransform__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxTransform*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxTransform__1getQ(JNIEnv*, jclass, jlong _address) {
    physx::PxTransform* _self = (physx::PxTransform*) _address;
    return (jlong) &_self->q;
}
JNIEXPORT void JNICALL Java_physx_common_PxTransform__1setQ(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxTransform* _self = (physx::PxTransform*) _address;
    _self->q = *((physx::PxQuat*) value);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxTransform__1getP(JNIEnv*, jclass, jlong _address) {
    physx::PxTransform* _self = (physx::PxTransform*) _address;
    return (jlong) &_self->p;
}
JNIEXPORT void JNICALL Java_physx_common_PxTransform__1setP(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxTransform* _self = (physx::PxTransform*) _address;
    _self->p = *((physx::PxVec3*) value);
}

// PxU16StridedData
JNIEXPORT jint JNICALL Java_physx_common_PxU16StridedData__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxU16StridedData);
}
JNIEXPORT void JNICALL Java_physx_common_PxU16StridedData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxU16StridedData*) _address;
}
JNIEXPORT jint JNICALL Java_physx_common_PxU16StridedData__1getStride(JNIEnv*, jclass, jlong _address) {
    PxU16StridedData* _self = (PxU16StridedData*) _address;
    return (jint) _self->stride;
}
JNIEXPORT void JNICALL Java_physx_common_PxU16StridedData__1setStride(JNIEnv*, jclass, jlong _address, jint value) {
    PxU16StridedData* _self = (PxU16StridedData*) _address;
    _self->stride = value;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxU16StridedData__1getData(JNIEnv*, jclass, jlong _address) {
    PxU16StridedData* _self = (PxU16StridedData*) _address;
    return (jlong) &_self->data;
}
JNIEXPORT void JNICALL Java_physx_common_PxU16StridedData__1setData(JNIEnv*, jclass, jlong _address, jlong value) {
    PxU16StridedData* _self = (PxU16StridedData*) _address;
    _self->data = *((PxU16ConstPtr*) value);
}

// PxVec3
JNIEXPORT jint JNICALL Java_physx_common_PxVec3__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxVec3);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxVec3__1_1placement_1new_1PxVec3__J(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxVec3();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxVec3__1_1placement_1new_1PxVec3__JFFF(JNIEnv*, jclass, jlong _placement_address, jfloat x, jfloat y, jfloat z) {
    return (jlong) new((void*)_placement_address) physx::PxVec3(x, y, z);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxVec3__1PxVec3__(JNIEnv*, jclass) {
    return (jlong) new physx::PxVec3();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxVec3__1PxVec3__FFF(JNIEnv*, jclass, jfloat x, jfloat y, jfloat z) {
    return (jlong) new physx::PxVec3(x, y, z);
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxVec3__1isZero(JNIEnv*, jclass, jlong _address) {
    physx::PxVec3* self = (physx::PxVec3*) _address;
    return (jboolean) self->isZero();
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxVec3__1isFinite(JNIEnv*, jclass, jlong _address) {
    physx::PxVec3* self = (physx::PxVec3*) _address;
    return (jboolean) self->isFinite();
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxVec3__1isNormalized(JNIEnv*, jclass, jlong _address) {
    physx::PxVec3* self = (physx::PxVec3*) _address;
    return (jboolean) self->isNormalized();
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxVec3__1magnitudeSquared(JNIEnv*, jclass, jlong _address) {
    physx::PxVec3* self = (physx::PxVec3*) _address;
    return (jfloat) self->magnitudeSquared();
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxVec3__1magnitude(JNIEnv*, jclass, jlong _address) {
    physx::PxVec3* self = (physx::PxVec3*) _address;
    return (jfloat) self->magnitude();
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxVec3__1dot(JNIEnv*, jclass, jlong _address, jlong v) {
    physx::PxVec3* self = (physx::PxVec3*) _address;
    return (jfloat) self->dot(*((physx::PxVec3*) v));
}
JNIEXPORT jlong JNICALL Java_physx_common_PxVec3__1cross(JNIEnv*, jclass, jlong _address, jlong v) {
    physx::PxVec3* self = (physx::PxVec3*) _address;
    static thread_local physx::PxVec3 _cache = self->cross(*((physx::PxVec3*) v));
    _cache = self->cross(*((physx::PxVec3*) v));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxVec3__1getNormalized(JNIEnv*, jclass, jlong _address) {
    physx::PxVec3* self = (physx::PxVec3*) _address;
    static thread_local physx::PxVec3 _cache = self->getNormalized();
    _cache = self->getNormalized();
    return (jlong) &_cache;
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxVec3__1normalize(JNIEnv*, jclass, jlong _address) {
    physx::PxVec3* self = (physx::PxVec3*) _address;
    return (jfloat) self->normalize();
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxVec3__1normalizeSafe(JNIEnv*, jclass, jlong _address) {
    physx::PxVec3* self = (physx::PxVec3*) _address;
    return (jfloat) self->normalizeSafe();
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxVec3__1normalizeFast(JNIEnv*, jclass, jlong _address) {
    physx::PxVec3* self = (physx::PxVec3*) _address;
    return (jfloat) self->normalizeFast();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxVec3__1multiply(JNIEnv*, jclass, jlong _address, jlong a) {
    physx::PxVec3* self = (physx::PxVec3*) _address;
    static thread_local physx::PxVec3 _cache = self->multiply(*((physx::PxVec3*) a));
    _cache = self->multiply(*((physx::PxVec3*) a));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxVec3__1minimum(JNIEnv*, jclass, jlong _address, jlong v) {
    physx::PxVec3* self = (physx::PxVec3*) _address;
    static thread_local physx::PxVec3 _cache = self->minimum(*((physx::PxVec3*) v));
    _cache = self->minimum(*((physx::PxVec3*) v));
    return (jlong) &_cache;
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxVec3__1minElement(JNIEnv*, jclass, jlong _address) {
    physx::PxVec3* self = (physx::PxVec3*) _address;
    return (jfloat) self->minElement();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxVec3__1maximum(JNIEnv*, jclass, jlong _address, jlong v) {
    physx::PxVec3* self = (physx::PxVec3*) _address;
    static thread_local physx::PxVec3 _cache = self->maximum(*((physx::PxVec3*) v));
    _cache = self->maximum(*((physx::PxVec3*) v));
    return (jlong) &_cache;
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxVec3__1maxElement(JNIEnv*, jclass, jlong _address) {
    physx::PxVec3* self = (physx::PxVec3*) _address;
    return (jfloat) self->maxElement();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxVec3__1abs(JNIEnv*, jclass, jlong _address) {
    physx::PxVec3* self = (physx::PxVec3*) _address;
    static thread_local physx::PxVec3 _cache = self->abs();
    _cache = self->abs();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_common_PxVec3__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxVec3*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxVec3__1getX(JNIEnv*, jclass, jlong _address) {
    physx::PxVec3* _self = (physx::PxVec3*) _address;
    return (jfloat) _self->x;
}
JNIEXPORT void JNICALL Java_physx_common_PxVec3__1setX(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVec3* _self = (physx::PxVec3*) _address;
    _self->x = value;
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxVec3__1getY(JNIEnv*, jclass, jlong _address) {
    physx::PxVec3* _self = (physx::PxVec3*) _address;
    return (jfloat) _self->y;
}
JNIEXPORT void JNICALL Java_physx_common_PxVec3__1setY(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVec3* _self = (physx::PxVec3*) _address;
    _self->y = value;
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxVec3__1getZ(JNIEnv*, jclass, jlong _address) {
    physx::PxVec3* _self = (physx::PxVec3*) _address;
    return (jfloat) _self->z;
}
JNIEXPORT void JNICALL Java_physx_common_PxVec3__1setZ(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVec3* _self = (physx::PxVec3*) _address;
    _self->z = value;
}

// PxCudaTopLevelFunctions
JNIEXPORT jint JNICALL Java_physx_common_PxCudaTopLevelFunctions__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxCudaTopLevelFunctions);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxCudaTopLevelFunctions__1CreateCudaContextManager(JNIEnv*, jclass, jlong foundation, jlong desc) {
    return (jlong) PxCudaTopLevelFunctions::CreateCudaContextManager(*((physx::PxFoundation*) foundation), *((physx::PxCudaContextManagerDesc*) desc));
}

// CUcontext
JNIEXPORT jint JNICALL Java_physx_common_CUcontext__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(CUcontext);
}
JNIEXPORT void JNICALL Java_physx_common_CUcontext__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (CUcontext*) _address;
}

// CUdevice
JNIEXPORT jint JNICALL Java_physx_common_CUdevice__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(CUdevice);
}
JNIEXPORT void JNICALL Java_physx_common_CUdevice__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (CUdevice*) _address;
}

// CUmodule
JNIEXPORT jint JNICALL Java_physx_common_CUmodule__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(CUmodule);
}
JNIEXPORT void JNICALL Java_physx_common_CUmodule__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (CUmodule*) _address;
}

// PxCudaContext
JNIEXPORT jint JNICALL Java_physx_common_PxCudaContext__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxCudaContext);
}

// PxCudaContextManager
JNIEXPORT jint JNICALL Java_physx_common_PxCudaContextManager__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxCudaContextManager);
}
JNIEXPORT void JNICALL Java_physx_common_PxCudaContextManager__1acquireContext(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    self->acquireContext();
}
JNIEXPORT void JNICALL Java_physx_common_PxCudaContextManager__1releaseContext(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    self->releaseContext();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxCudaContextManager__1getContext(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return (jlong) self->getContext();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxCudaContextManager__1getCudaContext(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return (jlong) self->getCudaContext();
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxCudaContextManager__1contextIsValid(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return (jboolean) self->contextIsValid();
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxCudaContextManager__1supportsArchSM10(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return (jboolean) self->supportsArchSM10();
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxCudaContextManager__1supportsArchSM11(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return (jboolean) self->supportsArchSM11();
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxCudaContextManager__1supportsArchSM12(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return (jboolean) self->supportsArchSM12();
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxCudaContextManager__1supportsArchSM13(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return (jboolean) self->supportsArchSM13();
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxCudaContextManager__1supportsArchSM20(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return (jboolean) self->supportsArchSM20();
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxCudaContextManager__1supportsArchSM30(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return (jboolean) self->supportsArchSM30();
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxCudaContextManager__1supportsArchSM35(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return (jboolean) self->supportsArchSM35();
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxCudaContextManager__1supportsArchSM50(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return (jboolean) self->supportsArchSM50();
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxCudaContextManager__1supportsArchSM52(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return (jboolean) self->supportsArchSM52();
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxCudaContextManager__1supportsArchSM60(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return (jboolean) self->supportsArchSM60();
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxCudaContextManager__1isIntegrated(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return (jboolean) self->isIntegrated();
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxCudaContextManager__1canMapHostMemory(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return (jboolean) self->canMapHostMemory();
}
JNIEXPORT jint JNICALL Java_physx_common_PxCudaContextManager__1getDriverVersion(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return (jint) self->getDriverVersion();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxCudaContextManager__1getDeviceTotalMemBytes(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return (jlong) self->getDeviceTotalMemBytes();
}
JNIEXPORT jint JNICALL Java_physx_common_PxCudaContextManager__1getMultiprocessorCount(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return (jint) self->getMultiprocessorCount();
}
JNIEXPORT jint JNICALL Java_physx_common_PxCudaContextManager__1getClockRate(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return (jint) self->getClockRate();
}
JNIEXPORT jint JNICALL Java_physx_common_PxCudaContextManager__1getSharedMemPerBlock(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return (jint) self->getSharedMemPerBlock();
}
JNIEXPORT jint JNICALL Java_physx_common_PxCudaContextManager__1getSharedMemPerMultiprocessor(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return (jint) self->getSharedMemPerMultiprocessor();
}
JNIEXPORT jint JNICALL Java_physx_common_PxCudaContextManager__1getMaxThreadsPerBlock(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return (jint) self->getMaxThreadsPerBlock();
}
JNIEXPORT jstring JNICALL Java_physx_common_PxCudaContextManager__1getDeviceName(JNIEnv* _env, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return _env->NewStringUTF(self->getDeviceName());
}
JNIEXPORT jlong JNICALL Java_physx_common_PxCudaContextManager__1getDevice(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return (jlong) self->getDevice();
}
JNIEXPORT jint JNICALL Java_physx_common_PxCudaContextManager__1getInteropMode(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return (jint) self->getInteropMode();
}
JNIEXPORT void JNICALL Java_physx_common_PxCudaContextManager__1setUsingConcurrentStreams(JNIEnv*, jclass, jlong _address, jboolean flag) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    self->setUsingConcurrentStreams(flag);
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxCudaContextManager__1getUsingConcurrentStreams(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return (jboolean) self->getUsingConcurrentStreams();
}
JNIEXPORT jint JNICALL Java_physx_common_PxCudaContextManager__1usingDedicatedGPU(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return (jint) self->usingDedicatedGPU();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxCudaContextManager__1getCuModules(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    return (jlong) self->getCuModules();
}
JNIEXPORT void JNICALL Java_physx_common_PxCudaContextManager__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManager* self = (physx::PxCudaContextManager*) _address;
    self->release();
}

// PxCudaContextManagerDesc
JNIEXPORT jint JNICALL Java_physx_common_PxCudaContextManagerDesc__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxCudaContextManagerDesc);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxCudaContextManagerDesc__1_1placement_1new_1PxCudaContextManagerDesc(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxCudaContextManagerDesc();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxCudaContextManagerDesc__1PxCudaContextManagerDesc(JNIEnv*, jclass) {
    return (jlong) new physx::PxCudaContextManagerDesc();
}
JNIEXPORT void JNICALL Java_physx_common_PxCudaContextManagerDesc__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxCudaContextManagerDesc*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxCudaContextManagerDesc__1getCtx(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManagerDesc* _self = (physx::PxCudaContextManagerDesc*) _address;
    return (jlong) _self->ctx;
}
JNIEXPORT void JNICALL Java_physx_common_PxCudaContextManagerDesc__1setCtx(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxCudaContextManagerDesc* _self = (physx::PxCudaContextManagerDesc*) _address;
    _self->ctx = (CUcontext*) value;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxCudaContextManagerDesc__1getGraphicsDevice(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManagerDesc* _self = (physx::PxCudaContextManagerDesc*) _address;
    return (jlong) _self->graphicsDevice;
}
JNIEXPORT void JNICALL Java_physx_common_PxCudaContextManagerDesc__1setGraphicsDevice(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxCudaContextManagerDesc* _self = (physx::PxCudaContextManagerDesc*) _address;
    _self->graphicsDevice = (void*) value;
}
JNIEXPORT jstring JNICALL Java_physx_common_PxCudaContextManagerDesc__1getAppGUID(JNIEnv* _env, jclass, jlong _address) {
    physx::PxCudaContextManagerDesc* _self = (physx::PxCudaContextManagerDesc*) _address;
    return _env->NewStringUTF(_self->appGUID);
}
JNIEXPORT void JNICALL Java_physx_common_PxCudaContextManagerDesc__1setAppGUID(JNIEnv* _env, jclass, jlong _address, jstring value) {
    physx::PxCudaContextManagerDesc* _self = (physx::PxCudaContextManagerDesc*) _address;
    _self->appGUID = _env->GetStringUTFChars(value, 0);
}
JNIEXPORT jint JNICALL Java_physx_common_PxCudaContextManagerDesc__1getInteropMode(JNIEnv*, jclass, jlong _address) {
    physx::PxCudaContextManagerDesc* _self = (physx::PxCudaContextManagerDesc*) _address;
    return (jint) _self->interopMode;
}
JNIEXPORT void JNICALL Java_physx_common_PxCudaContextManagerDesc__1setInteropMode(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxCudaContextManagerDesc* _self = (physx::PxCudaContextManagerDesc*) _address;
    _self->interopMode = (PxCudaInteropModeEnum) value;
}

// PxgDynamicsMemoryConfig
JNIEXPORT jint JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxgDynamicsMemoryConfig);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1PxgDynamicsMemoryConfig(JNIEnv*, jclass) {
    return (jlong) new physx::PxgDynamicsMemoryConfig();
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxgDynamicsMemoryConfig* self = (physx::PxgDynamicsMemoryConfig*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxgDynamicsMemoryConfig*) _address;
}
JNIEXPORT jint JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1getTempBufferCapacity(JNIEnv*, jclass, jlong _address) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    return (jint) _self->tempBufferCapacity;
}
JNIEXPORT void JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1setTempBufferCapacity(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    _self->tempBufferCapacity = value;
}
JNIEXPORT jint JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1getMaxRigidContactCount(JNIEnv*, jclass, jlong _address) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    return (jint) _self->maxRigidContactCount;
}
JNIEXPORT void JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1setMaxRigidContactCount(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    _self->maxRigidContactCount = value;
}
JNIEXPORT jint JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1getMaxRigidPatchCount(JNIEnv*, jclass, jlong _address) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    return (jint) _self->maxRigidPatchCount;
}
JNIEXPORT void JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1setMaxRigidPatchCount(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    _self->maxRigidPatchCount = value;
}
JNIEXPORT jint JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1getHeapCapacity(JNIEnv*, jclass, jlong _address) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    return (jint) _self->heapCapacity;
}
JNIEXPORT void JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1setHeapCapacity(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    _self->heapCapacity = value;
}
JNIEXPORT jint JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1getFoundLostPairsCapacity(JNIEnv*, jclass, jlong _address) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    return (jint) _self->foundLostPairsCapacity;
}
JNIEXPORT void JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1setFoundLostPairsCapacity(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    _self->foundLostPairsCapacity = value;
}
JNIEXPORT jint JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1getFoundLostAggregatePairsCapacity(JNIEnv*, jclass, jlong _address) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    return (jint) _self->foundLostAggregatePairsCapacity;
}
JNIEXPORT void JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1setFoundLostAggregatePairsCapacity(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    _self->foundLostAggregatePairsCapacity = value;
}
JNIEXPORT jint JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1getTotalAggregatePairsCapacity(JNIEnv*, jclass, jlong _address) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    return (jint) _self->totalAggregatePairsCapacity;
}
JNIEXPORT void JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1setTotalAggregatePairsCapacity(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    _self->totalAggregatePairsCapacity = value;
}
JNIEXPORT jint JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1getMaxSoftBodyContacts(JNIEnv*, jclass, jlong _address) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    return (jint) _self->maxSoftBodyContacts;
}
JNIEXPORT void JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1setMaxSoftBodyContacts(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    _self->maxSoftBodyContacts = value;
}
JNIEXPORT jint JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1getMaxFemClothContacts(JNIEnv*, jclass, jlong _address) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    return (jint) _self->maxFemClothContacts;
}
JNIEXPORT void JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1setMaxFemClothContacts(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    _self->maxFemClothContacts = value;
}
JNIEXPORT jint JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1getMaxParticleContacts(JNIEnv*, jclass, jlong _address) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    return (jint) _self->maxParticleContacts;
}
JNIEXPORT void JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1setMaxParticleContacts(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    _self->maxParticleContacts = value;
}
JNIEXPORT jint JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1getCollisionStackSize(JNIEnv*, jclass, jlong _address) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    return (jint) _self->collisionStackSize;
}
JNIEXPORT void JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1setCollisionStackSize(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    _self->collisionStackSize = value;
}
JNIEXPORT jint JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1getMaxHairContacts(JNIEnv*, jclass, jlong _address) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    return (jint) _self->maxHairContacts;
}
JNIEXPORT void JNICALL Java_physx_common_PxgDynamicsMemoryConfig__1setMaxHairContacts(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    _self->maxHairContacts = value;
}

// PxBaseFlagEnum
JNIEXPORT jint JNICALL Java_physx_common_PxBaseFlagEnum__1geteOWNS_1MEMORY(JNIEnv*, jclass) {
    return PxBaseFlagEnum::eOWNS_MEMORY;
}
JNIEXPORT jint JNICALL Java_physx_common_PxBaseFlagEnum__1geteIS_1RELEASABLE(JNIEnv*, jclass) {
    return PxBaseFlagEnum::eIS_RELEASABLE;
}

// PxErrorCodeEnum
JNIEXPORT jint JNICALL Java_physx_common_PxErrorCodeEnum__1geteNO_1ERROR(JNIEnv*, jclass) {
    return PxErrorCodeEnum::eNO_ERROR;
}
JNIEXPORT jint JNICALL Java_physx_common_PxErrorCodeEnum__1geteDEBUG_1INFO(JNIEnv*, jclass) {
    return PxErrorCodeEnum::eDEBUG_INFO;
}
JNIEXPORT jint JNICALL Java_physx_common_PxErrorCodeEnum__1geteDEBUG_1WARNING(JNIEnv*, jclass) {
    return PxErrorCodeEnum::eDEBUG_WARNING;
}
JNIEXPORT jint JNICALL Java_physx_common_PxErrorCodeEnum__1geteINVALID_1PARAMETER(JNIEnv*, jclass) {
    return PxErrorCodeEnum::eINVALID_PARAMETER;
}
JNIEXPORT jint JNICALL Java_physx_common_PxErrorCodeEnum__1geteINVALID_1OPERATION(JNIEnv*, jclass) {
    return PxErrorCodeEnum::eINVALID_OPERATION;
}
JNIEXPORT jint JNICALL Java_physx_common_PxErrorCodeEnum__1geteOUT_1OF_1MEMORY(JNIEnv*, jclass) {
    return PxErrorCodeEnum::eOUT_OF_MEMORY;
}
JNIEXPORT jint JNICALL Java_physx_common_PxErrorCodeEnum__1geteINTERNAL_1ERROR(JNIEnv*, jclass) {
    return PxErrorCodeEnum::eINTERNAL_ERROR;
}
JNIEXPORT jint JNICALL Java_physx_common_PxErrorCodeEnum__1geteABORT(JNIEnv*, jclass) {
    return PxErrorCodeEnum::eABORT;
}
JNIEXPORT jint JNICALL Java_physx_common_PxErrorCodeEnum__1getePERF_1WARNING(JNIEnv*, jclass) {
    return PxErrorCodeEnum::ePERF_WARNING;
}
JNIEXPORT jint JNICALL Java_physx_common_PxErrorCodeEnum__1geteMASK_1ALL(JNIEnv*, jclass) {
    return PxErrorCodeEnum::eMASK_ALL;
}

// PxIDENTITYEnum
JNIEXPORT jint JNICALL Java_physx_common_PxIDENTITYEnum__1getPxIdentity(JNIEnv*, jclass) {
    return PxIDENTITYEnum::PxIdentity;
}

// PxCudaInteropModeEnum
JNIEXPORT jint JNICALL Java_physx_common_PxCudaInteropModeEnum__1getNO_1INTEROP(JNIEnv*, jclass) {
    return PxCudaInteropModeEnum::NO_INTEROP;
}
JNIEXPORT jint JNICALL Java_physx_common_PxCudaInteropModeEnum__1getD3D10_1INTEROP(JNIEnv*, jclass) {
    return PxCudaInteropModeEnum::D3D10_INTEROP;
}
JNIEXPORT jint JNICALL Java_physx_common_PxCudaInteropModeEnum__1getD3D11_1INTEROP(JNIEnv*, jclass) {
    return PxCudaInteropModeEnum::D3D11_INTEROP;
}
JNIEXPORT jint JNICALL Java_physx_common_PxCudaInteropModeEnum__1getOGL_1INTEROP(JNIEnv*, jclass) {
    return PxCudaInteropModeEnum::OGL_INTEROP;
}

// PxBVH33MidphaseDesc
JNIEXPORT jint JNICALL Java_physx_cooking_PxBVH33MidphaseDesc__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxBVH33MidphaseDesc);
}
JNIEXPORT void JNICALL Java_physx_cooking_PxBVH33MidphaseDesc__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::PxBVH33MidphaseDesc* self = (physx::PxBVH33MidphaseDesc*) _address;
    self->setToDefault();
}
JNIEXPORT jboolean JNICALL Java_physx_cooking_PxBVH33MidphaseDesc__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxBVH33MidphaseDesc* self = (physx::PxBVH33MidphaseDesc*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_cooking_PxBVH33MidphaseDesc__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBVH33MidphaseDesc*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_cooking_PxBVH33MidphaseDesc__1getMeshSizePerformanceTradeOff(JNIEnv*, jclass, jlong _address) {
    physx::PxBVH33MidphaseDesc* _self = (physx::PxBVH33MidphaseDesc*) _address;
    return (jfloat) _self->meshSizePerformanceTradeOff;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxBVH33MidphaseDesc__1setMeshSizePerformanceTradeOff(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxBVH33MidphaseDesc* _self = (physx::PxBVH33MidphaseDesc*) _address;
    _self->meshSizePerformanceTradeOff = value;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxBVH33MidphaseDesc__1getMeshCookingHint(JNIEnv*, jclass, jlong _address) {
    physx::PxBVH33MidphaseDesc* _self = (physx::PxBVH33MidphaseDesc*) _address;
    return (jint) _self->meshCookingHint;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxBVH33MidphaseDesc__1setMeshCookingHint(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxBVH33MidphaseDesc* _self = (physx::PxBVH33MidphaseDesc*) _address;
    _self->meshCookingHint = (PxMeshCookingHintEnum) value;
}

// PxBVH34MidphaseDesc
JNIEXPORT jint JNICALL Java_physx_cooking_PxBVH34MidphaseDesc__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxBVH34MidphaseDesc);
}
JNIEXPORT void JNICALL Java_physx_cooking_PxBVH34MidphaseDesc__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::PxBVH34MidphaseDesc* self = (physx::PxBVH34MidphaseDesc*) _address;
    self->setToDefault();
}
JNIEXPORT jboolean JNICALL Java_physx_cooking_PxBVH34MidphaseDesc__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxBVH34MidphaseDesc* self = (physx::PxBVH34MidphaseDesc*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_cooking_PxBVH34MidphaseDesc__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBVH34MidphaseDesc*) _address;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxBVH34MidphaseDesc__1getNumPrimsPerLeaf(JNIEnv*, jclass, jlong _address) {
    physx::PxBVH34MidphaseDesc* _self = (physx::PxBVH34MidphaseDesc*) _address;
    return (jint) _self->numPrimsPerLeaf;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxBVH34MidphaseDesc__1setNumPrimsPerLeaf(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxBVH34MidphaseDesc* _self = (physx::PxBVH34MidphaseDesc*) _address;
    _self->numPrimsPerLeaf = value;
}

// PxConvexFlags
JNIEXPORT jint JNICALL Java_physx_cooking_PxConvexFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxConvexFlags);
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxConvexFlags__1_1placement_1new_1PxConvexFlags(JNIEnv*, jclass, jlong _placement_address, jshort flags) {
    return (jlong) new((void*)_placement_address) physx::PxConvexFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxConvexFlags__1PxConvexFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxConvexFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_cooking_PxConvexFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxConvexFlags* self = (physx::PxConvexFlags*) _address;
    return (jboolean) self->isSet((PxConvexFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_cooking_PxConvexFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxConvexFlags* self = (physx::PxConvexFlags*) _address;
    self->raise((PxConvexFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_cooking_PxConvexFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxConvexFlags* self = (physx::PxConvexFlags*) _address;
    self->clear((PxConvexFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_cooking_PxConvexFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxConvexFlags*) _address;
}

// PxConvexMeshDesc
JNIEXPORT jint JNICALL Java_physx_cooking_PxConvexMeshDesc__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxConvexMeshDesc);
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxConvexMeshDesc__1_1placement_1new_1PxConvexMeshDesc(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxConvexMeshDesc();
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxConvexMeshDesc__1PxConvexMeshDesc(JNIEnv*, jclass) {
    return (jlong) new physx::PxConvexMeshDesc();
}
JNIEXPORT void JNICALL Java_physx_cooking_PxConvexMeshDesc__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxConvexMeshDesc*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxConvexMeshDesc__1getPoints(JNIEnv*, jclass, jlong _address) {
    physx::PxConvexMeshDesc* _self = (physx::PxConvexMeshDesc*) _address;
    return (jlong) &_self->points;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxConvexMeshDesc__1setPoints(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxConvexMeshDesc* _self = (physx::PxConvexMeshDesc*) _address;
    _self->points = *((physx::PxBoundedData*) value);
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxConvexMeshDesc__1getFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxConvexMeshDesc* _self = (physx::PxConvexMeshDesc*) _address;
    return (jlong) &_self->flags;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxConvexMeshDesc__1setFlags(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxConvexMeshDesc* _self = (physx::PxConvexMeshDesc*) _address;
    _self->flags = *((physx::PxConvexFlags*) value);
}

// PxCooking
JNIEXPORT jint JNICALL Java_physx_cooking_PxCooking__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxCooking);
}
JNIEXPORT void JNICALL Java_physx_cooking_PxCooking__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxCooking* self = (physx::PxCooking*) _address;
    self->release();
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxCooking__1createConvexMesh(JNIEnv*, jclass, jlong _address, jlong desc, jlong insertionCallback) {
    physx::PxCooking* self = (physx::PxCooking*) _address;
    return (jlong) self->createConvexMesh(*((physx::PxConvexMeshDesc*) desc), *((physx::PxInsertionCallback*) insertionCallback));
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxCooking__1createTriangleMesh(JNIEnv*, jclass, jlong _address, jlong desc, jlong insertionCallback) {
    physx::PxCooking* self = (physx::PxCooking*) _address;
    return (jlong) self->createTriangleMesh(*((physx::PxTriangleMeshDesc*) desc), *((physx::PxInsertionCallback*) insertionCallback));
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxCooking__1createHeightField(JNIEnv*, jclass, jlong _address, jlong desc, jlong insertionCallback) {
    physx::PxCooking* self = (physx::PxCooking*) _address;
    return (jlong) self->createHeightField(*((physx::PxHeightFieldDesc*) desc), *((physx::PxInsertionCallback*) insertionCallback));
}

// PxCookingParams
JNIEXPORT jint JNICALL Java_physx_cooking_PxCookingParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxCookingParams);
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxCookingParams__1PxCookingParams(JNIEnv*, jclass, jlong sc) {
    return (jlong) new physx::PxCookingParams(*((physx::PxTolerancesScale*) sc));
}
JNIEXPORT void JNICALL Java_physx_cooking_PxCookingParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxCookingParams*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_cooking_PxCookingParams__1getAreaTestEpsilon(JNIEnv*, jclass, jlong _address) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    return (jfloat) _self->areaTestEpsilon;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxCookingParams__1setAreaTestEpsilon(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    _self->areaTestEpsilon = value;
}
JNIEXPORT jfloat JNICALL Java_physx_cooking_PxCookingParams__1getPlaneTolerance(JNIEnv*, jclass, jlong _address) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    return (jfloat) _self->planeTolerance;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxCookingParams__1setPlaneTolerance(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    _self->planeTolerance = value;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxCookingParams__1getConvexMeshCookingType(JNIEnv*, jclass, jlong _address) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    return (jint) _self->convexMeshCookingType;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxCookingParams__1setConvexMeshCookingType(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    _self->convexMeshCookingType = (PxConvexMeshCookingTypeEnum) value;
}
JNIEXPORT jboolean JNICALL Java_physx_cooking_PxCookingParams__1getSuppressTriangleMeshRemapTable(JNIEnv*, jclass, jlong _address) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    return (jboolean) _self->suppressTriangleMeshRemapTable;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxCookingParams__1setSuppressTriangleMeshRemapTable(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    _self->suppressTriangleMeshRemapTable = value;
}
JNIEXPORT jboolean JNICALL Java_physx_cooking_PxCookingParams__1getBuildTriangleAdjacencies(JNIEnv*, jclass, jlong _address) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    return (jboolean) _self->buildTriangleAdjacencies;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxCookingParams__1setBuildTriangleAdjacencies(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    _self->buildTriangleAdjacencies = value;
}
JNIEXPORT jboolean JNICALL Java_physx_cooking_PxCookingParams__1getBuildGPUData(JNIEnv*, jclass, jlong _address) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    return (jboolean) _self->buildGPUData;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxCookingParams__1setBuildGPUData(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    _self->buildGPUData = value;
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxCookingParams__1getScale(JNIEnv*, jclass, jlong _address) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    return (jlong) &_self->scale;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxCookingParams__1setScale(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    _self->scale = *((physx::PxTolerancesScale*) value);
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxCookingParams__1getMeshPreprocessParams(JNIEnv*, jclass, jlong _address) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    return (jlong) &_self->meshPreprocessParams;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxCookingParams__1setMeshPreprocessParams(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    _self->meshPreprocessParams = *((physx::PxMeshPreprocessingFlags*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_cooking_PxCookingParams__1getMeshWeldTolerance(JNIEnv*, jclass, jlong _address) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    return (jfloat) _self->meshWeldTolerance;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxCookingParams__1setMeshWeldTolerance(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    _self->meshWeldTolerance = value;
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxCookingParams__1getMidphaseDesc(JNIEnv*, jclass, jlong _address) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    return (jlong) &_self->midphaseDesc;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxCookingParams__1setMidphaseDesc(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    _self->midphaseDesc = *((physx::PxMidphaseDesc*) value);
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxCookingParams__1getGaussMapLimit(JNIEnv*, jclass, jlong _address) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    return (jint) _self->gaussMapLimit;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxCookingParams__1setGaussMapLimit(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    _self->gaussMapLimit = value;
}

// PxMeshPreprocessingFlags
JNIEXPORT jint JNICALL Java_physx_cooking_PxMeshPreprocessingFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxMeshPreprocessingFlags);
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxMeshPreprocessingFlags__1_1placement_1new_1PxMeshPreprocessingFlags(JNIEnv*, jclass, jlong _placement_address, jint flags) {
    return (jlong) new((void*)_placement_address) physx::PxMeshPreprocessingFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxMeshPreprocessingFlags__1PxMeshPreprocessingFlags(JNIEnv*, jclass, jint flags) {
    return (jlong) new physx::PxMeshPreprocessingFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_cooking_PxMeshPreprocessingFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxMeshPreprocessingFlags* self = (physx::PxMeshPreprocessingFlags*) _address;
    return (jboolean) self->isSet((PxMeshPreprocessingFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_cooking_PxMeshPreprocessingFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxMeshPreprocessingFlags* self = (physx::PxMeshPreprocessingFlags*) _address;
    self->raise((PxMeshPreprocessingFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_cooking_PxMeshPreprocessingFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxMeshPreprocessingFlags* self = (physx::PxMeshPreprocessingFlags*) _address;
    self->clear((PxMeshPreprocessingFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_cooking_PxMeshPreprocessingFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxMeshPreprocessingFlags*) _address;
}

// PxMidphaseDesc
JNIEXPORT jint JNICALL Java_physx_cooking_PxMidphaseDesc__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxMidphaseDesc);
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxMidphaseDesc__1PxMidphaseDesc(JNIEnv*, jclass) {
    return (jlong) new physx::PxMidphaseDesc();
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxMidphaseDesc__1getType(JNIEnv*, jclass, jlong _address) {
    physx::PxMidphaseDesc* self = (physx::PxMidphaseDesc*) _address;
    return (jint) self->getType();
}
JNIEXPORT void JNICALL Java_physx_cooking_PxMidphaseDesc__1setToDefault(JNIEnv*, jclass, jlong _address, jint type) {
    physx::PxMidphaseDesc* self = (physx::PxMidphaseDesc*) _address;
    self->setToDefault((PxMeshMidPhaseEnum) type);
}
JNIEXPORT jboolean JNICALL Java_physx_cooking_PxMidphaseDesc__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxMidphaseDesc* self = (physx::PxMidphaseDesc*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_cooking_PxMidphaseDesc__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxMidphaseDesc*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxMidphaseDesc__1getMBVH33Desc(JNIEnv*, jclass, jlong _address) {
    physx::PxMidphaseDesc* _self = (physx::PxMidphaseDesc*) _address;
    return (jlong) &_self->mBVH33Desc;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxMidphaseDesc__1setMBVH33Desc(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxMidphaseDesc* _self = (physx::PxMidphaseDesc*) _address;
    _self->mBVH33Desc = *((physx::PxBVH33MidphaseDesc*) value);
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxMidphaseDesc__1getMBVH34Desc(JNIEnv*, jclass, jlong _address) {
    physx::PxMidphaseDesc* _self = (physx::PxMidphaseDesc*) _address;
    return (jlong) &_self->mBVH34Desc;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxMidphaseDesc__1setMBVH34Desc(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxMidphaseDesc* _self = (physx::PxMidphaseDesc*) _address;
    _self->mBVH34Desc = *((physx::PxBVH34MidphaseDesc*) value);
}

// PxTriangleMeshDesc
JNIEXPORT jint JNICALL Java_physx_cooking_PxTriangleMeshDesc__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxTriangleMeshDesc);
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxTriangleMeshDesc__1_1placement_1new_1PxTriangleMeshDesc(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxTriangleMeshDesc();
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxTriangleMeshDesc__1PxTriangleMeshDesc(JNIEnv*, jclass) {
    return (jlong) new physx::PxTriangleMeshDesc();
}
JNIEXPORT void JNICALL Java_physx_cooking_PxTriangleMeshDesc__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxTriangleMeshDesc*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxTriangleMeshDesc__1getMaterialIndices(JNIEnv*, jclass, jlong _address) {
    physx::PxTriangleMeshDesc* _self = (physx::PxTriangleMeshDesc*) _address;
    return (jlong) &_self->materialIndices;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxTriangleMeshDesc__1setMaterialIndices(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxTriangleMeshDesc* _self = (physx::PxTriangleMeshDesc*) _address;
    _self->materialIndices = *((PxU16StridedData*) value);
}

// PxConvexFlagEnum
JNIEXPORT jint JNICALL Java_physx_cooking_PxConvexFlagEnum__1gete16_1BIT_1INDICES(JNIEnv*, jclass) {
    return PxConvexFlagEnum::e16_BIT_INDICES;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxConvexFlagEnum__1geteCOMPUTE_1CONVEX(JNIEnv*, jclass) {
    return PxConvexFlagEnum::eCOMPUTE_CONVEX;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxConvexFlagEnum__1geteCHECK_1ZERO_1AREA_1TRIANGLES(JNIEnv*, jclass) {
    return PxConvexFlagEnum::eCHECK_ZERO_AREA_TRIANGLES;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxConvexFlagEnum__1geteQUANTIZE_1INPUT(JNIEnv*, jclass) {
    return PxConvexFlagEnum::eQUANTIZE_INPUT;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxConvexFlagEnum__1geteDISABLE_1MESH_1VALIDATION(JNIEnv*, jclass) {
    return PxConvexFlagEnum::eDISABLE_MESH_VALIDATION;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxConvexFlagEnum__1getePLANE_1SHIFTING(JNIEnv*, jclass) {
    return PxConvexFlagEnum::ePLANE_SHIFTING;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxConvexFlagEnum__1geteFAST_1INERTIA_1COMPUTATION(JNIEnv*, jclass) {
    return PxConvexFlagEnum::eFAST_INERTIA_COMPUTATION;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxConvexFlagEnum__1geteGPU_1COMPATIBLE(JNIEnv*, jclass) {
    return PxConvexFlagEnum::eGPU_COMPATIBLE;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxConvexFlagEnum__1geteSHIFT_1VERTICES(JNIEnv*, jclass) {
    return PxConvexFlagEnum::eSHIFT_VERTICES;
}

// PxConvexMeshCookingTypeEnum
JNIEXPORT jint JNICALL Java_physx_cooking_PxConvexMeshCookingTypeEnum__1geteQUICKHULL(JNIEnv*, jclass) {
    return PxConvexMeshCookingTypeEnum::eQUICKHULL;
}

// PxMeshCookingHintEnum
JNIEXPORT jint JNICALL Java_physx_cooking_PxMeshCookingHintEnum__1geteSIM_1PERFORMANCE(JNIEnv*, jclass) {
    return PxMeshCookingHintEnum::eSIM_PERFORMANCE;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxMeshCookingHintEnum__1geteCOOKING_1PERFORMANCE(JNIEnv*, jclass) {
    return PxMeshCookingHintEnum::eCOOKING_PERFORMANCE;
}

// PxMeshPreprocessingFlagEnum
JNIEXPORT jint JNICALL Java_physx_cooking_PxMeshPreprocessingFlagEnum__1geteWELD_1VERTICES(JNIEnv*, jclass) {
    return PxMeshPreprocessingFlagEnum::eWELD_VERTICES;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxMeshPreprocessingFlagEnum__1geteDISABLE_1CLEAN_1MESH(JNIEnv*, jclass) {
    return PxMeshPreprocessingFlagEnum::eDISABLE_CLEAN_MESH;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxMeshPreprocessingFlagEnum__1geteDISABLE_1ACTIVE_1EDGES_1PRECOMPUTE(JNIEnv*, jclass) {
    return PxMeshPreprocessingFlagEnum::eDISABLE_ACTIVE_EDGES_PRECOMPUTE;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxMeshPreprocessingFlagEnum__1geteFORCE_132BIT_1INDICES(JNIEnv*, jclass) {
    return PxMeshPreprocessingFlagEnum::eFORCE_32BIT_INDICES;
}

// PxMeshMidPhaseEnum
JNIEXPORT jint JNICALL Java_physx_cooking_PxMeshMidPhaseEnum__1geteBVH33(JNIEnv*, jclass) {
    return PxMeshMidPhaseEnum::eBVH33;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxMeshMidPhaseEnum__1geteBVH34(JNIEnv*, jclass) {
    return PxMeshMidPhaseEnum::eBVH34;
}

// PxCollectionExt
JNIEXPORT jint JNICALL Java_physx_extensions_PxCollectionExt__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxCollectionExt);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxCollectionExt__1releaseObjects__J(JNIEnv*, jclass, jlong collection) {
    physx::PxCollectionExt::releaseObjects(*((physx::PxCollection*) collection));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxCollectionExt__1releaseObjects__JZ(JNIEnv*, jclass, jlong collection, jboolean releaseExclusiveShapes) {
    physx::PxCollectionExt::releaseObjects(*((physx::PxCollection*) collection), releaseExclusiveShapes);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxCollectionExt__1remove__JS(JNIEnv*, jclass, jlong collection, jshort concreteType) {
    physx::PxCollectionExt::remove(*((physx::PxCollection*) collection), concreteType);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxCollectionExt__1remove__JSJ(JNIEnv*, jclass, jlong collection, jshort concreteType, jlong to) {
    physx::PxCollectionExt::remove(*((physx::PxCollection*) collection), concreteType, (physx::PxCollection*) to);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxCollectionExt__1createCollection(JNIEnv*, jclass, jlong scene) {
    return (jlong) physx::PxCollectionExt::createCollection(*((physx::PxScene*) scene));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxCollectionExt__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxCollectionExt*) _address;
}

// PxDefaultMemoryInputData
JNIEXPORT jint JNICALL Java_physx_extensions_PxDefaultMemoryInputData__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxDefaultMemoryInputData);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxDefaultMemoryInputData__1PxDefaultMemoryInputData(JNIEnv*, jclass, jlong data, jint length) {
    return (jlong) new physx::PxDefaultMemoryInputData(*((PxU8Ptr*) data), length);
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxDefaultMemoryInputData__1read(JNIEnv*, jclass, jlong _address, jlong dest, jint count) {
    physx::PxDefaultMemoryInputData* self = (physx::PxDefaultMemoryInputData*) _address;
    return (jint) self->read((void*) dest, count);
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxDefaultMemoryInputData__1getLength(JNIEnv*, jclass, jlong _address) {
    physx::PxDefaultMemoryInputData* self = (physx::PxDefaultMemoryInputData*) _address;
    return (jint) self->getLength();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDefaultMemoryInputData__1seek(JNIEnv*, jclass, jlong _address, jint pos) {
    physx::PxDefaultMemoryInputData* self = (physx::PxDefaultMemoryInputData*) _address;
    self->seek(pos);
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxDefaultMemoryInputData__1tell(JNIEnv*, jclass, jlong _address) {
    physx::PxDefaultMemoryInputData* self = (physx::PxDefaultMemoryInputData*) _address;
    return (jint) self->tell();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDefaultMemoryInputData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxDefaultMemoryInputData*) _address;
}

// PxDefaultMemoryOutputStream
JNIEXPORT jint JNICALL Java_physx_extensions_PxDefaultMemoryOutputStream__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxDefaultMemoryOutputStream);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxDefaultMemoryOutputStream__1PxDefaultMemoryOutputStream(JNIEnv*, jclass) {
    return (jlong) new physx::PxDefaultMemoryOutputStream();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDefaultMemoryOutputStream__1write(JNIEnv*, jclass, jlong _address, jlong src, jint count) {
    physx::PxDefaultMemoryOutputStream* self = (physx::PxDefaultMemoryOutputStream*) _address;
    self->write((void*) src, count);
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxDefaultMemoryOutputStream__1getSize(JNIEnv*, jclass, jlong _address) {
    physx::PxDefaultMemoryOutputStream* self = (physx::PxDefaultMemoryOutputStream*) _address;
    return (jint) self->getSize();
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxDefaultMemoryOutputStream__1getData(JNIEnv*, jclass, jlong _address) {
    physx::PxDefaultMemoryOutputStream* self = (physx::PxDefaultMemoryOutputStream*) _address;
    return (jlong) self->getData();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDefaultMemoryOutputStream__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxDefaultMemoryOutputStream*) _address;
}

// PxMassProperties
JNIEXPORT jint JNICALL Java_physx_extensions_PxMassProperties__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxMassProperties);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxMassProperties__1PxMassProperties__(JNIEnv*, jclass) {
    return (jlong) new physx::PxMassProperties();
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxMassProperties__1PxMassProperties__FJJ(JNIEnv*, jclass, jfloat m, jlong inertiaT, jlong com) {
    return (jlong) new physx::PxMassProperties(m, *((physx::PxMat33*) inertiaT), *((physx::PxVec3*) com));
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxMassProperties__1PxMassProperties__J(JNIEnv*, jclass, jlong geometry) {
    return (jlong) new physx::PxMassProperties(*((physx::PxGeometry*) geometry));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxMassProperties__1translate(JNIEnv*, jclass, jlong _address, jlong t) {
    physx::PxMassProperties* self = (physx::PxMassProperties*) _address;
    self->translate(*((physx::PxVec3*) t));
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxMassProperties__1getMassSpaceInertia(JNIEnv*, jclass, jlong inertia, jlong massFrame) {
    static thread_local physx::PxVec3 _cache = physx::PxMassProperties::getMassSpaceInertia(*((physx::PxMat33*) inertia), *((physx::PxQuat*) massFrame));
    _cache = physx::PxMassProperties::getMassSpaceInertia(*((physx::PxMat33*) inertia), *((physx::PxQuat*) massFrame));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxMassProperties__1translateInertia(JNIEnv*, jclass, jlong inertia, jfloat mass, jlong t) {
    static thread_local physx::PxMat33 _cache = physx::PxMassProperties::translateInertia(*((physx::PxMat33*) inertia), mass, *((physx::PxVec3*) t));
    _cache = physx::PxMassProperties::translateInertia(*((physx::PxMat33*) inertia), mass, *((physx::PxVec3*) t));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxMassProperties__1rotateInertia(JNIEnv*, jclass, jlong inertia, jlong q) {
    static thread_local physx::PxMat33 _cache = physx::PxMassProperties::rotateInertia(*((physx::PxMat33*) inertia), *((physx::PxQuat*) q));
    _cache = physx::PxMassProperties::rotateInertia(*((physx::PxMat33*) inertia), *((physx::PxQuat*) q));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxMassProperties__1scaleInertia(JNIEnv*, jclass, jlong inertia, jlong scaleRotation, jlong scale) {
    static thread_local physx::PxMat33 _cache = physx::PxMassProperties::scaleInertia(*((physx::PxMat33*) inertia), *((physx::PxQuat*) scaleRotation), *((physx::PxVec3*) scale));
    _cache = physx::PxMassProperties::scaleInertia(*((physx::PxMat33*) inertia), *((physx::PxQuat*) scaleRotation), *((physx::PxVec3*) scale));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxMassProperties__1sum(JNIEnv*, jclass, jlong props, jlong transforms, jint count) {
    static thread_local physx::PxMassProperties _cache = physx::PxMassProperties::sum((physx::PxMassProperties*) props, (physx::PxTransform*) transforms, count);
    _cache = physx::PxMassProperties::sum((physx::PxMassProperties*) props, (physx::PxTransform*) transforms, count);
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxMassProperties__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxMassProperties*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxMassProperties__1getInertiaTensor(JNIEnv*, jclass, jlong _address) {
    physx::PxMassProperties* _self = (physx::PxMassProperties*) _address;
    return (jlong) &_self->inertiaTensor;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxMassProperties__1setInertiaTensor(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxMassProperties* _self = (physx::PxMassProperties*) _address;
    _self->inertiaTensor = *((physx::PxMat33*) value);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxMassProperties__1getCenterOfMass(JNIEnv*, jclass, jlong _address) {
    physx::PxMassProperties* _self = (physx::PxMassProperties*) _address;
    return (jlong) &_self->centerOfMass;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxMassProperties__1setCenterOfMass(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxMassProperties* _self = (physx::PxMassProperties*) _address;
    _self->centerOfMass = *((physx::PxVec3*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxMassProperties__1getMass(JNIEnv*, jclass, jlong _address) {
    physx::PxMassProperties* _self = (physx::PxMassProperties*) _address;
    return (jfloat) _self->mass;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxMassProperties__1setMass(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxMassProperties* _self = (physx::PxMassProperties*) _address;
    _self->mass = value;
}

// PxMeshOverlapUtil
JNIEXPORT jint JNICALL Java_physx_extensions_PxMeshOverlapUtil__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxMeshOverlapUtil);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxMeshOverlapUtil__1PxMeshOverlapUtil(JNIEnv*, jclass) {
    return (jlong) new physx::PxMeshOverlapUtil();
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxMeshOverlapUtil__1findOverlap(JNIEnv*, jclass, jlong _address, jlong geom, jlong geomPose, jlong meshGeom, jlong meshPose) {
    physx::PxMeshOverlapUtil* self = (physx::PxMeshOverlapUtil*) _address;
    return (jint) self->findOverlap(*((physx::PxGeometry*) geom), *((physx::PxTransform*) geomPose), *((physx::PxTriangleMeshGeometry*) meshGeom), *((physx::PxTransform*) meshPose));
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxMeshOverlapUtil__1getResults(JNIEnv*, jclass, jlong _address) {
    physx::PxMeshOverlapUtil* self = (physx::PxMeshOverlapUtil*) _address;
    static thread_local PxU32ConstPtr _cache = self->getResults();
    _cache = self->getResults();
    return (jlong) &_cache;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxMeshOverlapUtil__1getNbResults(JNIEnv*, jclass, jlong _address) {
    physx::PxMeshOverlapUtil* self = (physx::PxMeshOverlapUtil*) _address;
    return (jint) self->getNbResults();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxMeshOverlapUtil__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxMeshOverlapUtil*) _address;
}

// PxRigidActorExt
JNIEXPORT jint JNICALL Java_physx_extensions_PxRigidActorExt__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxRigidActorExt);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxRigidActorExt__1createExclusiveShape__JJJ(JNIEnv*, jclass, jlong actor, jlong geometry, jlong material) {
    return (jlong) physx::PxRigidActorExt::createExclusiveShape(*((physx::PxRigidActor*) actor), *((physx::PxGeometry*) geometry), *((physx::PxMaterial*) material));
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxRigidActorExt__1createExclusiveShape__JJJJ(JNIEnv*, jclass, jlong actor, jlong geometry, jlong material, jlong flags) {
    return (jlong) physx::PxRigidActorExt::createExclusiveShape(*((physx::PxRigidActor*) actor), *((physx::PxGeometry*) geometry), *((physx::PxMaterial*) material), *((physx::PxShapeFlags*) flags));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidActorExt__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxRigidActorExt*) _address;
}

// PxRigidBodyExt
JNIEXPORT jint JNICALL Java_physx_extensions_PxRigidBodyExt__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxRigidBodyExt);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxRigidBodyExt__1updateMassAndInertia__JF(JNIEnv*, jclass, jlong body, jfloat density) {
    return (jboolean) physx::PxRigidBodyExt::updateMassAndInertia(*((physx::PxRigidBody*) body), density);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxRigidBodyExt__1updateMassAndInertia__JFJ(JNIEnv*, jclass, jlong body, jfloat density, jlong massLocalPose) {
    return (jboolean) physx::PxRigidBodyExt::updateMassAndInertia(*((physx::PxRigidBody*) body), density, (physx::PxVec3*) massLocalPose);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxRigidBodyExt__1updateMassAndInertia__JFJZ(JNIEnv*, jclass, jlong body, jfloat density, jlong massLocalPose, jboolean includeNonSimShapes) {
    return (jboolean) physx::PxRigidBodyExt::updateMassAndInertia(*((physx::PxRigidBody*) body), density, (physx::PxVec3*) massLocalPose, includeNonSimShapes);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxRigidBodyExt__1setMassAndUpdateInertia__JF(JNIEnv*, jclass, jlong body, jfloat mass) {
    return (jboolean) physx::PxRigidBodyExt::setMassAndUpdateInertia(*((physx::PxRigidBody*) body), mass);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxRigidBodyExt__1setMassAndUpdateInertia__JFJ(JNIEnv*, jclass, jlong body, jfloat mass, jlong massLocalPose) {
    return (jboolean) physx::PxRigidBodyExt::setMassAndUpdateInertia(*((physx::PxRigidBody*) body), mass, (physx::PxVec3*) massLocalPose);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxRigidBodyExt__1setMassAndUpdateInertia__JFJZ(JNIEnv*, jclass, jlong body, jfloat mass, jlong massLocalPose, jboolean includeNonSimShapes) {
    return (jboolean) physx::PxRigidBodyExt::setMassAndUpdateInertia(*((physx::PxRigidBody*) body), mass, (physx::PxVec3*) massLocalPose, includeNonSimShapes);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1addForceAtPos__JJJ(JNIEnv*, jclass, jlong body, jlong force, jlong pos) {
    physx::PxRigidBodyExt::addForceAtPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) force), *((physx::PxVec3*) pos));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1addForceAtPos__JJJI(JNIEnv*, jclass, jlong body, jlong force, jlong pos, jint mode) {
    physx::PxRigidBodyExt::addForceAtPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) force), *((physx::PxVec3*) pos), (PxForceModeEnum) mode);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1addForceAtPos__JJJIZ(JNIEnv*, jclass, jlong body, jlong force, jlong pos, jint mode, jboolean wakeup) {
    physx::PxRigidBodyExt::addForceAtPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) force), *((physx::PxVec3*) pos), (PxForceModeEnum) mode, wakeup);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1addForceAtLocalPos__JJJ(JNIEnv*, jclass, jlong body, jlong force, jlong pos) {
    physx::PxRigidBodyExt::addForceAtLocalPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) force), *((physx::PxVec3*) pos));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1addForceAtLocalPos__JJJI(JNIEnv*, jclass, jlong body, jlong force, jlong pos, jint mode) {
    physx::PxRigidBodyExt::addForceAtLocalPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) force), *((physx::PxVec3*) pos), (PxForceModeEnum) mode);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1addForceAtLocalPos__JJJIZ(JNIEnv*, jclass, jlong body, jlong force, jlong pos, jint mode, jboolean wakeup) {
    physx::PxRigidBodyExt::addForceAtLocalPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) force), *((physx::PxVec3*) pos), (PxForceModeEnum) mode, wakeup);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1addLocalForceAtPos__JJJ(JNIEnv*, jclass, jlong body, jlong force, jlong pos) {
    physx::PxRigidBodyExt::addLocalForceAtPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) force), *((physx::PxVec3*) pos));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1addLocalForceAtPos__JJJI(JNIEnv*, jclass, jlong body, jlong force, jlong pos, jint mode) {
    physx::PxRigidBodyExt::addLocalForceAtPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) force), *((physx::PxVec3*) pos), (PxForceModeEnum) mode);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1addLocalForceAtPos__JJJIZ(JNIEnv*, jclass, jlong body, jlong force, jlong pos, jint mode, jboolean wakeup) {
    physx::PxRigidBodyExt::addLocalForceAtPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) force), *((physx::PxVec3*) pos), (PxForceModeEnum) mode, wakeup);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1addLocalForceAtLocalPos__JJJ(JNIEnv*, jclass, jlong body, jlong force, jlong pos) {
    physx::PxRigidBodyExt::addLocalForceAtLocalPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) force), *((physx::PxVec3*) pos));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1addLocalForceAtLocalPos__JJJI(JNIEnv*, jclass, jlong body, jlong force, jlong pos, jint mode) {
    physx::PxRigidBodyExt::addLocalForceAtLocalPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) force), *((physx::PxVec3*) pos), (PxForceModeEnum) mode);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1addLocalForceAtLocalPos__JJJIZ(JNIEnv*, jclass, jlong body, jlong force, jlong pos, jint mode, jboolean wakeup) {
    physx::PxRigidBodyExt::addLocalForceAtLocalPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) force), *((physx::PxVec3*) pos), (PxForceModeEnum) mode, wakeup);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxRigidBodyExt__1getVelocityAtPos(JNIEnv*, jclass, jlong body, jlong pos) {
    static thread_local physx::PxVec3 _cache = physx::PxRigidBodyExt::getVelocityAtPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) pos));
    _cache = physx::PxRigidBodyExt::getVelocityAtPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) pos));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxRigidBodyExt__1getLocalVelocityAtLocalPos(JNIEnv*, jclass, jlong body, jlong pos) {
    static thread_local physx::PxVec3 _cache = physx::PxRigidBodyExt::getLocalVelocityAtLocalPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) pos));
    _cache = physx::PxRigidBodyExt::getLocalVelocityAtLocalPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) pos));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxRigidBodyExt__1getVelocityAtOffset(JNIEnv*, jclass, jlong body, jlong pos) {
    static thread_local physx::PxVec3 _cache = physx::PxRigidBodyExt::getVelocityAtOffset(*((physx::PxRigidBody*) body), *((physx::PxVec3*) pos));
    _cache = physx::PxRigidBodyExt::getVelocityAtOffset(*((physx::PxRigidBody*) body), *((physx::PxVec3*) pos));
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1computeVelocityDeltaFromImpulse__JJJJJ(JNIEnv*, jclass, jlong body, jlong impulsiveForce, jlong impulsiveTorque, jlong deltaLinearVelocity, jlong deltaAngularVelocity) {
    physx::PxRigidBodyExt::computeVelocityDeltaFromImpulse(*((physx::PxRigidBody*) body), *((physx::PxVec3*) impulsiveForce), *((physx::PxVec3*) impulsiveTorque), *((physx::PxVec3*) deltaLinearVelocity), *((physx::PxVec3*) deltaAngularVelocity));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1computeVelocityDeltaFromImpulse__JJJJFFJJ(JNIEnv*, jclass, jlong body, jlong globalPose, jlong point, jlong impulse, jfloat invMassScale, jfloat invInertiaScale, jlong deltaLinearVelocity, jlong deltaAngularVelocity) {
    physx::PxRigidBodyExt::computeVelocityDeltaFromImpulse(*((physx::PxRigidBody*) body), *((physx::PxTransform*) globalPose), *((physx::PxVec3*) point), *((physx::PxVec3*) impulse), invMassScale, invInertiaScale, *((physx::PxVec3*) deltaLinearVelocity), *((physx::PxVec3*) deltaAngularVelocity));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1computeLinearAngularImpulse(JNIEnv*, jclass, jlong body, jlong globalPose, jlong point, jlong impulse, jfloat invMassScale, jfloat invInertiaScale, jlong linearImpulse, jlong angularImpulse) {
    physx::PxRigidBodyExt::computeLinearAngularImpulse(*((physx::PxRigidBody*) body), *((physx::PxTransform*) globalPose), *((physx::PxVec3*) point), *((physx::PxVec3*) impulse), invMassScale, invInertiaScale, *((physx::PxVec3*) linearImpulse), *((physx::PxVec3*) angularImpulse));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxRigidBodyExt*) _address;
}

// PxSerialization
JNIEXPORT jint JNICALL Java_physx_extensions_PxSerialization__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxSerialization);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxSerialization__1isSerializable__JJ(JNIEnv*, jclass, jlong collection, jlong sr) {
    return (jboolean) physx::PxSerialization::isSerializable(*((physx::PxCollection*) collection), *((physx::PxSerializationRegistry*) sr));
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxSerialization__1isSerializable__JJJ(JNIEnv*, jclass, jlong collection, jlong sr, jlong externalReferences) {
    return (jboolean) physx::PxSerialization::isSerializable(*((physx::PxCollection*) collection), *((physx::PxSerializationRegistry*) sr), (physx::PxCollection*) externalReferences);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxSerialization__1complete__JJ(JNIEnv*, jclass, jlong collection, jlong sr) {
    physx::PxSerialization::complete(*((physx::PxCollection*) collection), *((physx::PxSerializationRegistry*) sr));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxSerialization__1complete__JJJ(JNIEnv*, jclass, jlong collection, jlong sr, jlong exceptFor) {
    physx::PxSerialization::complete(*((physx::PxCollection*) collection), *((physx::PxSerializationRegistry*) sr), (physx::PxCollection*) exceptFor);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxSerialization__1complete__JJJZ(JNIEnv*, jclass, jlong collection, jlong sr, jlong exceptFor, jboolean followJoints) {
    physx::PxSerialization::complete(*((physx::PxCollection*) collection), *((physx::PxSerializationRegistry*) sr), (physx::PxCollection*) exceptFor, followJoints);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxSerialization__1createSerialObjectIds(JNIEnv*, jclass, jlong collection, jlong base) {
    physx::PxSerialization::createSerialObjectIds(*((physx::PxCollection*) collection), base);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxSerialization__1createCollectionFromXml__JJJ(JNIEnv*, jclass, jlong inputData, jlong cooking, jlong sr) {
    return (jlong) physx::PxSerialization::createCollectionFromXml(*((physx::PxInputData*) inputData), *((physx::PxCooking*) cooking), *((physx::PxSerializationRegistry*) sr));
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxSerialization__1createCollectionFromXml__JJJJ(JNIEnv*, jclass, jlong inputData, jlong cooking, jlong sr, jlong externalRefs) {
    return (jlong) physx::PxSerialization::createCollectionFromXml(*((physx::PxInputData*) inputData), *((physx::PxCooking*) cooking), *((physx::PxSerializationRegistry*) sr), (physx::PxCollection*) externalRefs);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxSerialization__1createCollectionFromBinary__JJ(JNIEnv*, jclass, jlong memBlock, jlong sr) {
    return (jlong) physx::PxSerialization::createCollectionFromBinary((void*) memBlock, *((physx::PxSerializationRegistry*) sr));
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxSerialization__1createCollectionFromBinary__JJJ(JNIEnv*, jclass, jlong memBlock, jlong sr, jlong externalRefs) {
    return (jlong) physx::PxSerialization::createCollectionFromBinary((void*) memBlock, *((physx::PxSerializationRegistry*) sr), (physx::PxCollection*) externalRefs);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxSerialization__1serializeCollectionToXml__JJJ(JNIEnv*, jclass, jlong outputStream, jlong collection, jlong sr) {
    return (jboolean) physx::PxSerialization::serializeCollectionToXml(*((physx::PxOutputStream*) outputStream), *((physx::PxCollection*) collection), *((physx::PxSerializationRegistry*) sr));
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxSerialization__1serializeCollectionToXml__JJJJ(JNIEnv*, jclass, jlong outputStream, jlong collection, jlong sr, jlong cooking) {
    return (jboolean) physx::PxSerialization::serializeCollectionToXml(*((physx::PxOutputStream*) outputStream), *((physx::PxCollection*) collection), *((physx::PxSerializationRegistry*) sr), (physx::PxCooking*) cooking);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxSerialization__1serializeCollectionToXml__JJJJJ(JNIEnv*, jclass, jlong outputStream, jlong collection, jlong sr, jlong cooking, jlong externalRefs) {
    return (jboolean) physx::PxSerialization::serializeCollectionToXml(*((physx::PxOutputStream*) outputStream), *((physx::PxCollection*) collection), *((physx::PxSerializationRegistry*) sr), (physx::PxCooking*) cooking, (physx::PxCollection*) externalRefs);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxSerialization__1serializeCollectionToBinary__JJJ(JNIEnv*, jclass, jlong outputStream, jlong collection, jlong sr) {
    return (jboolean) physx::PxSerialization::serializeCollectionToBinary(*((physx::PxOutputStream*) outputStream), *((physx::PxCollection*) collection), *((physx::PxSerializationRegistry*) sr));
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxSerialization__1serializeCollectionToBinary__JJJJ(JNIEnv*, jclass, jlong outputStream, jlong collection, jlong sr, jlong externalRefs) {
    return (jboolean) physx::PxSerialization::serializeCollectionToBinary(*((physx::PxOutputStream*) outputStream), *((physx::PxCollection*) collection), *((physx::PxSerializationRegistry*) sr), (physx::PxCollection*) externalRefs);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxSerialization__1serializeCollectionToBinary__JJJJZ(JNIEnv*, jclass, jlong outputStream, jlong collection, jlong sr, jlong externalRefs, jboolean exportNames) {
    return (jboolean) physx::PxSerialization::serializeCollectionToBinary(*((physx::PxOutputStream*) outputStream), *((physx::PxCollection*) collection), *((physx::PxSerializationRegistry*) sr), (physx::PxCollection*) externalRefs, exportNames);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxSerialization__1createSerializationRegistry(JNIEnv*, jclass, jlong physics) {
    return (jlong) physx::PxSerialization::createSerializationRegistry(*((physx::PxPhysics*) physics));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxSerialization__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSerialization*) _address;
}

// PxSerializationRegistry
JNIEXPORT jint JNICALL Java_physx_extensions_PxSerializationRegistry__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxSerializationRegistry);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxSerializationRegistry__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxSerializationRegistry* self = (physx::PxSerializationRegistry*) _address;
    self->release();
}

// PxD6Joint
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6Joint__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxD6Joint);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1setMotion(JNIEnv*, jclass, jlong _address, jint axis, jint type) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    self->setMotion((PxD6AxisEnum) axis, (PxD6MotionEnum) type);
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6Joint__1getMotion(JNIEnv*, jclass, jlong _address, jint axis) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    return (jint) self->getMotion((PxD6AxisEnum) axis);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxD6Joint__1getTwistAngle(JNIEnv*, jclass, jlong _address) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    return (jfloat) self->getTwistAngle();
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxD6Joint__1getSwingYAngle(JNIEnv*, jclass, jlong _address) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    return (jfloat) self->getSwingYAngle();
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxD6Joint__1getSwingZAngle(JNIEnv*, jclass, jlong _address) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    return (jfloat) self->getSwingZAngle();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1setDistanceLimit(JNIEnv*, jclass, jlong _address, jlong limit) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    self->setDistanceLimit(*((physx::PxJointLinearLimit*) limit));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1setLinearLimit(JNIEnv*, jclass, jlong _address, jint axis, jlong limit) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    self->setLinearLimit((PxD6AxisEnum) axis, *((physx::PxJointLinearLimitPair*) limit));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1setTwistLimit(JNIEnv*, jclass, jlong _address, jlong limit) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    self->setTwistLimit(*((physx::PxJointAngularLimitPair*) limit));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1setSwingLimit(JNIEnv*, jclass, jlong _address, jlong limit) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    self->setSwingLimit(*((physx::PxJointLimitCone*) limit));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1setPyramidSwingLimit(JNIEnv*, jclass, jlong _address, jlong limit) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    self->setPyramidSwingLimit(*((physx::PxJointLimitPyramid*) limit));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1setDrive(JNIEnv*, jclass, jlong _address, jint index, jlong drive) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    self->setDrive((PxD6DriveEnum) index, *((physx::PxD6JointDrive*) drive));
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxD6Joint__1getDrive(JNIEnv*, jclass, jlong _address, jint index) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    static thread_local physx::PxD6JointDrive _cache = self->getDrive((PxD6DriveEnum) index);
    _cache = self->getDrive((PxD6DriveEnum) index);
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1setDrivePosition__JJ(JNIEnv*, jclass, jlong _address, jlong pose) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    self->setDrivePosition(*((physx::PxTransform*) pose));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1setDrivePosition__JJZ(JNIEnv*, jclass, jlong _address, jlong pose, jboolean autowake) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    self->setDrivePosition(*((physx::PxTransform*) pose), autowake);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxD6Joint__1getDrivePosition(JNIEnv*, jclass, jlong _address) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    static thread_local physx::PxTransform _cache = self->getDrivePosition();
    _cache = self->getDrivePosition();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1setDriveVelocity(JNIEnv*, jclass, jlong _address, jlong linear, jlong angular) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    self->setDriveVelocity(*((physx::PxVec3*) linear), *((physx::PxVec3*) angular));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1getDriveVelocity(JNIEnv*, jclass, jlong _address, jlong linear, jlong angular) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    self->getDriveVelocity(*((physx::PxVec3*) linear), *((physx::PxVec3*) angular));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1setProjectionLinearTolerance(JNIEnv*, jclass, jlong _address, jfloat tolerance) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    self->setProjectionLinearTolerance(tolerance);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxD6Joint__1getProjectionLinearTolerance(JNIEnv*, jclass, jlong _address) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    return (jfloat) self->getProjectionLinearTolerance();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1setProjectionAngularTolerance(JNIEnv*, jclass, jlong _address, jfloat tolerance) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    self->setProjectionAngularTolerance(tolerance);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxD6Joint__1getProjectionAngularTolerance(JNIEnv*, jclass, jlong _address) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    return (jfloat) self->getProjectionAngularTolerance();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxD6Joint*) _address;
}

// PxD6JointDrive
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6JointDrive__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxD6JointDrive);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxD6JointDrive__1PxD6JointDrive__(JNIEnv*, jclass) {
    return (jlong) new physx::PxD6JointDrive();
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxD6JointDrive__1PxD6JointDrive__FFF(JNIEnv*, jclass, jfloat driveStiffness, jfloat driveDamping, jfloat driveForceLimit) {
    return (jlong) new physx::PxD6JointDrive(driveStiffness, driveDamping, driveForceLimit);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxD6JointDrive__1PxD6JointDrive__FFFZ(JNIEnv*, jclass, jfloat driveStiffness, jfloat driveDamping, jfloat driveForceLimit, jboolean isAcceleration) {
    return (jlong) new physx::PxD6JointDrive(driveStiffness, driveDamping, driveForceLimit, isAcceleration);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6JointDrive__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxD6JointDrive*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxD6JointDrive__1getForceLimit(JNIEnv*, jclass, jlong _address) {
    physx::PxD6JointDrive* _self = (physx::PxD6JointDrive*) _address;
    return (jfloat) _self->forceLimit;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6JointDrive__1setForceLimit(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxD6JointDrive* _self = (physx::PxD6JointDrive*) _address;
    _self->forceLimit = value;
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxD6JointDrive__1getFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxD6JointDrive* _self = (physx::PxD6JointDrive*) _address;
    return (jlong) &_self->flags;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6JointDrive__1setFlags(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxD6JointDrive* _self = (physx::PxD6JointDrive*) _address;
    _self->flags = *((physx::PxD6JointDriveFlags*) value);
}

// PxD6JointDriveFlags
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6JointDriveFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxD6JointDriveFlags);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxD6JointDriveFlags__1_1placement_1new_1PxD6JointDriveFlags(JNIEnv*, jclass, jlong _placement_address, jint flags) {
    return (jlong) new((void*)_placement_address) physx::PxD6JointDriveFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxD6JointDriveFlags__1PxD6JointDriveFlags(JNIEnv*, jclass, jint flags) {
    return (jlong) new physx::PxD6JointDriveFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxD6JointDriveFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxD6JointDriveFlags* self = (physx::PxD6JointDriveFlags*) _address;
    return (jboolean) self->isSet((PxD6JointDriveFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6JointDriveFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxD6JointDriveFlags* self = (physx::PxD6JointDriveFlags*) _address;
    self->raise((PxD6JointDriveFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6JointDriveFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxD6JointDriveFlags* self = (physx::PxD6JointDriveFlags*) _address;
    self->clear((PxD6JointDriveFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6JointDriveFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxD6JointDriveFlags*) _address;
}

// PxDistanceJoint
JNIEXPORT jint JNICALL Java_physx_extensions_PxDistanceJoint__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxDistanceJoint);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxDistanceJoint__1getDistance(JNIEnv*, jclass, jlong _address) {
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    return (jfloat) self->getDistance();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDistanceJoint__1setMinDistance(JNIEnv*, jclass, jlong _address, jfloat distance) {
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    self->setMinDistance(distance);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxDistanceJoint__1getMinDistance(JNIEnv*, jclass, jlong _address) {
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    return (jfloat) self->getMinDistance();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDistanceJoint__1setMaxDistance(JNIEnv*, jclass, jlong _address, jfloat distance) {
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    self->setMaxDistance(distance);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxDistanceJoint__1getMaxDistance(JNIEnv*, jclass, jlong _address) {
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    return (jfloat) self->getMaxDistance();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDistanceJoint__1setTolerance(JNIEnv*, jclass, jlong _address, jfloat tolerance) {
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    self->setTolerance(tolerance);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxDistanceJoint__1getTolerance(JNIEnv*, jclass, jlong _address) {
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    return (jfloat) self->getTolerance();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDistanceJoint__1setStiffness(JNIEnv*, jclass, jlong _address, jfloat stiffness) {
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    self->setStiffness(stiffness);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxDistanceJoint__1getStiffness(JNIEnv*, jclass, jlong _address) {
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    return (jfloat) self->getStiffness();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDistanceJoint__1setDamping(JNIEnv*, jclass, jlong _address, jfloat damping) {
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    self->setDamping(damping);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxDistanceJoint__1getDamping(JNIEnv*, jclass, jlong _address) {
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    return (jfloat) self->getDamping();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDistanceJoint__1setDistanceJointFlags(JNIEnv*, jclass, jlong _address, jlong flags) {
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    self->setDistanceJointFlags(*((physx::PxDistanceJointFlags*) flags));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDistanceJoint__1setDistanceJointFlag(JNIEnv*, jclass, jlong _address, jint flag, jboolean value) {
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    self->setDistanceJointFlag((PxDistanceJointFlagEnum) flag, value);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxDistanceJoint__1getDistanceJointFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    static thread_local physx::PxDistanceJointFlags _cache = self->getDistanceJointFlags();
    _cache = self->getDistanceJointFlags();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDistanceJoint__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxDistanceJoint*) _address;
}

// PxDistanceJointFlags
JNIEXPORT jint JNICALL Java_physx_extensions_PxDistanceJointFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxDistanceJointFlags);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxDistanceJointFlags__1_1placement_1new_1PxDistanceJointFlags(JNIEnv*, jclass, jlong _placement_address, jshort flags) {
    return (jlong) new((void*)_placement_address) physx::PxDistanceJointFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxDistanceJointFlags__1PxDistanceJointFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxDistanceJointFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxDistanceJointFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxDistanceJointFlags* self = (physx::PxDistanceJointFlags*) _address;
    return (jboolean) self->isSet((PxDistanceJointFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDistanceJointFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxDistanceJointFlags* self = (physx::PxDistanceJointFlags*) _address;
    self->raise((PxDistanceJointFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDistanceJointFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxDistanceJointFlags* self = (physx::PxDistanceJointFlags*) _address;
    self->clear((PxDistanceJointFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDistanceJointFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxDistanceJointFlags*) _address;
}

// PxFixedJoint
JNIEXPORT jint JNICALL Java_physx_extensions_PxFixedJoint__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxFixedJoint);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxFixedJoint__1setProjectionLinearTolerance(JNIEnv*, jclass, jlong _address, jfloat tolerance) {
    physx::PxFixedJoint* self = (physx::PxFixedJoint*) _address;
    self->setProjectionLinearTolerance(tolerance);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxFixedJoint__1getProjectionLinearTolerance(JNIEnv*, jclass, jlong _address) {
    physx::PxFixedJoint* self = (physx::PxFixedJoint*) _address;
    return (jfloat) self->getProjectionLinearTolerance();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxFixedJoint__1setProjectionAngularTolerance(JNIEnv*, jclass, jlong _address, jfloat tolerance) {
    physx::PxFixedJoint* self = (physx::PxFixedJoint*) _address;
    self->setProjectionAngularTolerance(tolerance);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxFixedJoint__1getProjectionAngularTolerance(JNIEnv*, jclass, jlong _address) {
    physx::PxFixedJoint* self = (physx::PxFixedJoint*) _address;
    return (jfloat) self->getProjectionAngularTolerance();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxFixedJoint__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxFixedJoint*) _address;
}

// PxJoint
JNIEXPORT jint JNICALL Java_physx_extensions_PxJoint__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxJoint);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJoint__1setActors(JNIEnv*, jclass, jlong _address, jlong actor0, jlong actor1) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    self->setActors((physx::PxRigidActor*) actor0, (physx::PxRigidActor*) actor1);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJoint__1setLocalPose(JNIEnv*, jclass, jlong _address, jint actor, jlong localPose) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    self->setLocalPose((PxJointActorIndexEnum) actor, *((physx::PxTransform*) localPose));
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxJoint__1getLocalPose(JNIEnv*, jclass, jlong _address, jint actor) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    static thread_local physx::PxTransform _cache = self->getLocalPose((PxJointActorIndexEnum) actor);
    _cache = self->getLocalPose((PxJointActorIndexEnum) actor);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxJoint__1getRelativeTransform(JNIEnv*, jclass, jlong _address) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    static thread_local physx::PxTransform _cache = self->getRelativeTransform();
    _cache = self->getRelativeTransform();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxJoint__1getRelativeLinearVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    static thread_local physx::PxVec3 _cache = self->getRelativeLinearVelocity();
    _cache = self->getRelativeLinearVelocity();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxJoint__1getRelativeAngularVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    static thread_local physx::PxVec3 _cache = self->getRelativeAngularVelocity();
    _cache = self->getRelativeAngularVelocity();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJoint__1setBreakForce(JNIEnv*, jclass, jlong _address, jfloat force, jfloat torque) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    self->setBreakForce(force, torque);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJoint__1setConstraintFlags(JNIEnv*, jclass, jlong _address, jlong flags) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    self->setConstraintFlags(*((physx::PxConstraintFlags*) flags));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJoint__1setConstraintFlag(JNIEnv*, jclass, jlong _address, jint flag, jboolean value) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    self->setConstraintFlag((PxConstraintFlagEnum) flag, value);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxJoint__1getConstraintFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    static thread_local physx::PxConstraintFlags _cache = self->getConstraintFlags();
    _cache = self->getConstraintFlags();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJoint__1setInvMassScale0(JNIEnv*, jclass, jlong _address, jfloat invMassScale) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    self->setInvMassScale0(invMassScale);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJoint__1getInvMassScale0(JNIEnv*, jclass, jlong _address) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    return (jfloat) self->getInvMassScale0();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJoint__1setInvMassScale1(JNIEnv*, jclass, jlong _address, jfloat invMassScale) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    self->setInvMassScale1(invMassScale);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJoint__1getInvMassScale1(JNIEnv*, jclass, jlong _address) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    return (jfloat) self->getInvMassScale1();
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxJoint__1getConstraint(JNIEnv*, jclass, jlong _address) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    return (jlong) self->getConstraint();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJoint__1setName(JNIEnv* _env, jclass, jlong _address, jstring name) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    self->setName(_env->GetStringUTFChars(name, 0));
}
JNIEXPORT jstring JNICALL Java_physx_extensions_PxJoint__1getName(JNIEnv* _env, jclass, jlong _address) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    return _env->NewStringUTF(self->getName());
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxJoint__1getScene(JNIEnv*, jclass, jlong _address) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    return (jlong) self->getScene();
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxJoint__1getUserData(JNIEnv*, jclass, jlong _address) {
    physx::PxJoint* _self = (physx::PxJoint*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJoint__1setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxJoint* _self = (physx::PxJoint*) _address;
    _self->userData = (void*) value;
}

// PxJointAngularLimitPair
JNIEXPORT jint JNICALL Java_physx_extensions_PxJointAngularLimitPair__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxJointAngularLimitPair);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxJointAngularLimitPair__1PxJointAngularLimitPair(JNIEnv*, jclass, jfloat lowerLimit, jfloat upperLimit, jlong spring) {
    return (jlong) new physx::PxJointAngularLimitPair(lowerLimit, upperLimit, *((physx::PxSpring*) spring));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointAngularLimitPair__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxJointAngularLimitPair*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointAngularLimitPair__1getUpper(JNIEnv*, jclass, jlong _address) {
    physx::PxJointAngularLimitPair* _self = (physx::PxJointAngularLimitPair*) _address;
    return (jfloat) _self->upper;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointAngularLimitPair__1setUpper(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointAngularLimitPair* _self = (physx::PxJointAngularLimitPair*) _address;
    _self->upper = value;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointAngularLimitPair__1getLower(JNIEnv*, jclass, jlong _address) {
    physx::PxJointAngularLimitPair* _self = (physx::PxJointAngularLimitPair*) _address;
    return (jfloat) _self->lower;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointAngularLimitPair__1setLower(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointAngularLimitPair* _self = (physx::PxJointAngularLimitPair*) _address;
    _self->lower = value;
}

// PxJointLimitCone
JNIEXPORT jint JNICALL Java_physx_extensions_PxJointLimitCone__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxJointLimitCone);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxJointLimitCone__1PxJointLimitCone(JNIEnv*, jclass, jfloat yLimitAngle, jfloat zLimitAngle, jlong spring) {
    return (jlong) new physx::PxJointLimitCone(yLimitAngle, zLimitAngle, *((physx::PxSpring*) spring));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLimitCone__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxJointLimitCone*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointLimitCone__1getYAngle(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLimitCone* _self = (physx::PxJointLimitCone*) _address;
    return (jfloat) _self->yAngle;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLimitCone__1setYAngle(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointLimitCone* _self = (physx::PxJointLimitCone*) _address;
    _self->yAngle = value;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointLimitCone__1getZAngle(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLimitCone* _self = (physx::PxJointLimitCone*) _address;
    return (jfloat) _self->zAngle;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLimitCone__1setZAngle(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointLimitCone* _self = (physx::PxJointLimitCone*) _address;
    _self->zAngle = value;
}

// PxJointLimitParameters
JNIEXPORT jint JNICALL Java_physx_extensions_PxJointLimitParameters__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxJointLimitParameters);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxJointLimitParameters__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLimitParameters* self = (physx::PxJointLimitParameters*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxJointLimitParameters__1isSoft(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLimitParameters* self = (physx::PxJointLimitParameters*) _address;
    return (jboolean) self->isSoft();
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointLimitParameters__1getRestitution(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLimitParameters* _self = (physx::PxJointLimitParameters*) _address;
    return (jfloat) _self->restitution;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLimitParameters__1setRestitution(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointLimitParameters* _self = (physx::PxJointLimitParameters*) _address;
    _self->restitution = value;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointLimitParameters__1getBounceThreshold(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLimitParameters* _self = (physx::PxJointLimitParameters*) _address;
    return (jfloat) _self->bounceThreshold;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLimitParameters__1setBounceThreshold(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointLimitParameters* _self = (physx::PxJointLimitParameters*) _address;
    _self->bounceThreshold = value;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointLimitParameters__1getStiffness(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLimitParameters* _self = (physx::PxJointLimitParameters*) _address;
    return (jfloat) _self->stiffness;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLimitParameters__1setStiffness(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointLimitParameters* _self = (physx::PxJointLimitParameters*) _address;
    _self->stiffness = value;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointLimitParameters__1getDamping(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLimitParameters* _self = (physx::PxJointLimitParameters*) _address;
    return (jfloat) _self->damping;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLimitParameters__1setDamping(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointLimitParameters* _self = (physx::PxJointLimitParameters*) _address;
    _self->damping = value;
}

// PxJointLimitPyramid
JNIEXPORT jint JNICALL Java_physx_extensions_PxJointLimitPyramid__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxJointLimitPyramid);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxJointLimitPyramid__1PxJointLimitPyramid(JNIEnv*, jclass, jfloat yLimitAngleMin, jfloat yLimitAngleMax, jfloat zLimitAngleMin, jfloat zLimitAngleMax, jlong spring) {
    return (jlong) new physx::PxJointLimitPyramid(yLimitAngleMin, yLimitAngleMax, zLimitAngleMin, zLimitAngleMax, *((physx::PxSpring*) spring));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLimitPyramid__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxJointLimitPyramid*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointLimitPyramid__1getYAngleMin(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLimitPyramid* _self = (physx::PxJointLimitPyramid*) _address;
    return (jfloat) _self->yAngleMin;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLimitPyramid__1setYAngleMin(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointLimitPyramid* _self = (physx::PxJointLimitPyramid*) _address;
    _self->yAngleMin = value;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointLimitPyramid__1getYAngleMax(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLimitPyramid* _self = (physx::PxJointLimitPyramid*) _address;
    return (jfloat) _self->yAngleMax;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLimitPyramid__1setYAngleMax(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointLimitPyramid* _self = (physx::PxJointLimitPyramid*) _address;
    _self->yAngleMax = value;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointLimitPyramid__1getZAngleMin(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLimitPyramid* _self = (physx::PxJointLimitPyramid*) _address;
    return (jfloat) _self->zAngleMin;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLimitPyramid__1setZAngleMin(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointLimitPyramid* _self = (physx::PxJointLimitPyramid*) _address;
    _self->zAngleMin = value;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointLimitPyramid__1getZAngleMax(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLimitPyramid* _self = (physx::PxJointLimitPyramid*) _address;
    return (jfloat) _self->zAngleMax;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLimitPyramid__1setZAngleMax(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointLimitPyramid* _self = (physx::PxJointLimitPyramid*) _address;
    _self->zAngleMax = value;
}

// PxJointLinearLimit
JNIEXPORT jint JNICALL Java_physx_extensions_PxJointLinearLimit__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxJointLinearLimit);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxJointLinearLimit__1PxJointLinearLimit(JNIEnv*, jclass, jfloat extent, jlong spring) {
    return (jlong) new physx::PxJointLinearLimit(extent, *((physx::PxSpring*) spring));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLinearLimit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxJointLinearLimit*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointLinearLimit__1getValue(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLinearLimit* _self = (physx::PxJointLinearLimit*) _address;
    return (jfloat) _self->value;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLinearLimit__1setValue(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointLinearLimit* _self = (physx::PxJointLinearLimit*) _address;
    _self->value = value;
}

// PxJointLinearLimitPair
JNIEXPORT jint JNICALL Java_physx_extensions_PxJointLinearLimitPair__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxJointLinearLimitPair);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxJointLinearLimitPair__1PxJointLinearLimitPair(JNIEnv*, jclass, jfloat lowerLimit, jfloat upperLimit, jlong spring) {
    return (jlong) new physx::PxJointLinearLimitPair(lowerLimit, upperLimit, *((physx::PxSpring*) spring));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLinearLimitPair__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxJointLinearLimitPair*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointLinearLimitPair__1getUpper(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLinearLimitPair* _self = (physx::PxJointLinearLimitPair*) _address;
    return (jfloat) _self->upper;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLinearLimitPair__1setUpper(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointLinearLimitPair* _self = (physx::PxJointLinearLimitPair*) _address;
    _self->upper = value;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointLinearLimitPair__1getLower(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLinearLimitPair* _self = (physx::PxJointLinearLimitPair*) _address;
    return (jfloat) _self->lower;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLinearLimitPair__1setLower(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointLinearLimitPair* _self = (physx::PxJointLinearLimitPair*) _address;
    _self->lower = value;
}

// PxPrismaticJoint
JNIEXPORT jint JNICALL Java_physx_extensions_PxPrismaticJoint__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxPrismaticJoint);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxPrismaticJoint__1getPosition(JNIEnv*, jclass, jlong _address) {
    physx::PxPrismaticJoint* self = (physx::PxPrismaticJoint*) _address;
    return (jfloat) self->getPosition();
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxPrismaticJoint__1getVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxPrismaticJoint* self = (physx::PxPrismaticJoint*) _address;
    return (jfloat) self->getVelocity();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxPrismaticJoint__1setLimit(JNIEnv*, jclass, jlong _address, jlong limit) {
    physx::PxPrismaticJoint* self = (physx::PxPrismaticJoint*) _address;
    self->setLimit(*((physx::PxJointLinearLimitPair*) limit));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxPrismaticJoint__1setPrismaticJointFlags(JNIEnv*, jclass, jlong _address, jlong flags) {
    physx::PxPrismaticJoint* self = (physx::PxPrismaticJoint*) _address;
    self->setPrismaticJointFlags(*((physx::PxPrismaticJointFlags*) flags));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxPrismaticJoint__1setPrismaticJointFlag(JNIEnv*, jclass, jlong _address, jint flag, jboolean value) {
    physx::PxPrismaticJoint* self = (physx::PxPrismaticJoint*) _address;
    self->setPrismaticJointFlag((PxPrismaticJointFlagEnum) flag, value);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxPrismaticJoint__1getPrismaticJointFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxPrismaticJoint* self = (physx::PxPrismaticJoint*) _address;
    static thread_local physx::PxPrismaticJointFlags _cache = self->getPrismaticJointFlags();
    _cache = self->getPrismaticJointFlags();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxPrismaticJoint__1setProjectionLinearTolerance(JNIEnv*, jclass, jlong _address, jfloat tolerance) {
    physx::PxPrismaticJoint* self = (physx::PxPrismaticJoint*) _address;
    self->setProjectionLinearTolerance(tolerance);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxPrismaticJoint__1getProjectionLinearTolerance(JNIEnv*, jclass, jlong _address) {
    physx::PxPrismaticJoint* self = (physx::PxPrismaticJoint*) _address;
    return (jfloat) self->getProjectionLinearTolerance();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxPrismaticJoint__1setProjectionAngularTolerance(JNIEnv*, jclass, jlong _address, jfloat tolerance) {
    physx::PxPrismaticJoint* self = (physx::PxPrismaticJoint*) _address;
    self->setProjectionAngularTolerance(tolerance);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxPrismaticJoint__1getProjectionAngularTolerance(JNIEnv*, jclass, jlong _address) {
    physx::PxPrismaticJoint* self = (physx::PxPrismaticJoint*) _address;
    return (jfloat) self->getProjectionAngularTolerance();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxPrismaticJoint__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxPrismaticJoint*) _address;
}

// PxPrismaticJointFlags
JNIEXPORT jint JNICALL Java_physx_extensions_PxPrismaticJointFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxPrismaticJointFlags);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxPrismaticJointFlags__1_1placement_1new_1PxPrismaticJointFlags(JNIEnv*, jclass, jlong _placement_address, jshort flags) {
    return (jlong) new((void*)_placement_address) physx::PxPrismaticJointFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxPrismaticJointFlags__1PxPrismaticJointFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxPrismaticJointFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxPrismaticJointFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxPrismaticJointFlags* self = (physx::PxPrismaticJointFlags*) _address;
    return (jboolean) self->isSet((PxPrismaticJointFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxPrismaticJointFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxPrismaticJointFlags* self = (physx::PxPrismaticJointFlags*) _address;
    self->raise((PxPrismaticJointFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxPrismaticJointFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxPrismaticJointFlags* self = (physx::PxPrismaticJointFlags*) _address;
    self->clear((PxPrismaticJointFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxPrismaticJointFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxPrismaticJointFlags*) _address;
}

// PxRevoluteJoint
JNIEXPORT jint JNICALL Java_physx_extensions_PxRevoluteJoint__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxRevoluteJoint);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxRevoluteJoint__1getAngle(JNIEnv*, jclass, jlong _address) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    return (jfloat) self->getAngle();
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxRevoluteJoint__1getVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    return (jfloat) self->getVelocity();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJoint__1setLimit(JNIEnv*, jclass, jlong _address, jlong limits) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    self->setLimit(*((physx::PxJointAngularLimitPair*) limits));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJoint__1setDriveVelocity__JF(JNIEnv*, jclass, jlong _address, jfloat velocity) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    self->setDriveVelocity(velocity);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJoint__1setDriveVelocity__JFZ(JNIEnv*, jclass, jlong _address, jfloat velocity, jboolean autowake) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    self->setDriveVelocity(velocity, autowake);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxRevoluteJoint__1getDriveVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    return (jfloat) self->getDriveVelocity();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJoint__1setDriveForceLimit(JNIEnv*, jclass, jlong _address, jfloat limit) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    self->setDriveForceLimit(limit);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxRevoluteJoint__1getDriveForceLimit(JNIEnv*, jclass, jlong _address) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    return (jfloat) self->getDriveForceLimit();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJoint__1setDriveGearRatio(JNIEnv*, jclass, jlong _address, jfloat ratio) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    self->setDriveGearRatio(ratio);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxRevoluteJoint__1getDriveGearRatio(JNIEnv*, jclass, jlong _address) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    return (jfloat) self->getDriveGearRatio();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJoint__1setRevoluteJointFlags(JNIEnv*, jclass, jlong _address, jlong flags) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    self->setRevoluteJointFlags(*((physx::PxRevoluteJointFlags*) flags));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJoint__1setRevoluteJointFlag(JNIEnv*, jclass, jlong _address, jint flag, jboolean value) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    self->setRevoluteJointFlag((PxRevoluteJointFlagEnum) flag, value);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxRevoluteJoint__1getRevoluteJointFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    static thread_local physx::PxRevoluteJointFlags _cache = self->getRevoluteJointFlags();
    _cache = self->getRevoluteJointFlags();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJoint__1setProjectionLinearTolerance(JNIEnv*, jclass, jlong _address, jfloat tolerance) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    self->setProjectionLinearTolerance(tolerance);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxRevoluteJoint__1getProjectionLinearTolerance(JNIEnv*, jclass, jlong _address) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    return (jfloat) self->getProjectionLinearTolerance();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJoint__1setProjectionAngularTolerance(JNIEnv*, jclass, jlong _address, jfloat tolerance) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    self->setProjectionAngularTolerance(tolerance);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxRevoluteJoint__1getProjectionAngularTolerance(JNIEnv*, jclass, jlong _address) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    return (jfloat) self->getProjectionAngularTolerance();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJoint__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxRevoluteJoint*) _address;
}

// PxRevoluteJointFlags
JNIEXPORT jint JNICALL Java_physx_extensions_PxRevoluteJointFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxRevoluteJointFlags);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxRevoluteJointFlags__1_1placement_1new_1PxRevoluteJointFlags(JNIEnv*, jclass, jlong _placement_address, jshort flags) {
    return (jlong) new((void*)_placement_address) physx::PxRevoluteJointFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxRevoluteJointFlags__1PxRevoluteJointFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxRevoluteJointFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxRevoluteJointFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxRevoluteJointFlags* self = (physx::PxRevoluteJointFlags*) _address;
    return (jboolean) self->isSet((PxRevoluteJointFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJointFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxRevoluteJointFlags* self = (physx::PxRevoluteJointFlags*) _address;
    self->raise((PxRevoluteJointFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJointFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxRevoluteJointFlags* self = (physx::PxRevoluteJointFlags*) _address;
    self->clear((PxRevoluteJointFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJointFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxRevoluteJointFlags*) _address;
}

// PxSphericalJoint
JNIEXPORT jint JNICALL Java_physx_extensions_PxSphericalJoint__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxSphericalJoint);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxSphericalJoint__1setLimitCone(JNIEnv*, jclass, jlong _address, jlong limitCone) {
    physx::PxSphericalJoint* self = (physx::PxSphericalJoint*) _address;
    self->setLimitCone(*((physx::PxJointLimitCone*) limitCone));
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxSphericalJoint__1getSwingYAngle(JNIEnv*, jclass, jlong _address) {
    physx::PxSphericalJoint* self = (physx::PxSphericalJoint*) _address;
    return (jfloat) self->getSwingYAngle();
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxSphericalJoint__1getSwingZAngle(JNIEnv*, jclass, jlong _address) {
    physx::PxSphericalJoint* self = (physx::PxSphericalJoint*) _address;
    return (jfloat) self->getSwingZAngle();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxSphericalJoint__1setSphericalJointFlags(JNIEnv*, jclass, jlong _address, jlong flags) {
    physx::PxSphericalJoint* self = (physx::PxSphericalJoint*) _address;
    self->setSphericalJointFlags(*((physx::PxSphericalJointFlags*) flags));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxSphericalJoint__1setSphericalJointFlag(JNIEnv*, jclass, jlong _address, jint flag, jboolean value) {
    physx::PxSphericalJoint* self = (physx::PxSphericalJoint*) _address;
    self->setSphericalJointFlag((PxSphericalJointFlagEnum) flag, value);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxSphericalJoint__1getSphericalJointFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxSphericalJoint* self = (physx::PxSphericalJoint*) _address;
    static thread_local physx::PxSphericalJointFlags _cache = self->getSphericalJointFlags();
    _cache = self->getSphericalJointFlags();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxSphericalJoint__1setProjectionLinearTolerance(JNIEnv*, jclass, jlong _address, jfloat tolerance) {
    physx::PxSphericalJoint* self = (physx::PxSphericalJoint*) _address;
    self->setProjectionLinearTolerance(tolerance);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxSphericalJoint__1getProjectionLinearTolerance(JNIEnv*, jclass, jlong _address) {
    physx::PxSphericalJoint* self = (physx::PxSphericalJoint*) _address;
    return (jfloat) self->getProjectionLinearTolerance();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxSphericalJoint__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSphericalJoint*) _address;
}

// PxSphericalJointFlags
JNIEXPORT jint JNICALL Java_physx_extensions_PxSphericalJointFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxSphericalJointFlags);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxSphericalJointFlags__1_1placement_1new_1PxSphericalJointFlags(JNIEnv*, jclass, jlong _placement_address, jshort flags) {
    return (jlong) new((void*)_placement_address) physx::PxSphericalJointFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxSphericalJointFlags__1PxSphericalJointFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxSphericalJointFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxSphericalJointFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxSphericalJointFlags* self = (physx::PxSphericalJointFlags*) _address;
    return (jboolean) self->isSet((PxSphericalJointFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxSphericalJointFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxSphericalJointFlags* self = (physx::PxSphericalJointFlags*) _address;
    self->raise((PxSphericalJointFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxSphericalJointFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxSphericalJointFlags* self = (physx::PxSphericalJointFlags*) _address;
    self->clear((PxSphericalJointFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxSphericalJointFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSphericalJointFlags*) _address;
}

// PxSpring
JNIEXPORT jint JNICALL Java_physx_extensions_PxSpring__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxSpring);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxSpring__1PxSpring(JNIEnv*, jclass, jfloat stiffness, jfloat damping) {
    return (jlong) new physx::PxSpring(stiffness, damping);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxSpring__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSpring*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxSpring__1getStiffness(JNIEnv*, jclass, jlong _address) {
    physx::PxSpring* _self = (physx::PxSpring*) _address;
    return (jfloat) _self->stiffness;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxSpring__1setStiffness(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxSpring* _self = (physx::PxSpring*) _address;
    _self->stiffness = value;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxSpring__1getDamping(JNIEnv*, jclass, jlong _address) {
    physx::PxSpring* _self = (physx::PxSpring*) _address;
    return (jfloat) _self->damping;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxSpring__1setDamping(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxSpring* _self = (physx::PxSpring*) _address;
    _self->damping = value;
}

// PxD6AxisEnum
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6AxisEnum__1geteX(JNIEnv*, jclass) {
    return PxD6AxisEnum::eX;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6AxisEnum__1geteY(JNIEnv*, jclass) {
    return PxD6AxisEnum::eY;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6AxisEnum__1geteZ(JNIEnv*, jclass) {
    return PxD6AxisEnum::eZ;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6AxisEnum__1geteTWIST(JNIEnv*, jclass) {
    return PxD6AxisEnum::eTWIST;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6AxisEnum__1geteSWING1(JNIEnv*, jclass) {
    return PxD6AxisEnum::eSWING1;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6AxisEnum__1geteSWING2(JNIEnv*, jclass) {
    return PxD6AxisEnum::eSWING2;
}

// PxD6DriveEnum
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6DriveEnum__1geteX(JNIEnv*, jclass) {
    return PxD6DriveEnum::eX;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6DriveEnum__1geteY(JNIEnv*, jclass) {
    return PxD6DriveEnum::eY;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6DriveEnum__1geteZ(JNIEnv*, jclass) {
    return PxD6DriveEnum::eZ;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6DriveEnum__1geteSWING(JNIEnv*, jclass) {
    return PxD6DriveEnum::eSWING;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6DriveEnum__1geteTWIST(JNIEnv*, jclass) {
    return PxD6DriveEnum::eTWIST;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6DriveEnum__1geteSLERP(JNIEnv*, jclass) {
    return PxD6DriveEnum::eSLERP;
}

// PxD6JointDriveFlagEnum
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6JointDriveFlagEnum__1geteACCELERATION(JNIEnv*, jclass) {
    return PxD6JointDriveFlagEnum::eACCELERATION;
}

// PxD6MotionEnum
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6MotionEnum__1geteLOCKED(JNIEnv*, jclass) {
    return PxD6MotionEnum::eLOCKED;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6MotionEnum__1geteLIMITED(JNIEnv*, jclass) {
    return PxD6MotionEnum::eLIMITED;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6MotionEnum__1geteFREE(JNIEnv*, jclass) {
    return PxD6MotionEnum::eFREE;
}

// PxDistanceJointFlagEnum
JNIEXPORT jint JNICALL Java_physx_extensions_PxDistanceJointFlagEnum__1geteMAX_1DISTANCE_1ENABLED(JNIEnv*, jclass) {
    return PxDistanceJointFlagEnum::eMAX_DISTANCE_ENABLED;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxDistanceJointFlagEnum__1geteMIN_1DISTANCE_1ENABLED(JNIEnv*, jclass) {
    return PxDistanceJointFlagEnum::eMIN_DISTANCE_ENABLED;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxDistanceJointFlagEnum__1geteSPRING_1ENABLED(JNIEnv*, jclass) {
    return PxDistanceJointFlagEnum::eSPRING_ENABLED;
}

// PxJointActorIndexEnum
JNIEXPORT jint JNICALL Java_physx_extensions_PxJointActorIndexEnum__1geteACTOR0(JNIEnv*, jclass) {
    return PxJointActorIndexEnum::eACTOR0;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxJointActorIndexEnum__1geteACTOR1(JNIEnv*, jclass) {
    return PxJointActorIndexEnum::eACTOR1;
}

// PxPrismaticJointFlagEnum
JNIEXPORT jint JNICALL Java_physx_extensions_PxPrismaticJointFlagEnum__1geteLIMIT_1ENABLED(JNIEnv*, jclass) {
    return PxPrismaticJointFlagEnum::eLIMIT_ENABLED;
}

// PxRevoluteJointFlagEnum
JNIEXPORT jint JNICALL Java_physx_extensions_PxRevoluteJointFlagEnum__1geteLIMIT_1ENABLED(JNIEnv*, jclass) {
    return PxRevoluteJointFlagEnum::eLIMIT_ENABLED;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxRevoluteJointFlagEnum__1geteDRIVE_1ENABLED(JNIEnv*, jclass) {
    return PxRevoluteJointFlagEnum::eDRIVE_ENABLED;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxRevoluteJointFlagEnum__1geteDRIVE_1FREESPIN(JNIEnv*, jclass) {
    return PxRevoluteJointFlagEnum::eDRIVE_FREESPIN;
}

// PxSphericalJointFlagEnum
JNIEXPORT jint JNICALL Java_physx_extensions_PxSphericalJointFlagEnum__1geteLIMIT_1ENABLED(JNIEnv*, jclass) {
    return PxSphericalJointFlagEnum::eLIMIT_ENABLED;
}

// PxBoxGeometry
JNIEXPORT jint JNICALL Java_physx_geometry_PxBoxGeometry__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxBoxGeometry);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxBoxGeometry__1_1placement_1new_1PxBoxGeometry(JNIEnv*, jclass, jlong _placement_address, jfloat hx, jfloat hy, jfloat hz) {
    return (jlong) new((void*)_placement_address) physx::PxBoxGeometry(hx, hy, hz);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxBoxGeometry__1PxBoxGeometry(JNIEnv*, jclass, jfloat hx, jfloat hy, jfloat hz) {
    return (jlong) new physx::PxBoxGeometry(hx, hy, hz);
}
JNIEXPORT void JNICALL Java_physx_geometry_PxBoxGeometry__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBoxGeometry*) _address;
}

// PxBVHStructure
JNIEXPORT jint JNICALL Java_physx_geometry_PxBVHStructure__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxBVHStructure);
}

// PxCapsuleGeometry
JNIEXPORT jint JNICALL Java_physx_geometry_PxCapsuleGeometry__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxCapsuleGeometry);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxCapsuleGeometry__1_1placement_1new_1PxCapsuleGeometry(JNIEnv*, jclass, jlong _placement_address, jfloat radius, jfloat halfHeight) {
    return (jlong) new((void*)_placement_address) physx::PxCapsuleGeometry(radius, halfHeight);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxCapsuleGeometry__1PxCapsuleGeometry(JNIEnv*, jclass, jfloat radius, jfloat halfHeight) {
    return (jlong) new physx::PxCapsuleGeometry(radius, halfHeight);
}
JNIEXPORT void JNICALL Java_physx_geometry_PxCapsuleGeometry__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxCapsuleGeometry*) _address;
}

// PxContactBuffer
JNIEXPORT jint JNICALL Java_physx_geometry_PxContactBuffer__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxContactBuffer);
}
JNIEXPORT void JNICALL Java_physx_geometry_PxContactBuffer__1reset(JNIEnv*, jclass, jlong _address) {
    physx::PxContactBuffer* self = (physx::PxContactBuffer*) _address;
    self->reset();
}
JNIEXPORT jboolean JNICALL Java_physx_geometry_PxContactBuffer__1contact__JJJF(JNIEnv*, jclass, jlong _address, jlong worldPoint, jlong worldNormalIn, jfloat separation) {
    physx::PxContactBuffer* self = (physx::PxContactBuffer*) _address;
    return (jboolean) self->contact(*((physx::PxVec3*) worldPoint), *((physx::PxVec3*) worldNormalIn), separation);
}
JNIEXPORT jboolean JNICALL Java_physx_geometry_PxContactBuffer__1contact__JJJFI(JNIEnv*, jclass, jlong _address, jlong worldPoint, jlong worldNormalIn, jfloat separation, jint faceIndex1) {
    physx::PxContactBuffer* self = (physx::PxContactBuffer*) _address;
    return (jboolean) self->contact(*((physx::PxVec3*) worldPoint), *((physx::PxVec3*) worldNormalIn), separation, faceIndex1);
}
JNIEXPORT jboolean JNICALL Java_physx_geometry_PxContactBuffer__1contact__JJ(JNIEnv*, jclass, jlong _address, jlong pt) {
    physx::PxContactBuffer* self = (physx::PxContactBuffer*) _address;
    return (jboolean) self->contact(*((physx::PxContactPoint*) pt));
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxContactBuffer__1contact__J(JNIEnv*, jclass, jlong _address) {
    physx::PxContactBuffer* self = (physx::PxContactBuffer*) _address;
    return (jlong) self->contact();
}
JNIEXPORT void JNICALL Java_physx_geometry_PxContactBuffer__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxContactBuffer*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxContactBuffer__1getContacts(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::PxContactBuffer* _self = (physx::PxContactBuffer*) _address;
    return (jlong) &_self->contacts[_index];
}
JNIEXPORT void JNICALL Java_physx_geometry_PxContactBuffer__1setContacts(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    physx::PxContactBuffer* _self = (physx::PxContactBuffer*) _address;
    _self->contacts[_index] = *((physx::PxContactPoint*) value);
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxContactBuffer__1getCount(JNIEnv*, jclass, jlong _address) {
    physx::PxContactBuffer* _self = (physx::PxContactBuffer*) _address;
    return (jint) _self->count;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxContactBuffer__1setCount(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxContactBuffer* _self = (physx::PxContactBuffer*) _address;
    _self->count = value;
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxContactBuffer__1getPad(JNIEnv*, jclass, jlong _address) {
    physx::PxContactBuffer* _self = (physx::PxContactBuffer*) _address;
    return (jint) _self->pad;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxContactBuffer__1setPad(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxContactBuffer* _self = (physx::PxContactBuffer*) _address;
    _self->pad = value;
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxContactBuffer__1getMAX_1CONTACTS(JNIEnv*, jclass) {
    return (jint) physx::PxContactBuffer::MAX_CONTACTS;
}

// PxContactPoint
JNIEXPORT jint JNICALL Java_physx_geometry_PxContactPoint__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxContactPoint);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxContactPoint__1PxContactPoint(JNIEnv*, jclass) {
    return (jlong) new physx::PxContactPoint();
}
JNIEXPORT void JNICALL Java_physx_geometry_PxContactPoint__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxContactPoint*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxContactPoint__1getNormal(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPoint* _self = (physx::PxContactPoint*) _address;
    return (jlong) &_self->normal;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxContactPoint__1setNormal(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxContactPoint* _self = (physx::PxContactPoint*) _address;
    _self->normal = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxContactPoint__1getPoint(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPoint* _self = (physx::PxContactPoint*) _address;
    return (jlong) &_self->point;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxContactPoint__1setPoint(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxContactPoint* _self = (physx::PxContactPoint*) _address;
    _self->point = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxContactPoint__1getTargetVel(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPoint* _self = (physx::PxContactPoint*) _address;
    return (jlong) &_self->targetVel;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxContactPoint__1setTargetVel(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxContactPoint* _self = (physx::PxContactPoint*) _address;
    _self->targetVel = *((physx::PxVec3*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_geometry_PxContactPoint__1getSeparation(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPoint* _self = (physx::PxContactPoint*) _address;
    return (jfloat) _self->separation;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxContactPoint__1setSeparation(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxContactPoint* _self = (physx::PxContactPoint*) _address;
    _self->separation = value;
}
JNIEXPORT jfloat JNICALL Java_physx_geometry_PxContactPoint__1getMaxImpulse(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPoint* _self = (physx::PxContactPoint*) _address;
    return (jfloat) _self->maxImpulse;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxContactPoint__1setMaxImpulse(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxContactPoint* _self = (physx::PxContactPoint*) _address;
    _self->maxImpulse = value;
}
JNIEXPORT jfloat JNICALL Java_physx_geometry_PxContactPoint__1getStaticFriction(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPoint* _self = (physx::PxContactPoint*) _address;
    return (jfloat) _self->staticFriction;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxContactPoint__1setStaticFriction(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxContactPoint* _self = (physx::PxContactPoint*) _address;
    _self->staticFriction = value;
}
JNIEXPORT jbyte JNICALL Java_physx_geometry_PxContactPoint__1getMaterialFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPoint* _self = (physx::PxContactPoint*) _address;
    return (jbyte) _self->materialFlags;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxContactPoint__1setMaterialFlags(JNIEnv*, jclass, jlong _address, jbyte value) {
    physx::PxContactPoint* _self = (physx::PxContactPoint*) _address;
    _self->materialFlags = value;
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxContactPoint__1getInternalFaceIndex1(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPoint* _self = (physx::PxContactPoint*) _address;
    return (jint) _self->internalFaceIndex1;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxContactPoint__1setInternalFaceIndex1(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxContactPoint* _self = (physx::PxContactPoint*) _address;
    _self->internalFaceIndex1 = value;
}
JNIEXPORT jfloat JNICALL Java_physx_geometry_PxContactPoint__1getDynamicFriction(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPoint* _self = (physx::PxContactPoint*) _address;
    return (jfloat) _self->dynamicFriction;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxContactPoint__1setDynamicFriction(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxContactPoint* _self = (physx::PxContactPoint*) _address;
    _self->dynamicFriction = value;
}
JNIEXPORT jfloat JNICALL Java_physx_geometry_PxContactPoint__1getRestitution(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPoint* _self = (physx::PxContactPoint*) _address;
    return (jfloat) _self->restitution;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxContactPoint__1setRestitution(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxContactPoint* _self = (physx::PxContactPoint*) _address;
    _self->restitution = value;
}
JNIEXPORT jfloat JNICALL Java_physx_geometry_PxContactPoint__1getDamping(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPoint* _self = (physx::PxContactPoint*) _address;
    return (jfloat) _self->damping;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxContactPoint__1setDamping(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxContactPoint* _self = (physx::PxContactPoint*) _address;
    _self->damping = value;
}

// PxConvexMesh
JNIEXPORT jint JNICALL Java_physx_geometry_PxConvexMesh__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxConvexMesh);
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxConvexMesh__1getNbVertices(JNIEnv*, jclass, jlong _address) {
    physx::PxConvexMesh* self = (physx::PxConvexMesh*) _address;
    return (jint) self->getNbVertices();
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxConvexMesh__1getVertices(JNIEnv*, jclass, jlong _address) {
    physx::PxConvexMesh* self = (physx::PxConvexMesh*) _address;
    return (jlong) self->getVertices();
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxConvexMesh__1getIndexBuffer(JNIEnv*, jclass, jlong _address) {
    physx::PxConvexMesh* self = (physx::PxConvexMesh*) _address;
    static thread_local PxU8ConstPtr _cache = self->getIndexBuffer();
    _cache = self->getIndexBuffer();
    return (jlong) &_cache;
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxConvexMesh__1getNbPolygons(JNIEnv*, jclass, jlong _address) {
    physx::PxConvexMesh* self = (physx::PxConvexMesh*) _address;
    return (jint) self->getNbPolygons();
}
JNIEXPORT jboolean JNICALL Java_physx_geometry_PxConvexMesh__1getPolygonData(JNIEnv*, jclass, jlong _address, jint index, jlong data) {
    physx::PxConvexMesh* self = (physx::PxConvexMesh*) _address;
    return (jboolean) self->getPolygonData(index, *((physx::PxHullPolygon*) data));
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxConvexMesh__1getLocalBounds(JNIEnv*, jclass, jlong _address) {
    physx::PxConvexMesh* self = (physx::PxConvexMesh*) _address;
    static thread_local physx::PxBounds3 _cache = self->getLocalBounds();
    _cache = self->getLocalBounds();
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_geometry_PxConvexMesh__1isGpuCompatible(JNIEnv*, jclass, jlong _address) {
    physx::PxConvexMesh* self = (physx::PxConvexMesh*) _address;
    return (jboolean) self->isGpuCompatible();
}

// PxConvexMeshGeometry
JNIEXPORT jint JNICALL Java_physx_geometry_PxConvexMeshGeometry__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxConvexMeshGeometry);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxConvexMeshGeometry__1_1placement_1new_1PxConvexMeshGeometry__JJ(JNIEnv*, jclass, jlong _placement_address, jlong mesh) {
    return (jlong) new((void*)_placement_address) physx::PxConvexMeshGeometry((physx::PxConvexMesh*) mesh);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxConvexMeshGeometry__1_1placement_1new_1PxConvexMeshGeometry__JJJ(JNIEnv*, jclass, jlong _placement_address, jlong mesh, jlong scaling) {
    return (jlong) new((void*)_placement_address) physx::PxConvexMeshGeometry((physx::PxConvexMesh*) mesh, *((physx::PxMeshScale*) scaling));
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxConvexMeshGeometry__1_1placement_1new_1PxConvexMeshGeometry__JJJJ(JNIEnv*, jclass, jlong _placement_address, jlong mesh, jlong scaling, jlong flags) {
    return (jlong) new((void*)_placement_address) physx::PxConvexMeshGeometry((physx::PxConvexMesh*) mesh, *((physx::PxMeshScale*) scaling), *((physx::PxConvexMeshGeometryFlags*) flags));
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxConvexMeshGeometry__1PxConvexMeshGeometry__J(JNIEnv*, jclass, jlong mesh) {
    return (jlong) new physx::PxConvexMeshGeometry((physx::PxConvexMesh*) mesh);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxConvexMeshGeometry__1PxConvexMeshGeometry__JJ(JNIEnv*, jclass, jlong mesh, jlong scaling) {
    return (jlong) new physx::PxConvexMeshGeometry((physx::PxConvexMesh*) mesh, *((physx::PxMeshScale*) scaling));
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxConvexMeshGeometry__1PxConvexMeshGeometry__JJJ(JNIEnv*, jclass, jlong mesh, jlong scaling, jlong flags) {
    return (jlong) new physx::PxConvexMeshGeometry((physx::PxConvexMesh*) mesh, *((physx::PxMeshScale*) scaling), *((physx::PxConvexMeshGeometryFlags*) flags));
}
JNIEXPORT void JNICALL Java_physx_geometry_PxConvexMeshGeometry__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxConvexMeshGeometry*) _address;
}

// PxConvexMeshGeometryFlags
JNIEXPORT jint JNICALL Java_physx_geometry_PxConvexMeshGeometryFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxConvexMeshGeometryFlags);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxConvexMeshGeometryFlags__1_1placement_1new_1PxConvexMeshGeometryFlags(JNIEnv*, jclass, jlong _placement_address, jbyte flags) {
    return (jlong) new((void*)_placement_address) physx::PxConvexMeshGeometryFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxConvexMeshGeometryFlags__1PxConvexMeshGeometryFlags(JNIEnv*, jclass, jbyte flags) {
    return (jlong) new physx::PxConvexMeshGeometryFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_geometry_PxConvexMeshGeometryFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxConvexMeshGeometryFlags* self = (physx::PxConvexMeshGeometryFlags*) _address;
    return (jboolean) self->isSet((PxConvexMeshGeometryFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geometry_PxConvexMeshGeometryFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxConvexMeshGeometryFlags* self = (physx::PxConvexMeshGeometryFlags*) _address;
    self->raise((PxConvexMeshGeometryFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geometry_PxConvexMeshGeometryFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxConvexMeshGeometryFlags* self = (physx::PxConvexMeshGeometryFlags*) _address;
    self->clear((PxConvexMeshGeometryFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geometry_PxConvexMeshGeometryFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxConvexMeshGeometryFlags*) _address;
}

// PxCustomGeometry
JNIEXPORT jint JNICALL Java_physx_geometry_PxCustomGeometry__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxCustomGeometry);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxCustomGeometry__1PxCustomGeometry(JNIEnv*, jclass, jlong callbacks) {
    return (jlong) new physx::PxCustomGeometry(*((SimpleCustomGeometryCallbacks*) callbacks));
}
JNIEXPORT jboolean JNICALL Java_physx_geometry_PxCustomGeometry__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxCustomGeometry* self = (physx::PxCustomGeometry*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_geometry_PxCustomGeometry__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxCustomGeometry*) _address;
}

// SimpleCustomGeometryCallbacks
JNIEXPORT jint JNICALL Java_physx_geometry_SimpleCustomGeometryCallbacks__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(SimpleCustomGeometryCallbacks);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_SimpleCustomGeometryCallbacks__1getLocalBoundsImpl(JNIEnv*, jclass, jlong _address, jlong geometry) {
    SimpleCustomGeometryCallbacks* self = (SimpleCustomGeometryCallbacks*) _address;
    return (jlong) self->getLocalBoundsImpl(*((physx::PxGeometry*) geometry));
}
JNIEXPORT jboolean JNICALL Java_physx_geometry_SimpleCustomGeometryCallbacks__1generateContactsImpl(JNIEnv*, jclass, jlong _address, jlong geom0, jlong geom1, jlong pose0, jlong pose1, jfloat contactDistance, jfloat meshContactMargin, jfloat toleranceLength, jlong contactBuffer) {
    SimpleCustomGeometryCallbacks* self = (SimpleCustomGeometryCallbacks*) _address;
    return (jboolean) self->generateContactsImpl(*((physx::PxGeometry*) geom0), *((physx::PxGeometry*) geom1), *((physx::PxTransform*) pose0), *((physx::PxTransform*) pose1), contactDistance, meshContactMargin, toleranceLength, *((physx::PxContactBuffer*) contactBuffer));
}
JNIEXPORT jint JNICALL Java_physx_geometry_SimpleCustomGeometryCallbacks__1raycastImpl(JNIEnv*, jclass, jlong _address, jlong origin, jlong unitDir, jlong geom, jlong pose, jfloat maxDist, jlong hitFlags, jint maxHits, jlong rayHits, jint stride) {
    SimpleCustomGeometryCallbacks* self = (SimpleCustomGeometryCallbacks*) _address;
    return (jint) self->raycastImpl(*((physx::PxVec3*) origin), *((physx::PxVec3*) unitDir), *((physx::PxGeometry*) geom), *((physx::PxTransform*) pose), maxDist, *((physx::PxHitFlags*) hitFlags), maxHits, (physx::PxGeomRaycastHit*) rayHits, stride);
}
JNIEXPORT jboolean JNICALL Java_physx_geometry_SimpleCustomGeometryCallbacks__1overlapImpl(JNIEnv*, jclass, jlong _address, jlong geom0, jlong pose0, jlong geom1, jlong pose1) {
    SimpleCustomGeometryCallbacks* self = (SimpleCustomGeometryCallbacks*) _address;
    return (jboolean) self->overlapImpl(*((physx::PxGeometry*) geom0), *((physx::PxTransform*) pose0), *((physx::PxGeometry*) geom1), *((physx::PxTransform*) pose1));
}
JNIEXPORT jboolean JNICALL Java_physx_geometry_SimpleCustomGeometryCallbacks__1sweepImpl(JNIEnv*, jclass, jlong _address, jlong unitDir, jfloat maxDist, jlong geom0, jlong pose0, jlong geom1, jlong pose1, jlong sweepHit, jlong hitFlags, jfloat inflation) {
    SimpleCustomGeometryCallbacks* self = (SimpleCustomGeometryCallbacks*) _address;
    return (jboolean) self->sweepImpl(*((physx::PxVec3*) unitDir), maxDist, *((physx::PxGeometry*) geom0), *((physx::PxTransform*) pose0), *((physx::PxGeometry*) geom1), *((physx::PxTransform*) pose1), *((physx::PxGeomSweepHit*) sweepHit), *((physx::PxHitFlags*) hitFlags), inflation);
}
JNIEXPORT void JNICALL Java_physx_geometry_SimpleCustomGeometryCallbacks__1computeMassPropertiesImpl(JNIEnv*, jclass, jlong _address, jlong geometry, jlong massProperties) {
    SimpleCustomGeometryCallbacks* self = (SimpleCustomGeometryCallbacks*) _address;
    self->computeMassPropertiesImpl(*((physx::PxGeometry*) geometry), *((physx::PxMassProperties*) massProperties));
}
JNIEXPORT jboolean JNICALL Java_physx_geometry_SimpleCustomGeometryCallbacks__1usePersistentContactManifoldImpl(JNIEnv*, jclass, jlong _address, jlong geometry) {
    SimpleCustomGeometryCallbacks* self = (SimpleCustomGeometryCallbacks*) _address;
    return (jboolean) self->usePersistentContactManifoldImpl(*((physx::PxGeometry*) geometry));
}
JNIEXPORT void JNICALL Java_physx_geometry_SimpleCustomGeometryCallbacks__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (SimpleCustomGeometryCallbacks*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_geometry_SimpleCustomGeometryCallbacks__1getPersistentContactManifold_1outBreakingThreshold(JNIEnv*, jclass, jlong _address) {
    SimpleCustomGeometryCallbacks* _self = (SimpleCustomGeometryCallbacks*) _address;
    return (jfloat) _self->persistentContactManifold_outBreakingThreshold;
}
JNIEXPORT void JNICALL Java_physx_geometry_SimpleCustomGeometryCallbacks__1setPersistentContactManifold_1outBreakingThreshold(JNIEnv*, jclass, jlong _address, jfloat value) {
    SimpleCustomGeometryCallbacks* _self = (SimpleCustomGeometryCallbacks*) _address;
    _self->persistentContactManifold_outBreakingThreshold = value;
}

// SimpleCustomGeometryCallbacksImpl
JNIEXPORT jint JNICALL Java_physx_geometry_SimpleCustomGeometryCallbacksImpl__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(SimpleCustomGeometryCallbacksImpl);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_SimpleCustomGeometryCallbacksImpl__1SimpleCustomGeometryCallbacksImpl(JNIEnv* env, jobject obj) {
    return (jlong) new SimpleCustomGeometryCallbacksImpl(env, obj);
}
JNIEXPORT void JNICALL Java_physx_geometry_SimpleCustomGeometryCallbacksImpl__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (SimpleCustomGeometryCallbacksImpl*) address;
}

// PxGeometry
JNIEXPORT jint JNICALL Java_physx_geometry_PxGeometry__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxGeometry);
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxGeometry__1getType(JNIEnv*, jclass, jlong _address) {
    physx::PxGeometry* self = (physx::PxGeometry*) _address;
    return (jint) self->getType();
}
JNIEXPORT void JNICALL Java_physx_geometry_PxGeometry__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxGeometry*) _address;
}

// PxGeometryHolder
JNIEXPORT jint JNICALL Java_physx_geometry_PxGeometryHolder__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxGeometryHolder);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxGeometryHolder__1PxGeometryHolder__(JNIEnv*, jclass) {
    return (jlong) new physx::PxGeometryHolder();
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxGeometryHolder__1PxGeometryHolder__J(JNIEnv*, jclass, jlong geometry) {
    return (jlong) new physx::PxGeometryHolder(*((physx::PxGeometry*) geometry));
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxGeometryHolder__1getType(JNIEnv*, jclass, jlong _address) {
    physx::PxGeometryHolder* self = (physx::PxGeometryHolder*) _address;
    return (jint) self->getType();
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxGeometryHolder__1sphere(JNIEnv*, jclass, jlong _address) {
    physx::PxGeometryHolder* self = (physx::PxGeometryHolder*) _address;
    return (jlong) &self->sphere();
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxGeometryHolder__1plane(JNIEnv*, jclass, jlong _address) {
    physx::PxGeometryHolder* self = (physx::PxGeometryHolder*) _address;
    return (jlong) &self->plane();
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxGeometryHolder__1capsule(JNIEnv*, jclass, jlong _address) {
    physx::PxGeometryHolder* self = (physx::PxGeometryHolder*) _address;
    return (jlong) &self->capsule();
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxGeometryHolder__1box(JNIEnv*, jclass, jlong _address) {
    physx::PxGeometryHolder* self = (physx::PxGeometryHolder*) _address;
    return (jlong) &self->box();
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxGeometryHolder__1convexMesh(JNIEnv*, jclass, jlong _address) {
    physx::PxGeometryHolder* self = (physx::PxGeometryHolder*) _address;
    return (jlong) &self->convexMesh();
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxGeometryHolder__1triangleMesh(JNIEnv*, jclass, jlong _address) {
    physx::PxGeometryHolder* self = (physx::PxGeometryHolder*) _address;
    return (jlong) &self->triangleMesh();
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxGeometryHolder__1heightField(JNIEnv*, jclass, jlong _address) {
    physx::PxGeometryHolder* self = (physx::PxGeometryHolder*) _address;
    return (jlong) &self->heightField();
}
JNIEXPORT void JNICALL Java_physx_geometry_PxGeometryHolder__1storeAny(JNIEnv*, jclass, jlong _address, jlong geometry) {
    physx::PxGeometryHolder* self = (physx::PxGeometryHolder*) _address;
    self->storeAny(*((physx::PxGeometry*) geometry));
}
JNIEXPORT void JNICALL Java_physx_geometry_PxGeometryHolder__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxGeometryHolder*) _address;
}

// PxGeometryQuery
JNIEXPORT jint JNICALL Java_physx_geometry_PxGeometryQuery__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxGeometryQuery);
}
JNIEXPORT jboolean JNICALL Java_physx_geometry_PxGeometryQuery__1sweep__JFJJJJJ(JNIEnv*, jclass, jlong unitDir, jfloat maxDist, jlong geom0, jlong pose0, jlong geom1, jlong pose1, jlong sweepHit) {
    return (jboolean) physx::PxGeometryQuery::sweep(*((physx::PxVec3*) unitDir), maxDist, *((physx::PxGeometry*) geom0), *((physx::PxTransform*) pose0), *((physx::PxGeometry*) geom1), *((physx::PxTransform*) pose1), *((physx::PxSweepHit*) sweepHit));
}
JNIEXPORT jboolean JNICALL Java_physx_geometry_PxGeometryQuery__1sweep__JFJJJJJJ(JNIEnv*, jclass, jlong unitDir, jfloat maxDist, jlong geom0, jlong pose0, jlong geom1, jlong pose1, jlong sweepHit, jlong hitFlags) {
    return (jboolean) physx::PxGeometryQuery::sweep(*((physx::PxVec3*) unitDir), maxDist, *((physx::PxGeometry*) geom0), *((physx::PxTransform*) pose0), *((physx::PxGeometry*) geom1), *((physx::PxTransform*) pose1), *((physx::PxSweepHit*) sweepHit), *((physx::PxHitFlags*) hitFlags));
}
JNIEXPORT jboolean JNICALL Java_physx_geometry_PxGeometryQuery__1sweep__JFJJJJJJF(JNIEnv*, jclass, jlong unitDir, jfloat maxDist, jlong geom0, jlong pose0, jlong geom1, jlong pose1, jlong sweepHit, jlong hitFlags, jfloat inflation) {
    return (jboolean) physx::PxGeometryQuery::sweep(*((physx::PxVec3*) unitDir), maxDist, *((physx::PxGeometry*) geom0), *((physx::PxTransform*) pose0), *((physx::PxGeometry*) geom1), *((physx::PxTransform*) pose1), *((physx::PxSweepHit*) sweepHit), *((physx::PxHitFlags*) hitFlags), inflation);
}
JNIEXPORT jboolean JNICALL Java_physx_geometry_PxGeometryQuery__1overlap(JNIEnv*, jclass, jlong geom0, jlong pose0, jlong geom1, jlong pose1) {
    return (jboolean) physx::PxGeometryQuery::overlap(*((physx::PxGeometry*) geom0), *((physx::PxTransform*) pose0), *((physx::PxGeometry*) geom1), *((physx::PxTransform*) pose1));
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxGeometryQuery__1raycast(JNIEnv*, jclass, jlong origin, jlong unitDir, jlong geom, jlong pose, jfloat maxDist, jlong hitFlags, jint maxHits, jlong rayHits) {
    return (jint) physx::PxGeometryQuery::raycast(*((physx::PxVec3*) origin), *((physx::PxVec3*) unitDir), *((physx::PxGeometry*) geom), *((physx::PxTransform*) pose), maxDist, *((physx::PxHitFlags*) hitFlags), maxHits, (physx::PxRaycastHit*) rayHits);
}
JNIEXPORT jfloat JNICALL Java_physx_geometry_PxGeometryQuery__1pointDistance__JJJ(JNIEnv*, jclass, jlong point, jlong geom, jlong pose) {
    return (jfloat) physx::PxGeometryQuery::pointDistance(*((physx::PxVec3*) point), *((physx::PxGeometry*) geom), *((physx::PxTransform*) pose));
}
JNIEXPORT jfloat JNICALL Java_physx_geometry_PxGeometryQuery__1pointDistance__JJJJ(JNIEnv*, jclass, jlong point, jlong geom, jlong pose, jlong closestPoint) {
    return (jfloat) physx::PxGeometryQuery::pointDistance(*((physx::PxVec3*) point), *((physx::PxGeometry*) geom), *((physx::PxTransform*) pose), (physx::PxVec3*) closestPoint);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxGeometryQuery__1getWorldBounds__JJ(JNIEnv*, jclass, jlong geom, jlong pose) {
    static thread_local physx::PxBounds3 _cache = physx::PxGeometryQuery::getWorldBounds(*((physx::PxGeometry*) geom), *((physx::PxTransform*) pose));
    _cache = physx::PxGeometryQuery::getWorldBounds(*((physx::PxGeometry*) geom), *((physx::PxTransform*) pose));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxGeometryQuery__1getWorldBounds__JJF(JNIEnv*, jclass, jlong geom, jlong pose, jfloat inflation) {
    static thread_local physx::PxBounds3 _cache = physx::PxGeometryQuery::getWorldBounds(*((physx::PxGeometry*) geom), *((physx::PxTransform*) pose), inflation);
    _cache = physx::PxGeometryQuery::getWorldBounds(*((physx::PxGeometry*) geom), *((physx::PxTransform*) pose), inflation);
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_geometry_PxGeometryQuery__1isValid(JNIEnv*, jclass, jlong geom) {
    return (jboolean) physx::PxGeometryQuery::isValid(*((physx::PxGeometry*) geom));
}
JNIEXPORT void JNICALL Java_physx_geometry_PxGeometryQuery__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxGeometryQuery*) _address;
}

// PxHeightField
JNIEXPORT jint JNICALL Java_physx_geometry_PxHeightField__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxHeightField);
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxHeightField__1saveCells(JNIEnv*, jclass, jlong _address, jlong destBuffer, jint destBufferSize) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    return (jint) self->saveCells((void*) destBuffer, destBufferSize);
}
JNIEXPORT jboolean JNICALL Java_physx_geometry_PxHeightField__1modifySamples__JIIJ(JNIEnv*, jclass, jlong _address, jint startCol, jint startRow, jlong subfieldDesc) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    return (jboolean) self->modifySamples(startCol, startRow, *((physx::PxHeightFieldDesc*) subfieldDesc));
}
JNIEXPORT jboolean JNICALL Java_physx_geometry_PxHeightField__1modifySamples__JIIJZ(JNIEnv*, jclass, jlong _address, jint startCol, jint startRow, jlong subfieldDesc, jboolean shrinkBounds) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    return (jboolean) self->modifySamples(startCol, startRow, *((physx::PxHeightFieldDesc*) subfieldDesc), shrinkBounds);
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxHeightField__1getNbRows(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    return (jint) self->getNbRows();
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxHeightField__1getNbColumns(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    return (jint) self->getNbColumns();
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxHeightField__1getFormat(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    return (jint) self->getFormat();
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxHeightField__1getSampleStride(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    return (jint) self->getSampleStride();
}
JNIEXPORT jfloat JNICALL Java_physx_geometry_PxHeightField__1getConvexEdgeThreshold(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    return (jfloat) self->getConvexEdgeThreshold();
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxHeightField__1getFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    static thread_local physx::PxHeightFieldFlags _cache = self->getFlags();
    _cache = self->getFlags();
    return (jlong) &_cache;
}
JNIEXPORT jfloat JNICALL Java_physx_geometry_PxHeightField__1getHeight(JNIEnv*, jclass, jlong _address, jfloat x, jfloat z) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    return (jfloat) self->getHeight(x, z);
}
JNIEXPORT jshort JNICALL Java_physx_geometry_PxHeightField__1getTriangleMaterialIndex(JNIEnv*, jclass, jlong _address, jint triangleIndex) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    return (jshort) self->getTriangleMaterialIndex(triangleIndex);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxHeightField__1getTriangleNormal(JNIEnv*, jclass, jlong _address, jint triangleIndex) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    static thread_local physx::PxVec3 _cache = self->getTriangleNormal(triangleIndex);
    _cache = self->getTriangleNormal(triangleIndex);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxHeightField__1getSample(JNIEnv*, jclass, jlong _address, jint row, jint column) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    return (jlong) &self->getSample(row, column);
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxHeightField__1getTimestamp(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    return (jint) self->getTimestamp();
}

// PxHeightFieldDesc
JNIEXPORT jint JNICALL Java_physx_geometry_PxHeightFieldDesc__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxHeightFieldDesc);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxHeightFieldDesc__1_1placement_1new_1PxHeightFieldDesc(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxHeightFieldDesc();
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxHeightFieldDesc__1PxHeightFieldDesc(JNIEnv*, jclass) {
    return (jlong) new physx::PxHeightFieldDesc();
}
JNIEXPORT void JNICALL Java_physx_geometry_PxHeightFieldDesc__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldDesc* self = (physx::PxHeightFieldDesc*) _address;
    self->setToDefault();
}
JNIEXPORT jboolean JNICALL Java_physx_geometry_PxHeightFieldDesc__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldDesc* self = (physx::PxHeightFieldDesc*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_geometry_PxHeightFieldDesc__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxHeightFieldDesc*) _address;
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxHeightFieldDesc__1getNbRows(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldDesc* _self = (physx::PxHeightFieldDesc*) _address;
    return (jint) _self->nbRows;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxHeightFieldDesc__1setNbRows(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxHeightFieldDesc* _self = (physx::PxHeightFieldDesc*) _address;
    _self->nbRows = value;
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxHeightFieldDesc__1getNbColumns(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldDesc* _self = (physx::PxHeightFieldDesc*) _address;
    return (jint) _self->nbColumns;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxHeightFieldDesc__1setNbColumns(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxHeightFieldDesc* _self = (physx::PxHeightFieldDesc*) _address;
    _self->nbColumns = value;
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxHeightFieldDesc__1getFormat(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldDesc* _self = (physx::PxHeightFieldDesc*) _address;
    return (jint) _self->format;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxHeightFieldDesc__1setFormat(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxHeightFieldDesc* _self = (physx::PxHeightFieldDesc*) _address;
    _self->format = (PxHeightFieldFormatEnum) value;
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxHeightFieldDesc__1getSamples(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldDesc* _self = (physx::PxHeightFieldDesc*) _address;
    return (jlong) &_self->samples;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxHeightFieldDesc__1setSamples(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxHeightFieldDesc* _self = (physx::PxHeightFieldDesc*) _address;
    _self->samples = *((physx::PxStridedData*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_geometry_PxHeightFieldDesc__1getConvexEdgeThreshold(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldDesc* _self = (physx::PxHeightFieldDesc*) _address;
    return (jfloat) _self->convexEdgeThreshold;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxHeightFieldDesc__1setConvexEdgeThreshold(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxHeightFieldDesc* _self = (physx::PxHeightFieldDesc*) _address;
    _self->convexEdgeThreshold = value;
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxHeightFieldDesc__1getFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldDesc* _self = (physx::PxHeightFieldDesc*) _address;
    return (jlong) &_self->flags;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxHeightFieldDesc__1setFlags(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxHeightFieldDesc* _self = (physx::PxHeightFieldDesc*) _address;
    _self->flags = *((physx::PxHeightFieldFlags*) value);
}

// PxHeightFieldFlags
JNIEXPORT jint JNICALL Java_physx_geometry_PxHeightFieldFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxHeightFieldFlags);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxHeightFieldFlags__1_1placement_1new_1PxHeightFieldFlags(JNIEnv*, jclass, jlong _placement_address, jshort flags) {
    return (jlong) new((void*)_placement_address) physx::PxHeightFieldFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxHeightFieldFlags__1PxHeightFieldFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxHeightFieldFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_geometry_PxHeightFieldFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxHeightFieldFlags* self = (physx::PxHeightFieldFlags*) _address;
    return (jboolean) self->isSet((PxHeightFieldFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geometry_PxHeightFieldFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxHeightFieldFlags* self = (physx::PxHeightFieldFlags*) _address;
    self->raise((PxHeightFieldFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geometry_PxHeightFieldFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxHeightFieldFlags* self = (physx::PxHeightFieldFlags*) _address;
    self->clear((PxHeightFieldFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geometry_PxHeightFieldFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxHeightFieldFlags*) _address;
}

// PxHeightFieldGeometry
JNIEXPORT jint JNICALL Java_physx_geometry_PxHeightFieldGeometry__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxHeightFieldGeometry);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxHeightFieldGeometry__1_1placement_1new_1PxHeightFieldGeometry__J(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxHeightFieldGeometry();
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxHeightFieldGeometry__1_1placement_1new_1PxHeightFieldGeometry__JJJFFF(JNIEnv*, jclass, jlong _placement_address, jlong hf, jlong flags, jfloat heightScale, jfloat rowScale, jfloat columnScale) {
    return (jlong) new((void*)_placement_address) physx::PxHeightFieldGeometry((physx::PxHeightField*) hf, *((physx::PxMeshGeometryFlags*) flags), heightScale, rowScale, columnScale);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxHeightFieldGeometry__1PxHeightFieldGeometry__(JNIEnv*, jclass) {
    return (jlong) new physx::PxHeightFieldGeometry();
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxHeightFieldGeometry__1PxHeightFieldGeometry__JJFFF(JNIEnv*, jclass, jlong hf, jlong flags, jfloat heightScale, jfloat rowScale, jfloat columnScale) {
    return (jlong) new physx::PxHeightFieldGeometry((physx::PxHeightField*) hf, *((physx::PxMeshGeometryFlags*) flags), heightScale, rowScale, columnScale);
}
JNIEXPORT jboolean JNICALL Java_physx_geometry_PxHeightFieldGeometry__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldGeometry* self = (physx::PxHeightFieldGeometry*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_geometry_PxHeightFieldGeometry__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxHeightFieldGeometry*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxHeightFieldGeometry__1getHeightField(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldGeometry* _self = (physx::PxHeightFieldGeometry*) _address;
    return (jlong) _self->heightField;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxHeightFieldGeometry__1setHeightField(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxHeightFieldGeometry* _self = (physx::PxHeightFieldGeometry*) _address;
    _self->heightField = (physx::PxHeightField*) value;
}
JNIEXPORT jfloat JNICALL Java_physx_geometry_PxHeightFieldGeometry__1getHeightScale(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldGeometry* _self = (physx::PxHeightFieldGeometry*) _address;
    return (jfloat) _self->heightScale;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxHeightFieldGeometry__1setHeightScale(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxHeightFieldGeometry* _self = (physx::PxHeightFieldGeometry*) _address;
    _self->heightScale = value;
}
JNIEXPORT jfloat JNICALL Java_physx_geometry_PxHeightFieldGeometry__1getRowScale(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldGeometry* _self = (physx::PxHeightFieldGeometry*) _address;
    return (jfloat) _self->rowScale;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxHeightFieldGeometry__1setRowScale(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxHeightFieldGeometry* _self = (physx::PxHeightFieldGeometry*) _address;
    _self->rowScale = value;
}
JNIEXPORT jfloat JNICALL Java_physx_geometry_PxHeightFieldGeometry__1getColumnScale(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldGeometry* _self = (physx::PxHeightFieldGeometry*) _address;
    return (jfloat) _self->columnScale;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxHeightFieldGeometry__1setColumnScale(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxHeightFieldGeometry* _self = (physx::PxHeightFieldGeometry*) _address;
    _self->columnScale = value;
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxHeightFieldGeometry__1getHeightFieldFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldGeometry* _self = (physx::PxHeightFieldGeometry*) _address;
    return (jlong) &_self->heightFieldFlags;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxHeightFieldGeometry__1setHeightFieldFlags(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxHeightFieldGeometry* _self = (physx::PxHeightFieldGeometry*) _address;
    _self->heightFieldFlags = *((physx::PxMeshGeometryFlags*) value);
}

// PxHeightFieldSample
JNIEXPORT jint JNICALL Java_physx_geometry_PxHeightFieldSample__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxHeightFieldSample);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxHeightFieldSample__1_1placement_1new_1PxHeightFieldSample(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxHeightFieldSample();
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxHeightFieldSample__1PxHeightFieldSample(JNIEnv*, jclass) {
    return (jlong) new physx::PxHeightFieldSample();
}
JNIEXPORT jbyte JNICALL Java_physx_geometry_PxHeightFieldSample__1tessFlag(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldSample* self = (physx::PxHeightFieldSample*) _address;
    return (jbyte) self->tessFlag();
}
JNIEXPORT void JNICALL Java_physx_geometry_PxHeightFieldSample__1clearTessFlag(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldSample* self = (physx::PxHeightFieldSample*) _address;
    self->clearTessFlag();
}
JNIEXPORT void JNICALL Java_physx_geometry_PxHeightFieldSample__1setTessFlag(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldSample* self = (physx::PxHeightFieldSample*) _address;
    self->setTessFlag();
}
JNIEXPORT void JNICALL Java_physx_geometry_PxHeightFieldSample__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxHeightFieldSample*) _address;
}
JNIEXPORT jshort JNICALL Java_physx_geometry_PxHeightFieldSample__1getHeight(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldSample* _self = (physx::PxHeightFieldSample*) _address;
    return (jshort) _self->height;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxHeightFieldSample__1setHeight(JNIEnv*, jclass, jlong _address, jshort value) {
    physx::PxHeightFieldSample* _self = (physx::PxHeightFieldSample*) _address;
    _self->height = value;
}
JNIEXPORT jbyte JNICALL Java_physx_geometry_PxHeightFieldSample__1getMaterialIndex0(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldSample* _self = (physx::PxHeightFieldSample*) _address;
    return (jbyte) _self->materialIndex0;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxHeightFieldSample__1setMaterialIndex0(JNIEnv*, jclass, jlong _address, jbyte value) {
    physx::PxHeightFieldSample* _self = (physx::PxHeightFieldSample*) _address;
    _self->materialIndex0 = value;
}
JNIEXPORT jbyte JNICALL Java_physx_geometry_PxHeightFieldSample__1getMaterialIndex1(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldSample* _self = (physx::PxHeightFieldSample*) _address;
    return (jbyte) _self->materialIndex1;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxHeightFieldSample__1setMaterialIndex1(JNIEnv*, jclass, jlong _address, jbyte value) {
    physx::PxHeightFieldSample* _self = (physx::PxHeightFieldSample*) _address;
    _self->materialIndex1 = value;
}

// PxHullPolygon
JNIEXPORT jint JNICALL Java_physx_geometry_PxHullPolygon__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxHullPolygon);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxHullPolygon__1_1placement_1new_1PxHullPolygon(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxHullPolygon();
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxHullPolygon__1PxHullPolygon(JNIEnv*, jclass) {
    return (jlong) new physx::PxHullPolygon();
}
JNIEXPORT void JNICALL Java_physx_geometry_PxHullPolygon__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxHullPolygon*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_geometry_PxHullPolygon__1getMPlane(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::PxHullPolygon* _self = (physx::PxHullPolygon*) _address;
    return (jfloat) _self->mPlane[_index];
}
JNIEXPORT void JNICALL Java_physx_geometry_PxHullPolygon__1setMPlane(JNIEnv*, jclass, jlong _address, jint _index, jfloat value) {
    physx::PxHullPolygon* _self = (physx::PxHullPolygon*) _address;
    _self->mPlane[_index] = value;
}
JNIEXPORT jshort JNICALL Java_physx_geometry_PxHullPolygon__1getMNbVerts(JNIEnv*, jclass, jlong _address) {
    physx::PxHullPolygon* _self = (physx::PxHullPolygon*) _address;
    return (jshort) _self->mNbVerts;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxHullPolygon__1setMNbVerts(JNIEnv*, jclass, jlong _address, jshort value) {
    physx::PxHullPolygon* _self = (physx::PxHullPolygon*) _address;
    _self->mNbVerts = value;
}
JNIEXPORT jshort JNICALL Java_physx_geometry_PxHullPolygon__1getMIndexBase(JNIEnv*, jclass, jlong _address) {
    physx::PxHullPolygon* _self = (physx::PxHullPolygon*) _address;
    return (jshort) _self->mIndexBase;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxHullPolygon__1setMIndexBase(JNIEnv*, jclass, jlong _address, jshort value) {
    physx::PxHullPolygon* _self = (physx::PxHullPolygon*) _address;
    _self->mIndexBase = value;
}

// PxMeshFlags
JNIEXPORT jint JNICALL Java_physx_geometry_PxMeshFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxMeshFlags);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxMeshFlags__1_1placement_1new_1PxMeshFlags(JNIEnv*, jclass, jlong _placement_address, jbyte flags) {
    return (jlong) new((void*)_placement_address) physx::PxMeshFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxMeshFlags__1PxMeshFlags(JNIEnv*, jclass, jbyte flags) {
    return (jlong) new physx::PxMeshFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_geometry_PxMeshFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxMeshFlags* self = (physx::PxMeshFlags*) _address;
    return (jboolean) self->isSet((PxMeshFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geometry_PxMeshFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxMeshFlags* self = (physx::PxMeshFlags*) _address;
    self->raise((PxMeshFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geometry_PxMeshFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxMeshFlags* self = (physx::PxMeshFlags*) _address;
    self->clear((PxMeshFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geometry_PxMeshFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxMeshFlags*) _address;
}

// PxMeshGeometryFlags
JNIEXPORT jint JNICALL Java_physx_geometry_PxMeshGeometryFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxMeshGeometryFlags);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxMeshGeometryFlags__1_1placement_1new_1PxMeshGeometryFlags(JNIEnv*, jclass, jlong _placement_address, jbyte flags) {
    return (jlong) new((void*)_placement_address) physx::PxMeshGeometryFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxMeshGeometryFlags__1PxMeshGeometryFlags(JNIEnv*, jclass, jbyte flags) {
    return (jlong) new physx::PxMeshGeometryFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_geometry_PxMeshGeometryFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxMeshGeometryFlags* self = (physx::PxMeshGeometryFlags*) _address;
    return (jboolean) self->isSet((PxMeshGeometryFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geometry_PxMeshGeometryFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxMeshGeometryFlags* self = (physx::PxMeshGeometryFlags*) _address;
    self->raise((PxMeshGeometryFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geometry_PxMeshGeometryFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxMeshGeometryFlags* self = (physx::PxMeshGeometryFlags*) _address;
    self->clear((PxMeshGeometryFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geometry_PxMeshGeometryFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxMeshGeometryFlags*) _address;
}

// PxMeshScale
JNIEXPORT jint JNICALL Java_physx_geometry_PxMeshScale__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxMeshScale);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxMeshScale__1_1placement_1new_1PxMeshScale__J(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxMeshScale();
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxMeshScale__1_1placement_1new_1PxMeshScale__JF(JNIEnv*, jclass, jlong _placement_address, jfloat r) {
    return (jlong) new((void*)_placement_address) physx::PxMeshScale(r);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxMeshScale__1_1placement_1new_1PxMeshScale__JJJ(JNIEnv*, jclass, jlong _placement_address, jlong s, jlong r) {
    return (jlong) new((void*)_placement_address) physx::PxMeshScale(*((physx::PxVec3*) s), *((physx::PxQuat*) r));
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxMeshScale__1PxMeshScale__(JNIEnv*, jclass) {
    return (jlong) new physx::PxMeshScale();
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxMeshScale__1PxMeshScale__F(JNIEnv*, jclass, jfloat r) {
    return (jlong) new physx::PxMeshScale(r);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxMeshScale__1PxMeshScale__JJ(JNIEnv*, jclass, jlong s, jlong r) {
    return (jlong) new physx::PxMeshScale(*((physx::PxVec3*) s), *((physx::PxQuat*) r));
}
JNIEXPORT void JNICALL Java_physx_geometry_PxMeshScale__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxMeshScale*) _address;
}

// PxPlaneGeometry
JNIEXPORT jint JNICALL Java_physx_geometry_PxPlaneGeometry__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxPlaneGeometry);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxPlaneGeometry__1_1placement_1new_1PxPlaneGeometry(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxPlaneGeometry();
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxPlaneGeometry__1PxPlaneGeometry(JNIEnv*, jclass) {
    return (jlong) new physx::PxPlaneGeometry();
}
JNIEXPORT void JNICALL Java_physx_geometry_PxPlaneGeometry__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxPlaneGeometry*) _address;
}

// PxSimpleTriangleMesh
JNIEXPORT jint JNICALL Java_physx_geometry_PxSimpleTriangleMesh__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxSimpleTriangleMesh);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxSimpleTriangleMesh__1PxSimpleTriangleMesh(JNIEnv*, jclass) {
    return (jlong) new physx::PxSimpleTriangleMesh();
}
JNIEXPORT void JNICALL Java_physx_geometry_PxSimpleTriangleMesh__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::PxSimpleTriangleMesh* self = (physx::PxSimpleTriangleMesh*) _address;
    self->setToDefault();
}
JNIEXPORT jboolean JNICALL Java_physx_geometry_PxSimpleTriangleMesh__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxSimpleTriangleMesh* self = (physx::PxSimpleTriangleMesh*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_geometry_PxSimpleTriangleMesh__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSimpleTriangleMesh*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxSimpleTriangleMesh__1getPoints(JNIEnv*, jclass, jlong _address) {
    physx::PxSimpleTriangleMesh* _self = (physx::PxSimpleTriangleMesh*) _address;
    return (jlong) &_self->points;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxSimpleTriangleMesh__1setPoints(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSimpleTriangleMesh* _self = (physx::PxSimpleTriangleMesh*) _address;
    _self->points = *((physx::PxBoundedData*) value);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxSimpleTriangleMesh__1getTriangles(JNIEnv*, jclass, jlong _address) {
    physx::PxSimpleTriangleMesh* _self = (physx::PxSimpleTriangleMesh*) _address;
    return (jlong) &_self->triangles;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxSimpleTriangleMesh__1setTriangles(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSimpleTriangleMesh* _self = (physx::PxSimpleTriangleMesh*) _address;
    _self->triangles = *((physx::PxBoundedData*) value);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxSimpleTriangleMesh__1getFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxSimpleTriangleMesh* _self = (physx::PxSimpleTriangleMesh*) _address;
    return (jlong) &_self->flags;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxSimpleTriangleMesh__1setFlags(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSimpleTriangleMesh* _self = (physx::PxSimpleTriangleMesh*) _address;
    _self->flags = *((physx::PxMeshFlags*) value);
}

// PxSphereGeometry
JNIEXPORT jint JNICALL Java_physx_geometry_PxSphereGeometry__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxSphereGeometry);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxSphereGeometry__1_1placement_1new_1PxSphereGeometry(JNIEnv*, jclass, jlong _placement_address, jfloat ir) {
    return (jlong) new((void*)_placement_address) physx::PxSphereGeometry(ir);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxSphereGeometry__1PxSphereGeometry(JNIEnv*, jclass, jfloat ir) {
    return (jlong) new physx::PxSphereGeometry(ir);
}
JNIEXPORT void JNICALL Java_physx_geometry_PxSphereGeometry__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSphereGeometry*) _address;
}

// PxTriangle
JNIEXPORT jint JNICALL Java_physx_geometry_PxTriangle__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxTriangle);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxTriangle__1PxTriangle__(JNIEnv*, jclass) {
    return (jlong) new physx::PxTriangle();
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxTriangle__1PxTriangle__JJJ(JNIEnv*, jclass, jlong p0, jlong p1, jlong p2) {
    return (jlong) new physx::PxTriangle(*((physx::PxVec3*) p0), *((physx::PxVec3*) p1), *((physx::PxVec3*) p2));
}
JNIEXPORT void JNICALL Java_physx_geometry_PxTriangle__1normal(JNIEnv*, jclass, jlong _address, jlong normal) {
    physx::PxTriangle* self = (physx::PxTriangle*) _address;
    self->normal(*((physx::PxVec3*) normal));
}
JNIEXPORT void JNICALL Java_physx_geometry_PxTriangle__1denormalizedNormal(JNIEnv*, jclass, jlong _address, jlong normal) {
    physx::PxTriangle* self = (physx::PxTriangle*) _address;
    self->denormalizedNormal(*((physx::PxVec3*) normal));
}
JNIEXPORT jfloat JNICALL Java_physx_geometry_PxTriangle__1area(JNIEnv*, jclass, jlong _address) {
    physx::PxTriangle* self = (physx::PxTriangle*) _address;
    return (jfloat) self->area();
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxTriangle__1pointFromUV(JNIEnv*, jclass, jlong _address, jfloat u, jfloat v) {
    physx::PxTriangle* self = (physx::PxTriangle*) _address;
    static thread_local physx::PxVec3 _cache = self->pointFromUV(u, v);
    _cache = self->pointFromUV(u, v);
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_geometry_PxTriangle__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxTriangle*) _address;
}

// PxTriangleMesh
JNIEXPORT jint JNICALL Java_physx_geometry_PxTriangleMesh__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxTriangleMesh);
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxTriangleMesh__1getNbVertices(JNIEnv*, jclass, jlong _address) {
    physx::PxTriangleMesh* self = (physx::PxTriangleMesh*) _address;
    return (jint) self->getNbVertices();
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxTriangleMesh__1getVertices(JNIEnv*, jclass, jlong _address) {
    physx::PxTriangleMesh* self = (physx::PxTriangleMesh*) _address;
    return (jlong) self->getVertices();
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxTriangleMesh__1getVerticesForModification(JNIEnv*, jclass, jlong _address) {
    physx::PxTriangleMesh* self = (physx::PxTriangleMesh*) _address;
    return (jlong) self->getVerticesForModification();
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxTriangleMesh__1refitBVH(JNIEnv*, jclass, jlong _address) {
    physx::PxTriangleMesh* self = (physx::PxTriangleMesh*) _address;
    static thread_local physx::PxBounds3 _cache = self->refitBVH();
    _cache = self->refitBVH();
    return (jlong) &_cache;
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxTriangleMesh__1getNbTriangles(JNIEnv*, jclass, jlong _address) {
    physx::PxTriangleMesh* self = (physx::PxTriangleMesh*) _address;
    return (jint) self->getNbTriangles();
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxTriangleMesh__1getTriangles(JNIEnv*, jclass, jlong _address) {
    physx::PxTriangleMesh* self = (physx::PxTriangleMesh*) _address;
    return (jlong) self->getTriangles();
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxTriangleMesh__1getTriangleMeshFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxTriangleMesh* self = (physx::PxTriangleMesh*) _address;
    static thread_local physx::PxTriangleMeshFlags _cache = self->getTriangleMeshFlags();
    _cache = self->getTriangleMeshFlags();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxTriangleMesh__1getTrianglesRemap(JNIEnv*, jclass, jlong _address) {
    physx::PxTriangleMesh* self = (physx::PxTriangleMesh*) _address;
    static thread_local PxU32ConstPtr _cache = self->getTrianglesRemap();
    _cache = self->getTrianglesRemap();
    return (jlong) &_cache;
}
JNIEXPORT jshort JNICALL Java_physx_geometry_PxTriangleMesh__1getTriangleMaterialIndex(JNIEnv*, jclass, jlong _address, jint triangleIndex) {
    physx::PxTriangleMesh* self = (physx::PxTriangleMesh*) _address;
    return (jshort) self->getTriangleMaterialIndex(triangleIndex);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxTriangleMesh__1getLocalBounds(JNIEnv*, jclass, jlong _address) {
    physx::PxTriangleMesh* self = (physx::PxTriangleMesh*) _address;
    static thread_local physx::PxBounds3 _cache = self->getLocalBounds();
    _cache = self->getLocalBounds();
    return (jlong) &_cache;
}

// PxTriangleMeshFlags
JNIEXPORT jint JNICALL Java_physx_geometry_PxTriangleMeshFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxTriangleMeshFlags);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxTriangleMeshFlags__1_1placement_1new_1PxTriangleMeshFlags(JNIEnv*, jclass, jlong _placement_address, jbyte flags) {
    return (jlong) new((void*)_placement_address) physx::PxTriangleMeshFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxTriangleMeshFlags__1PxTriangleMeshFlags(JNIEnv*, jclass, jbyte flags) {
    return (jlong) new physx::PxTriangleMeshFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_geometry_PxTriangleMeshFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxTriangleMeshFlags* self = (physx::PxTriangleMeshFlags*) _address;
    return (jboolean) self->isSet((PxTriangleMeshFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geometry_PxTriangleMeshFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxTriangleMeshFlags* self = (physx::PxTriangleMeshFlags*) _address;
    self->raise((PxTriangleMeshFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geometry_PxTriangleMeshFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxTriangleMeshFlags* self = (physx::PxTriangleMeshFlags*) _address;
    self->clear((PxTriangleMeshFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geometry_PxTriangleMeshFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxTriangleMeshFlags*) _address;
}

// PxTriangleMeshGeometry
JNIEXPORT jint JNICALL Java_physx_geometry_PxTriangleMeshGeometry__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxTriangleMeshGeometry);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxTriangleMeshGeometry__1_1placement_1new_1PxTriangleMeshGeometry__JJ(JNIEnv*, jclass, jlong _placement_address, jlong mesh) {
    return (jlong) new((void*)_placement_address) physx::PxTriangleMeshGeometry((physx::PxTriangleMesh*) mesh);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxTriangleMeshGeometry__1_1placement_1new_1PxTriangleMeshGeometry__JJJ(JNIEnv*, jclass, jlong _placement_address, jlong mesh, jlong scaling) {
    return (jlong) new((void*)_placement_address) physx::PxTriangleMeshGeometry((physx::PxTriangleMesh*) mesh, *((physx::PxMeshScale*) scaling));
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxTriangleMeshGeometry__1_1placement_1new_1PxTriangleMeshGeometry__JJJJ(JNIEnv*, jclass, jlong _placement_address, jlong mesh, jlong scaling, jlong flags) {
    return (jlong) new((void*)_placement_address) physx::PxTriangleMeshGeometry((physx::PxTriangleMesh*) mesh, *((physx::PxMeshScale*) scaling), *((physx::PxMeshGeometryFlags*) flags));
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxTriangleMeshGeometry__1PxTriangleMeshGeometry__J(JNIEnv*, jclass, jlong mesh) {
    return (jlong) new physx::PxTriangleMeshGeometry((physx::PxTriangleMesh*) mesh);
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxTriangleMeshGeometry__1PxTriangleMeshGeometry__JJ(JNIEnv*, jclass, jlong mesh, jlong scaling) {
    return (jlong) new physx::PxTriangleMeshGeometry((physx::PxTriangleMesh*) mesh, *((physx::PxMeshScale*) scaling));
}
JNIEXPORT jlong JNICALL Java_physx_geometry_PxTriangleMeshGeometry__1PxTriangleMeshGeometry__JJJ(JNIEnv*, jclass, jlong mesh, jlong scaling, jlong flags) {
    return (jlong) new physx::PxTriangleMeshGeometry((physx::PxTriangleMesh*) mesh, *((physx::PxMeshScale*) scaling), *((physx::PxMeshGeometryFlags*) flags));
}
JNIEXPORT jboolean JNICALL Java_physx_geometry_PxTriangleMeshGeometry__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxTriangleMeshGeometry* self = (physx::PxTriangleMeshGeometry*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_geometry_PxTriangleMeshGeometry__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxTriangleMeshGeometry*) _address;
}

// PxConvexMeshGeometryFlagEnum
JNIEXPORT jint JNICALL Java_physx_geometry_PxConvexMeshGeometryFlagEnum__1geteTIGHT_1BOUNDS(JNIEnv*, jclass) {
    return PxConvexMeshGeometryFlagEnum::eTIGHT_BOUNDS;
}

// PxGeometryTypeEnum
JNIEXPORT jint JNICALL Java_physx_geometry_PxGeometryTypeEnum__1geteSPHERE(JNIEnv*, jclass) {
    return PxGeometryTypeEnum::eSPHERE;
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxGeometryTypeEnum__1getePLANE(JNIEnv*, jclass) {
    return PxGeometryTypeEnum::ePLANE;
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxGeometryTypeEnum__1geteCAPSULE(JNIEnv*, jclass) {
    return PxGeometryTypeEnum::eCAPSULE;
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxGeometryTypeEnum__1geteBOX(JNIEnv*, jclass) {
    return PxGeometryTypeEnum::eBOX;
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxGeometryTypeEnum__1geteCONVEXMESH(JNIEnv*, jclass) {
    return PxGeometryTypeEnum::eCONVEXMESH;
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxGeometryTypeEnum__1geteTRIANGLEMESH(JNIEnv*, jclass) {
    return PxGeometryTypeEnum::eTRIANGLEMESH;
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxGeometryTypeEnum__1geteHEIGHTFIELD(JNIEnv*, jclass) {
    return PxGeometryTypeEnum::eHEIGHTFIELD;
}

// PxHeightFieldFlagEnum
JNIEXPORT jint JNICALL Java_physx_geometry_PxHeightFieldFlagEnum__1geteNO_1BOUNDARY_1EDGES(JNIEnv*, jclass) {
    return PxHeightFieldFlagEnum::eNO_BOUNDARY_EDGES;
}

// PxHeightFieldFormatEnum
JNIEXPORT jint JNICALL Java_physx_geometry_PxHeightFieldFormatEnum__1geteS16_1TM(JNIEnv*, jclass) {
    return PxHeightFieldFormatEnum::eS16_TM;
}

// PxMeshFlagEnum
JNIEXPORT jint JNICALL Java_physx_geometry_PxMeshFlagEnum__1geteFLIPNORMALS(JNIEnv*, jclass) {
    return PxMeshFlagEnum::eFLIPNORMALS;
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxMeshFlagEnum__1gete16_1BIT_1INDICES(JNIEnv*, jclass) {
    return PxMeshFlagEnum::e16_BIT_INDICES;
}

// PxMeshGeometryFlagEnum
JNIEXPORT jint JNICALL Java_physx_geometry_PxMeshGeometryFlagEnum__1geteDOUBLE_1SIDED(JNIEnv*, jclass) {
    return PxMeshGeometryFlagEnum::eDOUBLE_SIDED;
}

// PxTriangleMeshFlagEnum
JNIEXPORT jint JNICALL Java_physx_geometry_PxTriangleMeshFlagEnum__1gete16_1BIT_1INDICES(JNIEnv*, jclass) {
    return PxTriangleMeshFlagEnum::e16_BIT_INDICES;
}
JNIEXPORT jint JNICALL Java_physx_geometry_PxTriangleMeshFlagEnum__1geteADJACENCY_1INFO(JNIEnv*, jclass) {
    return PxTriangleMeshFlagEnum::eADJACENCY_INFO;
}

// PxActor
JNIEXPORT jint JNICALL Java_physx_physics_PxActor__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxActor);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxActor__1getType(JNIEnv*, jclass, jlong _address) {
    physx::PxActor* self = (physx::PxActor*) _address;
    return (jint) self->getType();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxActor__1getScene(JNIEnv*, jclass, jlong _address) {
    physx::PxActor* self = (physx::PxActor*) _address;
    return (jlong) self->getScene();
}
JNIEXPORT void JNICALL Java_physx_physics_PxActor__1setName(JNIEnv* _env, jclass, jlong _address, jstring name) {
    physx::PxActor* self = (physx::PxActor*) _address;
    self->setName(_env->GetStringUTFChars(name, 0));
}
JNIEXPORT jstring JNICALL Java_physx_physics_PxActor__1getName(JNIEnv* _env, jclass, jlong _address) {
    physx::PxActor* self = (physx::PxActor*) _address;
    return _env->NewStringUTF(self->getName());
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxActor__1getWorldBounds__J(JNIEnv*, jclass, jlong _address) {
    physx::PxActor* self = (physx::PxActor*) _address;
    static thread_local physx::PxBounds3 _cache = self->getWorldBounds();
    _cache = self->getWorldBounds();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxActor__1getWorldBounds__JF(JNIEnv*, jclass, jlong _address, jfloat inflation) {
    physx::PxActor* self = (physx::PxActor*) _address;
    static thread_local physx::PxBounds3 _cache = self->getWorldBounds(inflation);
    _cache = self->getWorldBounds(inflation);
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxActor__1setActorFlag(JNIEnv*, jclass, jlong _address, jint flag, jboolean value) {
    physx::PxActor* self = (physx::PxActor*) _address;
    self->setActorFlag((PxActorFlagEnum) flag, value);
}
JNIEXPORT void JNICALL Java_physx_physics_PxActor__1setActorFlags(JNIEnv*, jclass, jlong _address, jlong flags) {
    physx::PxActor* self = (physx::PxActor*) _address;
    self->setActorFlags(*((physx::PxActorFlags*) flags));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxActor__1getActorFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxActor* self = (physx::PxActor*) _address;
    static thread_local physx::PxActorFlags _cache = self->getActorFlags();
    _cache = self->getActorFlags();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxActor__1setDominanceGroup(JNIEnv*, jclass, jlong _address, jbyte dominanceGroup) {
    physx::PxActor* self = (physx::PxActor*) _address;
    self->setDominanceGroup(dominanceGroup);
}
JNIEXPORT jbyte JNICALL Java_physx_physics_PxActor__1getDominanceGroup(JNIEnv*, jclass, jlong _address) {
    physx::PxActor* self = (physx::PxActor*) _address;
    return (jbyte) self->getDominanceGroup();
}
JNIEXPORT void JNICALL Java_physx_physics_PxActor__1setOwnerClient(JNIEnv*, jclass, jlong _address, jbyte inClient) {
    physx::PxActor* self = (physx::PxActor*) _address;
    self->setOwnerClient(inClient);
}
JNIEXPORT jbyte JNICALL Java_physx_physics_PxActor__1getOwnerClient(JNIEnv*, jclass, jlong _address) {
    physx::PxActor* self = (physx::PxActor*) _address;
    return (jbyte) self->getOwnerClient();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxActor__1getUserData(JNIEnv*, jclass, jlong _address) {
    physx::PxActor* _self = (physx::PxActor*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_physx_physics_PxActor__1setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxActor* _self = (physx::PxActor*) _address;
    _self->userData = (void*) value;
}

// PxActorFlags
JNIEXPORT jint JNICALL Java_physx_physics_PxActorFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxActorFlags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxActorFlags__1_1placement_1new_1PxActorFlags(JNIEnv*, jclass, jlong _placement_address, jbyte flags) {
    return (jlong) new((void*)_placement_address) physx::PxActorFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxActorFlags__1PxActorFlags(JNIEnv*, jclass, jbyte flags) {
    return (jlong) new physx::PxActorFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxActorFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxActorFlags* self = (physx::PxActorFlags*) _address;
    return (jboolean) self->isSet((PxActorFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxActorFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxActorFlags* self = (physx::PxActorFlags*) _address;
    self->raise((PxActorFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxActorFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxActorFlags* self = (physx::PxActorFlags*) _address;
    self->clear((PxActorFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxActorFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxActorFlags*) _address;
}

// PxActorTypeFlags
JNIEXPORT jint JNICALL Java_physx_physics_PxActorTypeFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxActorTypeFlags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxActorTypeFlags__1_1placement_1new_1PxActorTypeFlags(JNIEnv*, jclass, jlong _placement_address, jshort flags) {
    return (jlong) new((void*)_placement_address) physx::PxActorTypeFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxActorTypeFlags__1PxActorTypeFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxActorTypeFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxActorTypeFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxActorTypeFlags* self = (physx::PxActorTypeFlags*) _address;
    return (jboolean) self->isSet((PxActorTypeFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxActorTypeFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxActorTypeFlags* self = (physx::PxActorTypeFlags*) _address;
    self->raise((PxActorTypeFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxActorTypeFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxActorTypeFlags* self = (physx::PxActorTypeFlags*) _address;
    self->clear((PxActorTypeFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxActorTypeFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxActorTypeFlags*) _address;
}

// PxRigidActor
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidActor__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxRigidActor);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidActor__1getGlobalPose(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidActor* self = (physx::PxRigidActor*) _address;
    static thread_local physx::PxTransform _cache = self->getGlobalPose();
    _cache = self->getGlobalPose();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidActor__1setGlobalPose__JJ(JNIEnv*, jclass, jlong _address, jlong pose) {
    physx::PxRigidActor* self = (physx::PxRigidActor*) _address;
    self->setGlobalPose(*((physx::PxTransform*) pose));
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidActor__1setGlobalPose__JJZ(JNIEnv*, jclass, jlong _address, jlong pose, jboolean autowake) {
    physx::PxRigidActor* self = (physx::PxRigidActor*) _address;
    self->setGlobalPose(*((physx::PxTransform*) pose), autowake);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxRigidActor__1attachShape(JNIEnv*, jclass, jlong _address, jlong shape) {
    physx::PxRigidActor* self = (physx::PxRigidActor*) _address;
    return (jboolean) self->attachShape(*((physx::PxShape*) shape));
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidActor__1detachShape__JJ(JNIEnv*, jclass, jlong _address, jlong shape) {
    physx::PxRigidActor* self = (physx::PxRigidActor*) _address;
    self->detachShape(*((physx::PxShape*) shape));
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidActor__1detachShape__JJZ(JNIEnv*, jclass, jlong _address, jlong shape, jboolean wakeOnLostTouch) {
    physx::PxRigidActor* self = (physx::PxRigidActor*) _address;
    self->detachShape(*((physx::PxShape*) shape), wakeOnLostTouch);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidActor__1getNbShapes(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidActor* self = (physx::PxRigidActor*) _address;
    return (jint) self->getNbShapes();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidActor__1getNbConstraints(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidActor* self = (physx::PxRigidActor*) _address;
    return (jint) self->getNbConstraints();
}

// PxRigidBody
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidBody__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxRigidBody);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setCMassLocalPose(JNIEnv*, jclass, jlong _address, jlong pose) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setCMassLocalPose(*((physx::PxTransform*) pose));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidBody__1getCMassLocalPose(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    static thread_local physx::PxTransform _cache = self->getCMassLocalPose();
    _cache = self->getCMassLocalPose();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setMass(JNIEnv*, jclass, jlong _address, jfloat mass) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setMass(mass);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getMass(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    return (jfloat) self->getMass();
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getInvMass(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    return (jfloat) self->getInvMass();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setMassSpaceInertiaTensor(JNIEnv*, jclass, jlong _address, jlong m) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setMassSpaceInertiaTensor(*((physx::PxVec3*) m));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidBody__1getMassSpaceInertiaTensor(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    static thread_local physx::PxVec3 _cache = self->getMassSpaceInertiaTensor();
    _cache = self->getMassSpaceInertiaTensor();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidBody__1getMassSpaceInvInertiaTensor(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    static thread_local physx::PxVec3 _cache = self->getMassSpaceInvInertiaTensor();
    _cache = self->getMassSpaceInvInertiaTensor();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setLinearDamping(JNIEnv*, jclass, jlong _address, jfloat linDamp) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setLinearDamping(linDamp);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getLinearDamping(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    return (jfloat) self->getLinearDamping();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setAngularDamping(JNIEnv*, jclass, jlong _address, jfloat angDamp) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setAngularDamping(angDamp);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getAngularDamping(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    return (jfloat) self->getAngularDamping();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidBody__1getLinearVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    static thread_local physx::PxVec3 _cache = self->getLinearVelocity();
    _cache = self->getLinearVelocity();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidBody__1getAngularVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    static thread_local physx::PxVec3 _cache = self->getAngularVelocity();
    _cache = self->getAngularVelocity();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setMaxLinearVelocity(JNIEnv*, jclass, jlong _address, jfloat maxLinVel) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setMaxLinearVelocity(maxLinVel);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getMaxLinearVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    return (jfloat) self->getMaxLinearVelocity();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setMaxAngularVelocity(JNIEnv*, jclass, jlong _address, jfloat maxAngVel) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setMaxAngularVelocity(maxAngVel);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getMaxAngularVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    return (jfloat) self->getMaxAngularVelocity();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1addForce__JJ(JNIEnv*, jclass, jlong _address, jlong force) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->addForce(*((physx::PxVec3*) force));
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1addForce__JJI(JNIEnv*, jclass, jlong _address, jlong force, jint mode) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->addForce(*((physx::PxVec3*) force), (PxForceModeEnum) mode);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1addForce__JJIZ(JNIEnv*, jclass, jlong _address, jlong force, jint mode, jboolean autowake) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->addForce(*((physx::PxVec3*) force), (PxForceModeEnum) mode, autowake);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1addTorque__JJ(JNIEnv*, jclass, jlong _address, jlong torque) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->addTorque(*((physx::PxVec3*) torque));
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1addTorque__JJI(JNIEnv*, jclass, jlong _address, jlong torque, jint mode) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->addTorque(*((physx::PxVec3*) torque), (PxForceModeEnum) mode);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1addTorque__JJIZ(JNIEnv*, jclass, jlong _address, jlong torque, jint mode, jboolean autowake) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->addTorque(*((physx::PxVec3*) torque), (PxForceModeEnum) mode, autowake);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1clearForce(JNIEnv*, jclass, jlong _address, jint mode) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->clearForce((PxForceModeEnum) mode);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1clearTorque(JNIEnv*, jclass, jlong _address, jint mode) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->clearTorque((PxForceModeEnum) mode);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setForceAndTorque__JJJ(JNIEnv*, jclass, jlong _address, jlong force, jlong torque) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setForceAndTorque(*((physx::PxVec3*) force), *((physx::PxVec3*) torque));
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setForceAndTorque__JJJI(JNIEnv*, jclass, jlong _address, jlong force, jlong torque, jint mode) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setForceAndTorque(*((physx::PxVec3*) force), *((physx::PxVec3*) torque), (PxForceModeEnum) mode);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setRigidBodyFlag(JNIEnv*, jclass, jlong _address, jint flag, jboolean value) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setRigidBodyFlag((PxRigidBodyFlagEnum) flag, value);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setRigidBodyFlags(JNIEnv*, jclass, jlong _address, jlong inFlags) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setRigidBodyFlags(*((physx::PxRigidBodyFlags*) inFlags));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidBody__1getRigidBodyFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    static thread_local physx::PxRigidBodyFlags _cache = self->getRigidBodyFlags();
    _cache = self->getRigidBodyFlags();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setMinCCDAdvanceCoefficient(JNIEnv*, jclass, jlong _address, jfloat advanceCoefficient) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setMinCCDAdvanceCoefficient(advanceCoefficient);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getMinCCDAdvanceCoefficient(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    return (jfloat) self->getMinCCDAdvanceCoefficient();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setMaxDepenetrationVelocity(JNIEnv*, jclass, jlong _address, jfloat biasClamp) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setMaxDepenetrationVelocity(biasClamp);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getMaxDepenetrationVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    return (jfloat) self->getMaxDepenetrationVelocity();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setMaxContactImpulse(JNIEnv*, jclass, jlong _address, jfloat maxImpulse) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setMaxContactImpulse(maxImpulse);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getMaxContactImpulse(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    return (jfloat) self->getMaxContactImpulse();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setContactSlopCoefficient(JNIEnv*, jclass, jlong _address, jfloat slopCoefficient) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setContactSlopCoefficient(slopCoefficient);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getContactSlopCoefficient(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    return (jfloat) self->getContactSlopCoefficient();
}

// PxRigidBodyFlags
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidBodyFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxRigidBodyFlags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidBodyFlags__1_1placement_1new_1PxRigidBodyFlags(JNIEnv*, jclass, jlong _placement_address, jbyte flags) {
    return (jlong) new((void*)_placement_address) physx::PxRigidBodyFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidBodyFlags__1PxRigidBodyFlags(JNIEnv*, jclass, jbyte flags) {
    return (jlong) new physx::PxRigidBodyFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxRigidBodyFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxRigidBodyFlags* self = (physx::PxRigidBodyFlags*) _address;
    return (jboolean) self->isSet((PxRigidBodyFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBodyFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxRigidBodyFlags* self = (physx::PxRigidBodyFlags*) _address;
    self->raise((PxRigidBodyFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBodyFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxRigidBodyFlags* self = (physx::PxRigidBodyFlags*) _address;
    self->clear((PxRigidBodyFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBodyFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxRigidBodyFlags*) _address;
}

// PxRigidDynamic
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidDynamic__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxRigidDynamic);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setKinematicTarget(JNIEnv*, jclass, jlong _address, jlong destination) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    self->setKinematicTarget(*((physx::PxTransform*) destination));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxRigidDynamic__1getKinematicTarget(JNIEnv*, jclass, jlong _address, jlong target) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    return (jboolean) self->getKinematicTarget(*((physx::PxTransform*) target));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxRigidDynamic__1isSleeping(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    return (jboolean) self->isSleeping();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setSleepThreshold(JNIEnv*, jclass, jlong _address, jfloat threshold) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    self->setSleepThreshold(threshold);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidDynamic__1getSleepThreshold(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    return (jfloat) self->getSleepThreshold();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setStabilizationThreshold(JNIEnv*, jclass, jlong _address, jfloat threshold) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    self->setStabilizationThreshold(threshold);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidDynamic__1getStabilizationThreshold(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    return (jfloat) self->getStabilizationThreshold();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidDynamic__1getRigidDynamicLockFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    static thread_local physx::PxRigidDynamicLockFlags _cache = self->getRigidDynamicLockFlags();
    _cache = self->getRigidDynamicLockFlags();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setRigidDynamicLockFlag(JNIEnv*, jclass, jlong _address, jint flag, jboolean value) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    self->setRigidDynamicLockFlag((PxRigidDynamicLockFlagEnum) flag, value);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setRigidDynamicLockFlags(JNIEnv*, jclass, jlong _address, jlong flags) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    self->setRigidDynamicLockFlags(*((physx::PxRigidDynamicLockFlags*) flags));
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setLinearVelocity__JJ(JNIEnv*, jclass, jlong _address, jlong linVel) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    self->setLinearVelocity(*((physx::PxVec3*) linVel));
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setLinearVelocity__JJZ(JNIEnv*, jclass, jlong _address, jlong linVel, jboolean autowake) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    self->setLinearVelocity(*((physx::PxVec3*) linVel), autowake);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setAngularVelocity__JJ(JNIEnv*, jclass, jlong _address, jlong angVel) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    self->setAngularVelocity(*((physx::PxVec3*) angVel));
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setAngularVelocity__JJZ(JNIEnv*, jclass, jlong _address, jlong angVel, jboolean autowake) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    self->setAngularVelocity(*((physx::PxVec3*) angVel), autowake);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setWakeCounter(JNIEnv*, jclass, jlong _address, jfloat wakeCounterValue) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    self->setWakeCounter(wakeCounterValue);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidDynamic__1getWakeCounter(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    return (jfloat) self->getWakeCounter();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1wakeUp(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    self->wakeUp();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1putToSleep(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    self->putToSleep();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setSolverIterationCounts__JI(JNIEnv*, jclass, jlong _address, jint minPositionIters) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    self->setSolverIterationCounts(minPositionIters);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setSolverIterationCounts__JII(JNIEnv*, jclass, jlong _address, jint minPositionIters, jint minVelocityIters) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    self->setSolverIterationCounts(minPositionIters, minVelocityIters);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidDynamic__1getContactReportThreshold(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    return (jfloat) self->getContactReportThreshold();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setContactReportThreshold(JNIEnv*, jclass, jlong _address, jfloat threshold) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    self->setContactReportThreshold(threshold);
}

// PxRigidDynamicLockFlags
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidDynamicLockFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxRigidDynamicLockFlags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidDynamicLockFlags__1_1placement_1new_1PxRigidDynamicLockFlags(JNIEnv*, jclass, jlong _placement_address, jbyte flags) {
    return (jlong) new((void*)_placement_address) physx::PxRigidDynamicLockFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidDynamicLockFlags__1PxRigidDynamicLockFlags(JNIEnv*, jclass, jbyte flags) {
    return (jlong) new physx::PxRigidDynamicLockFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxRigidDynamicLockFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxRigidDynamicLockFlags* self = (physx::PxRigidDynamicLockFlags*) _address;
    return (jboolean) self->isSet((PxRigidDynamicLockFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamicLockFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxRigidDynamicLockFlags* self = (physx::PxRigidDynamicLockFlags*) _address;
    self->raise((PxRigidDynamicLockFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamicLockFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxRigidDynamicLockFlags* self = (physx::PxRigidDynamicLockFlags*) _address;
    self->clear((PxRigidDynamicLockFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamicLockFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxRigidDynamicLockFlags*) _address;
}

// PxRigidStatic
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidStatic__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxRigidStatic);
}

// PxArticulationAttachment
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationAttachment__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxArticulationAttachment);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationAttachment__1setRestLength(JNIEnv*, jclass, jlong _address, jfloat restLength) {
    physx::PxArticulationAttachment* self = (physx::PxArticulationAttachment*) _address;
    self->setRestLength(restLength);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationAttachment__1getRestLength(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationAttachment* self = (physx::PxArticulationAttachment*) _address;
    return (jfloat) self->getRestLength();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationAttachment__1setLimitParameters(JNIEnv*, jclass, jlong _address, jlong parameters) {
    physx::PxArticulationAttachment* self = (physx::PxArticulationAttachment*) _address;
    self->setLimitParameters(*((physx::PxArticulationTendonLimit*) parameters));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationAttachment__1getLimitParameters(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationAttachment* self = (physx::PxArticulationAttachment*) _address;
    static thread_local physx::PxArticulationTendonLimit _cache = self->getLimitParameters();
    _cache = self->getLimitParameters();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationAttachment__1setRelativeOffset(JNIEnv*, jclass, jlong _address, jlong offset) {
    physx::PxArticulationAttachment* self = (physx::PxArticulationAttachment*) _address;
    self->setRelativeOffset(*((physx::PxVec3*) offset));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationAttachment__1getRelativeOffset(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationAttachment* self = (physx::PxArticulationAttachment*) _address;
    static thread_local physx::PxVec3 _cache = self->getRelativeOffset();
    _cache = self->getRelativeOffset();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationAttachment__1setCoefficient(JNIEnv*, jclass, jlong _address, jfloat coefficient) {
    physx::PxArticulationAttachment* self = (physx::PxArticulationAttachment*) _address;
    self->setCoefficient(coefficient);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationAttachment__1getCoefficient(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationAttachment* self = (physx::PxArticulationAttachment*) _address;
    return (jfloat) self->getCoefficient();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationAttachment__1getLink(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationAttachment* self = (physx::PxArticulationAttachment*) _address;
    return (jlong) self->getLink();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationAttachment__1getParent(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationAttachment* self = (physx::PxArticulationAttachment*) _address;
    return (jlong) self->getParent();
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxArticulationAttachment__1isLeaf(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationAttachment* self = (physx::PxArticulationAttachment*) _address;
    return (jboolean) self->isLeaf();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationAttachment__1getTendon(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationAttachment* self = (physx::PxArticulationAttachment*) _address;
    return (jlong) self->getTendon();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationAttachment__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationAttachment* self = (physx::PxArticulationAttachment*) _address;
    self->release();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationAttachment__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxArticulationAttachment*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationAttachment__1getUserData(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationAttachment* _self = (physx::PxArticulationAttachment*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationAttachment__1setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxArticulationAttachment* _self = (physx::PxArticulationAttachment*) _address;
    _self->userData = (void*) value;
}

// PxArticulationCache
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationCache__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxArticulationCache);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationCache__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationCache* self = (physx::PxArticulationCache*) _address;
    self->release();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationCache__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxArticulationCache*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationCache__1getExternalForces(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    return (jlong) _self->externalForces;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationCache__1setExternalForces(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    _self->externalForces = (physx::PxSpatialForce*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationCache__1getDenseJacobian(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    return (jlong) &_self->denseJacobian;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationCache__1setDenseJacobian(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    _self->denseJacobian = *((PxRealPtr*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationCache__1getMassMatrix(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    return (jlong) &_self->massMatrix;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationCache__1setMassMatrix(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    _self->massMatrix = *((PxRealPtr*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationCache__1getJointVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    return (jlong) &_self->jointVelocity;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationCache__1setJointVelocity(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    _self->jointVelocity = *((PxRealPtr*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationCache__1getJointAcceleration(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    return (jlong) &_self->jointAcceleration;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationCache__1setJointAcceleration(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    _self->jointAcceleration = *((PxRealPtr*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationCache__1getJointPosition(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    return (jlong) &_self->jointPosition;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationCache__1setJointPosition(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    _self->jointPosition = *((PxRealPtr*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationCache__1getJointForce(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    return (jlong) &_self->jointForce;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationCache__1setJointForce(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    _self->jointForce = *((PxRealPtr*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationCache__1getLinkVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    return (jlong) _self->linkVelocity;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationCache__1setLinkVelocity(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    _self->linkVelocity = (physx::PxSpatialVelocity*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationCache__1getLinkAcceleration(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    return (jlong) _self->linkAcceleration;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationCache__1setLinkAcceleration(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    _self->linkAcceleration = (physx::PxSpatialVelocity*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationCache__1getRootLinkData(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    return (jlong) _self->rootLinkData;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationCache__1setRootLinkData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    _self->rootLinkData = (physx::PxArticulationRootLinkData*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationCache__1getSensorForces(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    return (jlong) _self->sensorForces;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationCache__1setSensorForces(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    _self->sensorForces = (physx::PxSpatialForce*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationCache__1getCoefficientMatrix(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    return (jlong) &_self->coefficientMatrix;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationCache__1setCoefficientMatrix(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    _self->coefficientMatrix = *((PxRealPtr*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationCache__1getLambda(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    return (jlong) &_self->lambda;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationCache__1setLambda(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    _self->lambda = *((PxRealPtr*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationCache__1getScratchMemory(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    return (jlong) _self->scratchMemory;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationCache__1setScratchMemory(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    _self->scratchMemory = (void*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationCache__1getScratchAllocator(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    return (jlong) _self->scratchAllocator;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationCache__1setScratchAllocator(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    _self->scratchAllocator = (void*) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationCache__1getVersion(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    return (jint) _self->version;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationCache__1setVersion(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxArticulationCache* _self = (physx::PxArticulationCache*) _address;
    _self->version = value;
}

// PxArticulationCacheFlags
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationCacheFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxArticulationCacheFlags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationCacheFlags__1_1placement_1new_1PxArticulationCacheFlags(JNIEnv*, jclass, jlong _placement_address, jint flags) {
    return (jlong) new((void*)_placement_address) physx::PxArticulationCacheFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationCacheFlags__1PxArticulationCacheFlags(JNIEnv*, jclass, jint flags) {
    return (jlong) new physx::PxArticulationCacheFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxArticulationCacheFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxArticulationCacheFlags* self = (physx::PxArticulationCacheFlags*) _address;
    return (jboolean) self->isSet((PxArticulationCacheFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationCacheFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxArticulationCacheFlags* self = (physx::PxArticulationCacheFlags*) _address;
    self->raise((PxArticulationCacheFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationCacheFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxArticulationCacheFlags* self = (physx::PxArticulationCacheFlags*) _address;
    self->clear((PxArticulationCacheFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationCacheFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxArticulationCacheFlags*) _address;
}

// PxArticulationDrive
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationDrive__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxArticulationDrive);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationDrive__1_1placement_1new_1PxArticulationDrive__J(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxArticulationDrive();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationDrive__1_1placement_1new_1PxArticulationDrive__JFFFI(JNIEnv*, jclass, jlong _placement_address, jfloat stiffness, jfloat damping, jfloat maxForce, jint driveType) {
    return (jlong) new((void*)_placement_address) physx::PxArticulationDrive(stiffness, damping, maxForce, (PxArticulationDriveTypeEnum) driveType);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationDrive__1PxArticulationDrive__(JNIEnv*, jclass) {
    return (jlong) new physx::PxArticulationDrive();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationDrive__1PxArticulationDrive__FFFI(JNIEnv*, jclass, jfloat stiffness, jfloat damping, jfloat maxForce, jint driveType) {
    return (jlong) new physx::PxArticulationDrive(stiffness, damping, maxForce, (PxArticulationDriveTypeEnum) driveType);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationDrive__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxArticulationDrive*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationDrive__1getStiffness(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationDrive* _self = (physx::PxArticulationDrive*) _address;
    return (jfloat) _self->stiffness;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationDrive__1setStiffness(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxArticulationDrive* _self = (physx::PxArticulationDrive*) _address;
    _self->stiffness = value;
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationDrive__1getDamping(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationDrive* _self = (physx::PxArticulationDrive*) _address;
    return (jfloat) _self->damping;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationDrive__1setDamping(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxArticulationDrive* _self = (physx::PxArticulationDrive*) _address;
    _self->damping = value;
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationDrive__1getMaxForce(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationDrive* _self = (physx::PxArticulationDrive*) _address;
    return (jfloat) _self->maxForce;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationDrive__1setMaxForce(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxArticulationDrive* _self = (physx::PxArticulationDrive*) _address;
    _self->maxForce = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationDrive__1getDriveType(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationDrive* _self = (physx::PxArticulationDrive*) _address;
    return (jint) _self->driveType;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationDrive__1setDriveType(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxArticulationDrive* _self = (physx::PxArticulationDrive*) _address;
    _self->driveType = (PxArticulationDriveTypeEnum) value;
}

// PxArticulationFixedTendon
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationFixedTendon__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxArticulationFixedTendon);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationFixedTendon__1createTendonJoint(JNIEnv*, jclass, jlong _address, jlong parent, jint axis, jfloat coefficient, jfloat recipCoefficient, jlong link) {
    physx::PxArticulationFixedTendon* self = (physx::PxArticulationFixedTendon*) _address;
    return (jlong) self->createTendonJoint((physx::PxArticulationTendonJoint*) parent, (PxArticulationAxisEnum) axis, coefficient, recipCoefficient, (physx::PxArticulationLink*) link);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationFixedTendon__1getNbTendonJoints(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationFixedTendon* self = (physx::PxArticulationFixedTendon*) _address;
    return (jint) self->getNbTendonJoints();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationFixedTendon__1setRestLength(JNIEnv*, jclass, jlong _address, jfloat restLength) {
    physx::PxArticulationFixedTendon* self = (physx::PxArticulationFixedTendon*) _address;
    self->setRestLength(restLength);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationFixedTendon__1getRestLength(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationFixedTendon* self = (physx::PxArticulationFixedTendon*) _address;
    return (jfloat) self->getRestLength();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationFixedTendon__1setLimitParameters(JNIEnv*, jclass, jlong _address, jlong parameter) {
    physx::PxArticulationFixedTendon* self = (physx::PxArticulationFixedTendon*) _address;
    self->setLimitParameters(*((physx::PxArticulationTendonLimit*) parameter));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationFixedTendon__1getLimitParameters(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationFixedTendon* self = (physx::PxArticulationFixedTendon*) _address;
    static thread_local physx::PxArticulationTendonLimit _cache = self->getLimitParameters();
    _cache = self->getLimitParameters();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationFixedTendon__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxArticulationFixedTendon*) _address;
}

// PxArticulationFlags
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxArticulationFlags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationFlags__1_1placement_1new_1PxArticulationFlags(JNIEnv*, jclass, jlong _placement_address, jbyte flags) {
    return (jlong) new((void*)_placement_address) physx::PxArticulationFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationFlags__1PxArticulationFlags(JNIEnv*, jclass, jbyte flags) {
    return (jlong) new physx::PxArticulationFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxArticulationFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxArticulationFlags* self = (physx::PxArticulationFlags*) _address;
    return (jboolean) self->isSet((PxArticulationFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxArticulationFlags* self = (physx::PxArticulationFlags*) _address;
    self->raise((PxArticulationFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxArticulationFlags* self = (physx::PxArticulationFlags*) _address;
    self->clear((PxArticulationFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxArticulationFlags*) _address;
}

// PxArticulationJointReducedCoordinate
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxArticulationJointReducedCoordinate);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1getParentArticulationLink(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    return (jlong) &self->getParentArticulationLink();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1setParentPose(JNIEnv*, jclass, jlong _address, jlong pose) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    self->setParentPose(*((physx::PxTransform*) pose));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1getParentPose(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    static thread_local physx::PxTransform _cache = self->getParentPose();
    _cache = self->getParentPose();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1getChildArticulationLink(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    return (jlong) &self->getChildArticulationLink();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1setChildPose(JNIEnv*, jclass, jlong _address, jlong pose) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    self->setChildPose(*((physx::PxTransform*) pose));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1getChildPose(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    static thread_local physx::PxTransform _cache = self->getChildPose();
    _cache = self->getChildPose();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1setJointType(JNIEnv*, jclass, jlong _address, jint jointType) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    self->setJointType((PxArticulationJointTypeEnum) jointType);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1getJointType(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    return (jint) self->getJointType();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1setMotion(JNIEnv*, jclass, jlong _address, jint axis, jint motion) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    self->setMotion((PxArticulationAxisEnum) axis, (PxArticulationMotionEnum) motion);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1getMotion(JNIEnv*, jclass, jlong _address, jint axis) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    return (jint) self->getMotion((PxArticulationAxisEnum) axis);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1setLimitParams(JNIEnv*, jclass, jlong _address, jint axis, jlong limit) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    self->setLimitParams((PxArticulationAxisEnum) axis, *((physx::PxArticulationLimit*) limit));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1getLimitParams(JNIEnv*, jclass, jlong _address, jint axis) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    static thread_local physx::PxArticulationLimit _cache = self->getLimitParams((PxArticulationAxisEnum) axis);
    _cache = self->getLimitParams((PxArticulationAxisEnum) axis);
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1setDriveParams(JNIEnv*, jclass, jlong _address, jint axis, jlong drive) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    self->setDriveParams((PxArticulationAxisEnum) axis, *((physx::PxArticulationDrive*) drive));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1setDriveTarget__JIF(JNIEnv*, jclass, jlong _address, jint axis, jfloat target) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    self->setDriveTarget((PxArticulationAxisEnum) axis, target);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1setDriveTarget__JIFZ(JNIEnv*, jclass, jlong _address, jint axis, jfloat target, jboolean autowake) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    self->setDriveTarget((PxArticulationAxisEnum) axis, target, autowake);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1getDriveTarget(JNIEnv*, jclass, jlong _address, jint axis) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    return (jfloat) self->getDriveTarget((PxArticulationAxisEnum) axis);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1setDriveVelocity__JIF(JNIEnv*, jclass, jlong _address, jint axis, jfloat targetVel) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    self->setDriveVelocity((PxArticulationAxisEnum) axis, targetVel);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1setDriveVelocity__JIFZ(JNIEnv*, jclass, jlong _address, jint axis, jfloat targetVel, jboolean autowake) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    self->setDriveVelocity((PxArticulationAxisEnum) axis, targetVel, autowake);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1getDriveVelocity(JNIEnv*, jclass, jlong _address, jint axis) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    return (jfloat) self->getDriveVelocity((PxArticulationAxisEnum) axis);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1setArmature(JNIEnv*, jclass, jlong _address, jint axis, jfloat armature) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    self->setArmature((PxArticulationAxisEnum) axis, armature);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1getArmature(JNIEnv*, jclass, jlong _address, jint axis) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    return (jfloat) self->getArmature((PxArticulationAxisEnum) axis);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1setFrictionCoefficient(JNIEnv*, jclass, jlong _address, jfloat coefficient) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    self->setFrictionCoefficient(coefficient);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1getFrictionCoefficient(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    return (jfloat) self->getFrictionCoefficient();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1setMaxJointVelocity(JNIEnv*, jclass, jlong _address, jfloat maxJointV) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    self->setMaxJointVelocity(maxJointV);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1getMaxJointVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    return (jfloat) self->getMaxJointVelocity();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1setJointPosition(JNIEnv*, jclass, jlong _address, jint axis, jfloat jointPos) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    self->setJointPosition((PxArticulationAxisEnum) axis, jointPos);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1getJointPosition(JNIEnv*, jclass, jlong _address, jint axis) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    return (jfloat) self->getJointPosition((PxArticulationAxisEnum) axis);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1setJointVelocity(JNIEnv*, jclass, jlong _address, jint axis, jfloat jointVel) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    self->setJointVelocity((PxArticulationAxisEnum) axis, jointVel);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1getJointVelocity(JNIEnv*, jclass, jlong _address, jint axis) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    return (jfloat) self->getJointVelocity((PxArticulationAxisEnum) axis);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxArticulationJointReducedCoordinate*) _address;
}

// PxArticulationKinematicFlags
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationKinematicFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxArticulationKinematicFlags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationKinematicFlags__1_1placement_1new_1PxArticulationKinematicFlags(JNIEnv*, jclass, jlong _placement_address, jbyte flags) {
    return (jlong) new((void*)_placement_address) physx::PxArticulationKinematicFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationKinematicFlags__1PxArticulationKinematicFlags(JNIEnv*, jclass, jbyte flags) {
    return (jlong) new physx::PxArticulationKinematicFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxArticulationKinematicFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxArticulationKinematicFlags* self = (physx::PxArticulationKinematicFlags*) _address;
    return (jboolean) self->isSet((PxArticulationKinematicFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationKinematicFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxArticulationKinematicFlags* self = (physx::PxArticulationKinematicFlags*) _address;
    self->raise((PxArticulationKinematicFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationKinematicFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxArticulationKinematicFlags* self = (physx::PxArticulationKinematicFlags*) _address;
    self->clear((PxArticulationKinematicFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationKinematicFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxArticulationKinematicFlags*) _address;
}

// PxArticulationLink
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationLink__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxArticulationLink);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationLink__1getArticulation(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationLink* self = (physx::PxArticulationLink*) _address;
    return (jlong) &self->getArticulation();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationLink__1getInboundJoint(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationLink* self = (physx::PxArticulationLink*) _address;
    return (jlong) self->getInboundJoint();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationLink__1getInboundJointDof(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationLink* self = (physx::PxArticulationLink*) _address;
    return (jint) self->getInboundJointDof();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationLink__1getNbChildren(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationLink* self = (physx::PxArticulationLink*) _address;
    return (jint) self->getNbChildren();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationLink__1getLinkIndex(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationLink* self = (physx::PxArticulationLink*) _address;
    return (jint) self->getLinkIndex();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationLink__1setCfmScale(JNIEnv*, jclass, jlong _address, jfloat cfm) {
    physx::PxArticulationLink* self = (physx::PxArticulationLink*) _address;
    self->setCfmScale(cfm);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationLink__1getCfmScale(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationLink* self = (physx::PxArticulationLink*) _address;
    return (jfloat) self->getCfmScale();
}

// PxArticulationLimit
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationLimit__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxArticulationLimit);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationLimit__1_1placement_1new_1PxArticulationLimit__J(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxArticulationLimit();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationLimit__1_1placement_1new_1PxArticulationLimit__JFF(JNIEnv*, jclass, jlong _placement_address, jfloat low, jfloat high) {
    return (jlong) new((void*)_placement_address) physx::PxArticulationLimit(low, high);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationLimit__1PxArticulationLimit__(JNIEnv*, jclass) {
    return (jlong) new physx::PxArticulationLimit();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationLimit__1PxArticulationLimit__FF(JNIEnv*, jclass, jfloat low, jfloat high) {
    return (jlong) new physx::PxArticulationLimit(low, high);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationLimit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxArticulationLimit*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationLimit__1getLow(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationLimit* _self = (physx::PxArticulationLimit*) _address;
    return (jfloat) _self->low;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationLimit__1setLow(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxArticulationLimit* _self = (physx::PxArticulationLimit*) _address;
    _self->low = value;
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationLimit__1getHigh(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationLimit* _self = (physx::PxArticulationLimit*) _address;
    return (jfloat) _self->high;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationLimit__1setHigh(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxArticulationLimit* _self = (physx::PxArticulationLimit*) _address;
    _self->high = value;
}

// PxArticulationRootLinkData
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationRootLinkData__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxArticulationRootLinkData);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationRootLinkData__1PxArticulationRootLinkData(JNIEnv*, jclass) {
    return (jlong) new physx::PxArticulationRootLinkData();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationRootLinkData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxArticulationRootLinkData*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationRootLinkData__1getTransform(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationRootLinkData* _self = (physx::PxArticulationRootLinkData*) _address;
    return (jlong) &_self->transform;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationRootLinkData__1setTransform(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxArticulationRootLinkData* _self = (physx::PxArticulationRootLinkData*) _address;
    _self->transform = *((physx::PxTransform*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationRootLinkData__1getWorldLinVel(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationRootLinkData* _self = (physx::PxArticulationRootLinkData*) _address;
    return (jlong) &_self->worldLinVel;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationRootLinkData__1setWorldLinVel(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxArticulationRootLinkData* _self = (physx::PxArticulationRootLinkData*) _address;
    _self->worldLinVel = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationRootLinkData__1getWorldAngVel(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationRootLinkData* _self = (physx::PxArticulationRootLinkData*) _address;
    return (jlong) &_self->worldAngVel;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationRootLinkData__1setWorldAngVel(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxArticulationRootLinkData* _self = (physx::PxArticulationRootLinkData*) _address;
    _self->worldAngVel = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationRootLinkData__1getWorldLinAccel(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationRootLinkData* _self = (physx::PxArticulationRootLinkData*) _address;
    return (jlong) &_self->worldLinAccel;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationRootLinkData__1setWorldLinAccel(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxArticulationRootLinkData* _self = (physx::PxArticulationRootLinkData*) _address;
    _self->worldLinAccel = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationRootLinkData__1getWorldAngAccel(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationRootLinkData* _self = (physx::PxArticulationRootLinkData*) _address;
    return (jlong) &_self->worldAngAccel;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationRootLinkData__1setWorldAngAccel(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxArticulationRootLinkData* _self = (physx::PxArticulationRootLinkData*) _address;
    _self->worldAngAccel = *((physx::PxVec3*) value);
}

// PxArticulationReducedCoordinate
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxArticulationReducedCoordinate);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getScene(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jlong) self->getScene();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1setSolverIterationCounts__JI(JNIEnv*, jclass, jlong _address, jint minPositionIters) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->setSolverIterationCounts(minPositionIters);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1setSolverIterationCounts__JII(JNIEnv*, jclass, jlong _address, jint minPositionIters, jint minVelocityIters) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->setSolverIterationCounts(minPositionIters, minVelocityIters);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1isSleeping(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jboolean) self->isSleeping();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1setSleepThreshold(JNIEnv*, jclass, jlong _address, jfloat threshold) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->setSleepThreshold(threshold);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getSleepThreshold(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jfloat) self->getSleepThreshold();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1setStabilizationThreshold(JNIEnv*, jclass, jlong _address, jfloat threshold) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->setStabilizationThreshold(threshold);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getStabilizationThreshold(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jfloat) self->getStabilizationThreshold();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1setWakeCounter(JNIEnv*, jclass, jlong _address, jfloat wakeCounterValue) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->setWakeCounter(wakeCounterValue);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getWakeCounter(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jfloat) self->getWakeCounter();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1wakeUp(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->wakeUp();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1putToSleep(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->putToSleep();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1setMaxCOMLinearVelocity(JNIEnv*, jclass, jlong _address, jfloat maxLinerVelocity) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->setMaxCOMLinearVelocity(maxLinerVelocity);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getMaxCOMLinearVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jfloat) self->getMaxCOMLinearVelocity();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1setMaxCOMAngularVelocity(JNIEnv*, jclass, jlong _address, jfloat maxAngularVelocity) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->setMaxCOMAngularVelocity(maxAngularVelocity);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getMaxCOMAngularVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jfloat) self->getMaxCOMAngularVelocity();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1createLink(JNIEnv*, jclass, jlong _address, jlong parent, jlong pose) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jlong) self->createLink((physx::PxArticulationLink*) parent, *((physx::PxTransform*) pose));
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getNbLinks(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jint) self->getNbLinks();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getNbShapes(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jint) self->getNbShapes();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1setName(JNIEnv* _env, jclass, jlong _address, jstring name) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->setName(_env->GetStringUTFChars(name, 0));
}
JNIEXPORT jstring JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getName(JNIEnv* _env, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return _env->NewStringUTF(self->getName());
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getWorldBounds__J(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    static thread_local physx::PxBounds3 _cache = self->getWorldBounds();
    _cache = self->getWorldBounds();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getWorldBounds__JF(JNIEnv*, jclass, jlong _address, jfloat inflation) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    static thread_local physx::PxBounds3 _cache = self->getWorldBounds(inflation);
    _cache = self->getWorldBounds(inflation);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getAggregate(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jlong) self->getAggregate();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1setArticulationFlags(JNIEnv*, jclass, jlong _address, jlong flags) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->setArticulationFlags(*((physx::PxArticulationFlags*) flags));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1setArticulationFlag(JNIEnv*, jclass, jlong _address, jint flag, jboolean value) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->setArticulationFlag((PxArticulationFlagEnum) flag, value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getArticulationFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    static thread_local physx::PxArticulationFlags _cache = self->getArticulationFlags();
    _cache = self->getArticulationFlags();
    return (jlong) &_cache;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getDofs(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jint) self->getDofs();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1createCache(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jlong) self->createCache();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getCacheDataSize(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jint) self->getCacheDataSize();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1zeroCache(JNIEnv*, jclass, jlong _address, jlong cache) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->zeroCache(*((physx::PxArticulationCache*) cache));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1applyCache__JJJ(JNIEnv*, jclass, jlong _address, jlong cache, jlong flags) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->applyCache(*((physx::PxArticulationCache*) cache), *((physx::PxArticulationCacheFlags*) flags));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1applyCache__JJJZ(JNIEnv*, jclass, jlong _address, jlong cache, jlong flags, jboolean autowake) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->applyCache(*((physx::PxArticulationCache*) cache), *((physx::PxArticulationCacheFlags*) flags), autowake);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1copyInternalStateToCache(JNIEnv*, jclass, jlong _address, jlong cache, jlong flags) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->copyInternalStateToCache(*((physx::PxArticulationCache*) cache), *((physx::PxArticulationCacheFlags*) flags));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1commonInit(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->commonInit();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1computeGeneralizedGravityForce(JNIEnv*, jclass, jlong _address, jlong cache) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->computeGeneralizedGravityForce(*((physx::PxArticulationCache*) cache));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1computeCoriolisAndCentrifugalForce(JNIEnv*, jclass, jlong _address, jlong cache) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->computeCoriolisAndCentrifugalForce(*((physx::PxArticulationCache*) cache));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1computeGeneralizedExternalForce(JNIEnv*, jclass, jlong _address, jlong cache) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->computeGeneralizedExternalForce(*((physx::PxArticulationCache*) cache));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1computeJointAcceleration(JNIEnv*, jclass, jlong _address, jlong cache) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->computeJointAcceleration(*((physx::PxArticulationCache*) cache));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1computeJointForce(JNIEnv*, jclass, jlong _address, jlong cache) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->computeJointForce(*((physx::PxArticulationCache*) cache));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1computeCoefficientMatrix(JNIEnv*, jclass, jlong _address, jlong cache) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->computeCoefficientMatrix(*((physx::PxArticulationCache*) cache));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1computeGeneralizedMassMatrix(JNIEnv*, jclass, jlong _address, jlong cache) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->computeGeneralizedMassMatrix(*((physx::PxArticulationCache*) cache));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1addLoopJoint(JNIEnv*, jclass, jlong _address, jlong joint) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->addLoopJoint((physx::PxConstraint*) joint);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1removeLoopJoint(JNIEnv*, jclass, jlong _address, jlong joint) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->removeLoopJoint((physx::PxConstraint*) joint);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getNbLoopJoints(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jint) self->getNbLoopJoints();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getCoefficientMatrixSize(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jint) self->getCoefficientMatrixSize();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1setRootGlobalPose__JJ(JNIEnv*, jclass, jlong _address, jlong pose) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->setRootGlobalPose(*((physx::PxTransform*) pose));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1setRootGlobalPose__JJZ(JNIEnv*, jclass, jlong _address, jlong pose, jboolean autowake) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->setRootGlobalPose(*((physx::PxTransform*) pose), autowake);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getRootGlobalPose(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    static thread_local physx::PxTransform _cache = self->getRootGlobalPose();
    _cache = self->getRootGlobalPose();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1setRootLinearVelocity__JJ(JNIEnv*, jclass, jlong _address, jlong linearVelocity) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->setRootLinearVelocity(*((physx::PxVec3*) linearVelocity));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1setRootLinearVelocity__JJZ(JNIEnv*, jclass, jlong _address, jlong linearVelocity, jboolean autowake) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->setRootLinearVelocity(*((physx::PxVec3*) linearVelocity), autowake);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getRootLinearVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    static thread_local physx::PxVec3 _cache = self->getRootLinearVelocity();
    _cache = self->getRootLinearVelocity();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1setRootAngularVelocity__JJ(JNIEnv*, jclass, jlong _address, jlong angularVelocity) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->setRootAngularVelocity(*((physx::PxVec3*) angularVelocity));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1setRootAngularVelocity__JJZ(JNIEnv*, jclass, jlong _address, jlong angularVelocity, jboolean autowake) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->setRootAngularVelocity(*((physx::PxVec3*) angularVelocity), autowake);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getRootAngularVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    static thread_local physx::PxVec3 _cache = self->getRootAngularVelocity();
    _cache = self->getRootAngularVelocity();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getLinkAcceleration(JNIEnv*, jclass, jlong _address, jint linkId) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    static thread_local physx::PxSpatialVelocity _cache = self->getLinkAcceleration(linkId);
    _cache = self->getLinkAcceleration(linkId);
    return (jlong) &_cache;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getGpuArticulationIndex(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jint) self->getGpuArticulationIndex();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1createSpatialTendon(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jlong) self->createSpatialTendon();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1createFixedTendon(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jlong) self->createFixedTendon();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1createSensor(JNIEnv*, jclass, jlong _address, jlong link, jlong relativePose) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jlong) self->createSensor((physx::PxArticulationLink*) link, *((physx::PxTransform*) relativePose));
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getNbSpatialTendons(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jint) self->getNbSpatialTendons();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getNbFixedTendons(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jint) self->getNbFixedTendons();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getNbSensors(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jint) self->getNbSensors();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1updateKinematic(JNIEnv*, jclass, jlong _address, jlong flags) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->updateKinematic(*((physx::PxArticulationKinematicFlags*) flags));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxArticulationReducedCoordinate*) _address;
}

// PxArticulationSensor
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationSensor__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxArticulationSensor);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationSensor__1getForces(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationSensor* self = (physx::PxArticulationSensor*) _address;
    static thread_local physx::PxSpatialForce _cache = self->getForces();
    _cache = self->getForces();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationSensor__1getRelativePose(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationSensor* self = (physx::PxArticulationSensor*) _address;
    static thread_local physx::PxTransform _cache = self->getRelativePose();
    _cache = self->getRelativePose();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationSensor__1setRelativePose(JNIEnv*, jclass, jlong _address, jlong pose) {
    physx::PxArticulationSensor* self = (physx::PxArticulationSensor*) _address;
    self->setRelativePose(*((physx::PxTransform*) pose));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationSensor__1getLink(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationSensor* self = (physx::PxArticulationSensor*) _address;
    return (jlong) self->getLink();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationSensor__1getIndex(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationSensor* self = (physx::PxArticulationSensor*) _address;
    return (jint) self->getIndex();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationSensor__1getArticulation(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationSensor* self = (physx::PxArticulationSensor*) _address;
    return (jlong) self->getArticulation();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationSensor__1getFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationSensor* self = (physx::PxArticulationSensor*) _address;
    static thread_local physx::PxArticulationSensorFlags _cache = self->getFlags();
    _cache = self->getFlags();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationSensor__1setFlag(JNIEnv*, jclass, jlong _address, jint flag, jboolean enabled) {
    physx::PxArticulationSensor* self = (physx::PxArticulationSensor*) _address;
    self->setFlag((PxArticulationSensorFlagEnum) flag, enabled);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationSensor__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxArticulationSensor*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationSensor__1getUserData(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationSensor* _self = (physx::PxArticulationSensor*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationSensor__1setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxArticulationSensor* _self = (physx::PxArticulationSensor*) _address;
    _self->userData = (void*) value;
}

// PxArticulationSensorFlags
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationSensorFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxArticulationSensorFlags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationSensorFlags__1_1placement_1new_1PxArticulationSensorFlags(JNIEnv*, jclass, jlong _placement_address, jbyte flags) {
    return (jlong) new((void*)_placement_address) physx::PxArticulationSensorFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationSensorFlags__1PxArticulationSensorFlags(JNIEnv*, jclass, jbyte flags) {
    return (jlong) new physx::PxArticulationSensorFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxArticulationSensorFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxArticulationSensorFlags* self = (physx::PxArticulationSensorFlags*) _address;
    return (jboolean) self->isSet((PxArticulationSensorFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationSensorFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxArticulationSensorFlags* self = (physx::PxArticulationSensorFlags*) _address;
    self->raise((PxArticulationSensorFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationSensorFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxArticulationSensorFlags* self = (physx::PxArticulationSensorFlags*) _address;
    self->clear((PxArticulationSensorFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationSensorFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxArticulationSensorFlags*) _address;
}

// PxArticulationSpatialTendon
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationSpatialTendon__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxArticulationSpatialTendon);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationSpatialTendon__1createAttachment(JNIEnv*, jclass, jlong _address, jlong parent, jfloat coefficient, jlong relativeOffset, jlong link) {
    physx::PxArticulationSpatialTendon* self = (physx::PxArticulationSpatialTendon*) _address;
    return (jlong) self->createAttachment((physx::PxArticulationAttachment*) parent, coefficient, *((physx::PxVec3*) relativeOffset), (physx::PxArticulationLink*) link);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationSpatialTendon__1getNbAttachments(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationSpatialTendon* self = (physx::PxArticulationSpatialTendon*) _address;
    return (jint) self->getNbAttachments();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationSpatialTendon__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxArticulationSpatialTendon*) _address;
}

// PxArticulationTendon
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationTendon__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxArticulationTendon);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationTendon__1setStiffness(JNIEnv*, jclass, jlong _address, jfloat stiffness) {
    physx::PxArticulationTendon* self = (physx::PxArticulationTendon*) _address;
    self->setStiffness(stiffness);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationTendon__1getStiffness(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationTendon* self = (physx::PxArticulationTendon*) _address;
    return (jfloat) self->getStiffness();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationTendon__1setDamping(JNIEnv*, jclass, jlong _address, jfloat damping) {
    physx::PxArticulationTendon* self = (physx::PxArticulationTendon*) _address;
    self->setDamping(damping);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationTendon__1getDamping(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationTendon* self = (physx::PxArticulationTendon*) _address;
    return (jfloat) self->getDamping();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationTendon__1setLimitStiffness(JNIEnv*, jclass, jlong _address, jfloat stiffness) {
    physx::PxArticulationTendon* self = (physx::PxArticulationTendon*) _address;
    self->setLimitStiffness(stiffness);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationTendon__1getLimitStiffness(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationTendon* self = (physx::PxArticulationTendon*) _address;
    return (jfloat) self->getLimitStiffness();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationTendon__1setOffset__JF(JNIEnv*, jclass, jlong _address, jfloat offset) {
    physx::PxArticulationTendon* self = (physx::PxArticulationTendon*) _address;
    self->setOffset(offset);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationTendon__1setOffset__JFZ(JNIEnv*, jclass, jlong _address, jfloat offset, jboolean autowake) {
    physx::PxArticulationTendon* self = (physx::PxArticulationTendon*) _address;
    self->setOffset(offset, autowake);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationTendon__1getOffset(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationTendon* self = (physx::PxArticulationTendon*) _address;
    return (jfloat) self->getOffset();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationTendon__1getArticulation(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationTendon* self = (physx::PxArticulationTendon*) _address;
    return (jlong) self->getArticulation();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationTendon__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxArticulationTendon*) _address;
}

// PxArticulationTendonJoint
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationTendonJoint__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxArticulationTendonJoint);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationTendonJoint__1setCoefficient(JNIEnv*, jclass, jlong _address, jint axis, jfloat coefficient, jfloat recipCoefficient) {
    physx::PxArticulationTendonJoint* self = (physx::PxArticulationTendonJoint*) _address;
    self->setCoefficient((PxArticulationAxisEnum) axis, coefficient, recipCoefficient);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationTendonJoint__1getLink(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationTendonJoint* self = (physx::PxArticulationTendonJoint*) _address;
    return (jlong) self->getLink();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationTendonJoint__1getParent(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationTendonJoint* self = (physx::PxArticulationTendonJoint*) _address;
    return (jlong) self->getParent();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationTendonJoint__1getTendon(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationTendonJoint* self = (physx::PxArticulationTendonJoint*) _address;
    return (jlong) self->getTendon();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationTendonJoint__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationTendonJoint* self = (physx::PxArticulationTendonJoint*) _address;
    self->release();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationTendonJoint__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxArticulationTendonJoint*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationTendonJoint__1getUserData(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationTendonJoint* _self = (physx::PxArticulationTendonJoint*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationTendonJoint__1setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxArticulationTendonJoint* _self = (physx::PxArticulationTendonJoint*) _address;
    _self->userData = (void*) value;
}

// PxArticulationTendonLimit
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationTendonLimit__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxArticulationTendonLimit);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationTendonLimit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxArticulationTendonLimit*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationTendonLimit__1getLowLimit(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationTendonLimit* _self = (physx::PxArticulationTendonLimit*) _address;
    return (jfloat) _self->lowLimit;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationTendonLimit__1setLowLimit(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxArticulationTendonLimit* _self = (physx::PxArticulationTendonLimit*) _address;
    _self->lowLimit = value;
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationTendonLimit__1getHighLimit(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationTendonLimit* _self = (physx::PxArticulationTendonLimit*) _address;
    return (jfloat) _self->highLimit;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationTendonLimit__1setHighLimit(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxArticulationTendonLimit* _self = (physx::PxArticulationTendonLimit*) _address;
    _self->highLimit = value;
}

// PxSpatialForce
JNIEXPORT jint JNICALL Java_physx_physics_PxSpatialForce__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxSpatialForce);
}
JNIEXPORT void JNICALL Java_physx_physics_PxSpatialForce__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSpatialForce*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSpatialForce__1getForce(JNIEnv*, jclass, jlong _address) {
    physx::PxSpatialForce* _self = (physx::PxSpatialForce*) _address;
    return (jlong) &_self->force;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSpatialForce__1setForce(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSpatialForce* _self = (physx::PxSpatialForce*) _address;
    _self->force = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSpatialForce__1getTorque(JNIEnv*, jclass, jlong _address) {
    physx::PxSpatialForce* _self = (physx::PxSpatialForce*) _address;
    return (jlong) &_self->torque;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSpatialForce__1setTorque(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSpatialForce* _self = (physx::PxSpatialForce*) _address;
    _self->torque = *((physx::PxVec3*) value);
}

// PxSpatialVelocity
JNIEXPORT jint JNICALL Java_physx_physics_PxSpatialVelocity__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxSpatialVelocity);
}
JNIEXPORT void JNICALL Java_physx_physics_PxSpatialVelocity__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSpatialVelocity*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSpatialVelocity__1getLinear(JNIEnv*, jclass, jlong _address) {
    physx::PxSpatialVelocity* _self = (physx::PxSpatialVelocity*) _address;
    return (jlong) &_self->linear;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSpatialVelocity__1setLinear(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSpatialVelocity* _self = (physx::PxSpatialVelocity*) _address;
    _self->linear = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSpatialVelocity__1getAngular(JNIEnv*, jclass, jlong _address) {
    physx::PxSpatialVelocity* _self = (physx::PxSpatialVelocity*) _address;
    return (jlong) &_self->angular;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSpatialVelocity__1setAngular(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSpatialVelocity* _self = (physx::PxSpatialVelocity*) _address;
    _self->angular = *((physx::PxVec3*) value);
}

// PxAggregate
JNIEXPORT jint JNICALL Java_physx_physics_PxAggregate__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxAggregate);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxAggregate__1addActor__JJ(JNIEnv*, jclass, jlong _address, jlong actor) {
    physx::PxAggregate* self = (physx::PxAggregate*) _address;
    return (jboolean) self->addActor(*((physx::PxActor*) actor));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxAggregate__1addActor__JJJ(JNIEnv*, jclass, jlong _address, jlong actor, jlong bvhStructure) {
    physx::PxAggregate* self = (physx::PxAggregate*) _address;
    return (jboolean) self->addActor(*((physx::PxActor*) actor), (physx::PxBVHStructure*) bvhStructure);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxAggregate__1removeActor(JNIEnv*, jclass, jlong _address, jlong actor) {
    physx::PxAggregate* self = (physx::PxAggregate*) _address;
    return (jboolean) self->removeActor(*((physx::PxActor*) actor));
}
JNIEXPORT jint JNICALL Java_physx_physics_PxAggregate__1getNbActors(JNIEnv*, jclass, jlong _address) {
    physx::PxAggregate* self = (physx::PxAggregate*) _address;
    return (jint) self->getNbActors();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxAggregate__1getMaxNbActors(JNIEnv*, jclass, jlong _address) {
    physx::PxAggregate* self = (physx::PxAggregate*) _address;
    return (jint) self->getMaxNbActors();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxAggregate__1getScene(JNIEnv*, jclass, jlong _address) {
    physx::PxAggregate* self = (physx::PxAggregate*) _address;
    return (jlong) self->getScene();
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxAggregate__1getSelfCollision(JNIEnv*, jclass, jlong _address) {
    physx::PxAggregate* self = (physx::PxAggregate*) _address;
    return (jboolean) self->getSelfCollision();
}

// PxBaseMaterial
JNIEXPORT jint JNICALL Java_physx_physics_PxBaseMaterial__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxBaseMaterial);
}
JNIEXPORT void JNICALL Java_physx_physics_PxBaseMaterial__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBaseMaterial*) _address;
}

// PxBroadPhaseCaps
JNIEXPORT jint JNICALL Java_physx_physics_PxBroadPhaseCaps__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxBroadPhaseCaps);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBroadPhaseCaps__1PxBroadPhaseCaps(JNIEnv*, jclass) {
    return (jlong) new physx::PxBroadPhaseCaps();
}
JNIEXPORT void JNICALL Java_physx_physics_PxBroadPhaseCaps__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBroadPhaseCaps*) _address;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxBroadPhaseCaps__1getMMaxNbRegions(JNIEnv*, jclass, jlong _address) {
    physx::PxBroadPhaseCaps* _self = (physx::PxBroadPhaseCaps*) _address;
    return (jint) _self->mMaxNbRegions;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBroadPhaseCaps__1setMMaxNbRegions(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxBroadPhaseCaps* _self = (physx::PxBroadPhaseCaps*) _address;
    _self->mMaxNbRegions = value;
}

// PxBroadPhaseRegion
JNIEXPORT jint JNICALL Java_physx_physics_PxBroadPhaseRegion__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxBroadPhaseRegion);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBroadPhaseRegion__1PxBroadPhaseRegion(JNIEnv*, jclass) {
    return (jlong) new physx::PxBroadPhaseRegion();
}
JNIEXPORT void JNICALL Java_physx_physics_PxBroadPhaseRegion__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBroadPhaseRegion*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBroadPhaseRegion__1getMBounds(JNIEnv*, jclass, jlong _address) {
    physx::PxBroadPhaseRegion* _self = (physx::PxBroadPhaseRegion*) _address;
    return (jlong) &_self->mBounds;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBroadPhaseRegion__1setMBounds(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxBroadPhaseRegion* _self = (physx::PxBroadPhaseRegion*) _address;
    _self->mBounds = *((physx::PxBounds3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBroadPhaseRegion__1getMUserData(JNIEnv*, jclass, jlong _address) {
    physx::PxBroadPhaseRegion* _self = (physx::PxBroadPhaseRegion*) _address;
    return (jlong) _self->mUserData;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBroadPhaseRegion__1setMUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxBroadPhaseRegion* _self = (physx::PxBroadPhaseRegion*) _address;
    _self->mUserData = (void*) value;
}

// PxBroadPhaseRegionInfo
JNIEXPORT jint JNICALL Java_physx_physics_PxBroadPhaseRegionInfo__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxBroadPhaseRegionInfo);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBroadPhaseRegionInfo__1PxBroadPhaseRegionInfo(JNIEnv*, jclass) {
    return (jlong) new physx::PxBroadPhaseRegionInfo();
}
JNIEXPORT void JNICALL Java_physx_physics_PxBroadPhaseRegionInfo__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBroadPhaseRegionInfo*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBroadPhaseRegionInfo__1getMRegion(JNIEnv*, jclass, jlong _address) {
    physx::PxBroadPhaseRegionInfo* _self = (physx::PxBroadPhaseRegionInfo*) _address;
    return (jlong) &_self->mRegion;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBroadPhaseRegionInfo__1setMRegion(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxBroadPhaseRegionInfo* _self = (physx::PxBroadPhaseRegionInfo*) _address;
    _self->mRegion = *((physx::PxBroadPhaseRegion*) value);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxBroadPhaseRegionInfo__1getMNbStaticObjects(JNIEnv*, jclass, jlong _address) {
    physx::PxBroadPhaseRegionInfo* _self = (physx::PxBroadPhaseRegionInfo*) _address;
    return (jint) _self->mNbStaticObjects;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBroadPhaseRegionInfo__1setMNbStaticObjects(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxBroadPhaseRegionInfo* _self = (physx::PxBroadPhaseRegionInfo*) _address;
    _self->mNbStaticObjects = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxBroadPhaseRegionInfo__1getMNbDynamicObjects(JNIEnv*, jclass, jlong _address) {
    physx::PxBroadPhaseRegionInfo* _self = (physx::PxBroadPhaseRegionInfo*) _address;
    return (jint) _self->mNbDynamicObjects;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBroadPhaseRegionInfo__1setMNbDynamicObjects(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxBroadPhaseRegionInfo* _self = (physx::PxBroadPhaseRegionInfo*) _address;
    _self->mNbDynamicObjects = value;
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxBroadPhaseRegionInfo__1getMActive(JNIEnv*, jclass, jlong _address) {
    physx::PxBroadPhaseRegionInfo* _self = (physx::PxBroadPhaseRegionInfo*) _address;
    return (jboolean) _self->mActive;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBroadPhaseRegionInfo__1setMActive(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::PxBroadPhaseRegionInfo* _self = (physx::PxBroadPhaseRegionInfo*) _address;
    _self->mActive = value;
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxBroadPhaseRegionInfo__1getMOverlap(JNIEnv*, jclass, jlong _address) {
    physx::PxBroadPhaseRegionInfo* _self = (physx::PxBroadPhaseRegionInfo*) _address;
    return (jboolean) _self->mOverlap;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBroadPhaseRegionInfo__1setMOverlap(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::PxBroadPhaseRegionInfo* _self = (physx::PxBroadPhaseRegionInfo*) _address;
    _self->mOverlap = value;
}

// PxConstraint
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraint__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxConstraint);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxConstraint__1getScene(JNIEnv*, jclass, jlong _address) {
    physx::PxConstraint* self = (physx::PxConstraint*) _address;
    return (jlong) self->getScene();
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraint__1setActors(JNIEnv*, jclass, jlong _address, jlong actor0, jlong actor1) {
    physx::PxConstraint* self = (physx::PxConstraint*) _address;
    self->setActors((physx::PxRigidActor*) actor0, (physx::PxRigidActor*) actor1);
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraint__1markDirty(JNIEnv*, jclass, jlong _address) {
    physx::PxConstraint* self = (physx::PxConstraint*) _address;
    self->markDirty();
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraint__1setFlags(JNIEnv*, jclass, jlong _address, jlong flags) {
    physx::PxConstraint* self = (physx::PxConstraint*) _address;
    self->setFlags(*((physx::PxConstraintFlags*) flags));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxConstraint__1getFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxConstraint* self = (physx::PxConstraint*) _address;
    static thread_local physx::PxConstraintFlags _cache = self->getFlags();
    _cache = self->getFlags();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraint__1setFlag(JNIEnv*, jclass, jlong _address, jint flag, jboolean value) {
    physx::PxConstraint* self = (physx::PxConstraint*) _address;
    self->setFlag((PxConstraintFlagEnum) flag, value);
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraint__1getForce(JNIEnv*, jclass, jlong _address, jlong linear, jlong angular) {
    physx::PxConstraint* self = (physx::PxConstraint*) _address;
    self->getForce(*((physx::PxVec3*) linear), *((physx::PxVec3*) angular));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxConstraint__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxConstraint* self = (physx::PxConstraint*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraint__1setBreakForce(JNIEnv*, jclass, jlong _address, jfloat linear, jfloat angular) {
    physx::PxConstraint* self = (physx::PxConstraint*) _address;
    self->setBreakForce(linear, angular);
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraint__1setMinResponseThreshold(JNIEnv*, jclass, jlong _address, jfloat threshold) {
    physx::PxConstraint* self = (physx::PxConstraint*) _address;
    self->setMinResponseThreshold(threshold);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxConstraint__1getMinResponseThreshold(JNIEnv*, jclass, jlong _address) {
    physx::PxConstraint* self = (physx::PxConstraint*) _address;
    return (jfloat) self->getMinResponseThreshold();
}

// PxConstraintConnector
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintConnector__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxConstraintConnector);
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraintConnector__1prepareData(JNIEnv*, jclass, jlong _address) {
    physx::PxConstraintConnector* self = (physx::PxConstraintConnector*) _address;
    self->prepareData();
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraintConnector__1updateOmniPvdProperties(JNIEnv*, jclass, jlong _address) {
    physx::PxConstraintConnector* self = (physx::PxConstraintConnector*) _address;
    self->updateOmniPvdProperties();
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraintConnector__1onConstraintRelease(JNIEnv*, jclass, jlong _address) {
    physx::PxConstraintConnector* self = (physx::PxConstraintConnector*) _address;
    self->onConstraintRelease();
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraintConnector__1onComShift(JNIEnv*, jclass, jlong _address, jint actor) {
    physx::PxConstraintConnector* self = (physx::PxConstraintConnector*) _address;
    self->onComShift(actor);
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraintConnector__1onOriginShift(JNIEnv*, jclass, jlong _address, jlong shift) {
    physx::PxConstraintConnector* self = (physx::PxConstraintConnector*) _address;
    self->onOriginShift(*((physx::PxVec3*) shift));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxConstraintConnector__1getSerializable(JNIEnv*, jclass, jlong _address) {
    physx::PxConstraintConnector* self = (physx::PxConstraintConnector*) _address;
    return (jlong) self->getSerializable();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxConstraintConnector__1getPrep(JNIEnv*, jclass, jlong _address) {
    physx::PxConstraintConnector* self = (physx::PxConstraintConnector*) _address;
    static thread_local physx::PxConstraintSolverPrep _cache = self->getPrep();
    _cache = self->getPrep();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraintConnector__1getConstantBlock(JNIEnv*, jclass, jlong _address) {
    physx::PxConstraintConnector* self = (physx::PxConstraintConnector*) _address;
    self->getConstantBlock();
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraintConnector__1connectToConstraint(JNIEnv*, jclass, jlong _address, jlong constraint) {
    physx::PxConstraintConnector* self = (physx::PxConstraintConnector*) _address;
    self->connectToConstraint((physx::PxConstraint*) constraint);
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraintConnector__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxConstraintConnector*) _address;
}

// PxConstraintFlags
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxConstraintFlags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxConstraintFlags__1_1placement_1new_1PxConstraintFlags(JNIEnv*, jclass, jlong _placement_address, jshort flags) {
    return (jlong) new((void*)_placement_address) physx::PxConstraintFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxConstraintFlags__1PxConstraintFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxConstraintFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxConstraintFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxConstraintFlags* self = (physx::PxConstraintFlags*) _address;
    return (jboolean) self->isSet((PxConstraintFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraintFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxConstraintFlags* self = (physx::PxConstraintFlags*) _address;
    self->raise((PxConstraintFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraintFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxConstraintFlags* self = (physx::PxConstraintFlags*) _address;
    self->clear((PxConstraintFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraintFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxConstraintFlags*) _address;
}

// PxConstraintInfo
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintInfo__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxConstraintInfo);
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraintInfo__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxConstraintInfo*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxConstraintInfo__1getConstraint(JNIEnv*, jclass, jlong _address) {
    physx::PxConstraintInfo* _self = (physx::PxConstraintInfo*) _address;
    return (jlong) _self->constraint;
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraintInfo__1setConstraint(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxConstraintInfo* _self = (physx::PxConstraintInfo*) _address;
    _self->constraint = (physx::PxConstraint*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxConstraintInfo__1getExternalReference(JNIEnv*, jclass, jlong _address) {
    physx::PxConstraintInfo* _self = (physx::PxConstraintInfo*) _address;
    return (jlong) _self->externalReference;
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraintInfo__1setExternalReference(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxConstraintInfo* _self = (physx::PxConstraintInfo*) _address;
    _self->externalReference = (void*) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintInfo__1getType(JNIEnv*, jclass, jlong _address) {
    physx::PxConstraintInfo* _self = (physx::PxConstraintInfo*) _address;
    return (jint) _self->type;
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraintInfo__1setType(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxConstraintInfo* _self = (physx::PxConstraintInfo*) _address;
    _self->type = value;
}

// PxConstraintSolverPrep
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintSolverPrep__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxConstraintSolverPrep);
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraintSolverPrep__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxConstraintSolverPrep*) _address;
}

// PxContactPairHeaderFlags
JNIEXPORT jint JNICALL Java_physx_physics_PxContactPairHeaderFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxContactPairHeaderFlags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxContactPairHeaderFlags__1_1placement_1new_1PxContactPairHeaderFlags(JNIEnv*, jclass, jlong _placement_address, jshort flags) {
    return (jlong) new((void*)_placement_address) physx::PxContactPairHeaderFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxContactPairHeaderFlags__1PxContactPairHeaderFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxContactPairHeaderFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxContactPairHeaderFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxContactPairHeaderFlags* self = (physx::PxContactPairHeaderFlags*) _address;
    return (jboolean) self->isSet((PxContactPairHeaderFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairHeaderFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxContactPairHeaderFlags* self = (physx::PxContactPairHeaderFlags*) _address;
    self->raise((PxContactPairHeaderFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairHeaderFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxContactPairHeaderFlags* self = (physx::PxContactPairHeaderFlags*) _address;
    self->clear((PxContactPairHeaderFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairHeaderFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxContactPairHeaderFlags*) _address;
}

// PxContactPair
JNIEXPORT jint JNICALL Java_physx_physics_PxContactPair__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxContactPair);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxContactPair__1extractContacts(JNIEnv*, jclass, jlong _address, jlong userBuffer, jint bufferSize) {
    physx::PxContactPair* self = (physx::PxContactPair*) _address;
    return (jint) self->extractContacts((physx::PxContactPairPoint*) userBuffer, bufferSize);
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPair__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxContactPair*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxContactPair__1getShapes(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::PxContactPair* _self = (physx::PxContactPair*) _address;
    return (jlong) _self->shapes[_index];
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPair__1setShapes(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    physx::PxContactPair* _self = (physx::PxContactPair*) _address;
    _self->shapes[_index] = (physx::PxShape*) value;
}
JNIEXPORT jbyte JNICALL Java_physx_physics_PxContactPair__1getContactCount(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPair* _self = (physx::PxContactPair*) _address;
    return (jbyte) _self->contactCount;
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPair__1setContactCount(JNIEnv*, jclass, jlong _address, jbyte value) {
    physx::PxContactPair* _self = (physx::PxContactPair*) _address;
    _self->contactCount = value;
}
JNIEXPORT jbyte JNICALL Java_physx_physics_PxContactPair__1getPatchCount(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPair* _self = (physx::PxContactPair*) _address;
    return (jbyte) _self->patchCount;
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPair__1setPatchCount(JNIEnv*, jclass, jlong _address, jbyte value) {
    physx::PxContactPair* _self = (physx::PxContactPair*) _address;
    _self->patchCount = value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxContactPair__1getFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPair* _self = (physx::PxContactPair*) _address;
    return (jlong) &_self->flags;
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPair__1setFlags(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxContactPair* _self = (physx::PxContactPair*) _address;
    _self->flags = *((physx::PxContactPairFlags*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxContactPair__1getEvents(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPair* _self = (physx::PxContactPair*) _address;
    return (jlong) &_self->events;
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPair__1setEvents(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxContactPair* _self = (physx::PxContactPair*) _address;
    _self->events = *((physx::PxPairFlags*) value);
}

// PxContactPairFlags
JNIEXPORT jint JNICALL Java_physx_physics_PxContactPairFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxContactPairFlags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxContactPairFlags__1_1placement_1new_1PxContactPairFlags(JNIEnv*, jclass, jlong _placement_address, jshort flags) {
    return (jlong) new((void*)_placement_address) physx::PxContactPairFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxContactPairFlags__1PxContactPairFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxContactPairFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxContactPairFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxContactPairFlags* self = (physx::PxContactPairFlags*) _address;
    return (jboolean) self->isSet((PxContactPairFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxContactPairFlags* self = (physx::PxContactPairFlags*) _address;
    self->raise((PxContactPairFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxContactPairFlags* self = (physx::PxContactPairFlags*) _address;
    self->clear((PxContactPairFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxContactPairFlags*) _address;
}

// PxContactPairHeader
JNIEXPORT jint JNICALL Java_physx_physics_PxContactPairHeader__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxContactPairHeader);
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairHeader__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxContactPairHeader*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxContactPairHeader__1getActors(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::PxContactPairHeader* _self = (physx::PxContactPairHeader*) _address;
    return (jlong) _self->actors[_index];
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairHeader__1setActors(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    physx::PxContactPairHeader* _self = (physx::PxContactPairHeader*) _address;
    _self->actors[_index] = (physx::PxActor*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxContactPairHeader__1getFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPairHeader* _self = (physx::PxContactPairHeader*) _address;
    return (jlong) &_self->flags;
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairHeader__1setFlags(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxContactPairHeader* _self = (physx::PxContactPairHeader*) _address;
    _self->flags = *((physx::PxContactPairHeaderFlags*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxContactPairHeader__1getPairs(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPairHeader* _self = (physx::PxContactPairHeader*) _address;
    return (jlong) _self->pairs;
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairHeader__1setPairs(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxContactPairHeader* _self = (physx::PxContactPairHeader*) _address;
    _self->pairs = (physx::PxContactPair*) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxContactPairHeader__1getNbPairs(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPairHeader* _self = (physx::PxContactPairHeader*) _address;
    return (jint) _self->nbPairs;
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairHeader__1setNbPairs(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxContactPairHeader* _self = (physx::PxContactPairHeader*) _address;
    _self->nbPairs = value;
}

// PxContactPairPoint
JNIEXPORT jint JNICALL Java_physx_physics_PxContactPairPoint__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxContactPairPoint);
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairPoint__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxContactPairPoint*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxContactPairPoint__1getPosition(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPairPoint* _self = (physx::PxContactPairPoint*) _address;
    return (jlong) &_self->position;
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairPoint__1setPosition(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxContactPairPoint* _self = (physx::PxContactPairPoint*) _address;
    _self->position = *((physx::PxVec3*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxContactPairPoint__1getSeparation(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPairPoint* _self = (physx::PxContactPairPoint*) _address;
    return (jfloat) _self->separation;
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairPoint__1setSeparation(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxContactPairPoint* _self = (physx::PxContactPairPoint*) _address;
    _self->separation = value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxContactPairPoint__1getNormal(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPairPoint* _self = (physx::PxContactPairPoint*) _address;
    return (jlong) &_self->normal;
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairPoint__1setNormal(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxContactPairPoint* _self = (physx::PxContactPairPoint*) _address;
    _self->normal = *((physx::PxVec3*) value);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxContactPairPoint__1getInternalFaceIndex0(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPairPoint* _self = (physx::PxContactPairPoint*) _address;
    return (jint) _self->internalFaceIndex0;
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairPoint__1setInternalFaceIndex0(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxContactPairPoint* _self = (physx::PxContactPairPoint*) _address;
    _self->internalFaceIndex0 = value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxContactPairPoint__1getImpulse(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPairPoint* _self = (physx::PxContactPairPoint*) _address;
    return (jlong) &_self->impulse;
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairPoint__1setImpulse(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxContactPairPoint* _self = (physx::PxContactPairPoint*) _address;
    _self->impulse = *((physx::PxVec3*) value);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxContactPairPoint__1getInternalFaceIndex1(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPairPoint* _self = (physx::PxContactPairPoint*) _address;
    return (jint) _self->internalFaceIndex1;
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairPoint__1setInternalFaceIndex1(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxContactPairPoint* _self = (physx::PxContactPairPoint*) _address;
    _self->internalFaceIndex1 = value;
}

// PxDominanceGroupPair
JNIEXPORT jint JNICALL Java_physx_physics_PxDominanceGroupPair__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxDominanceGroupPair);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxDominanceGroupPair__1PxDominanceGroupPair(JNIEnv*, jclass, jbyte a, jbyte b) {
    return (jlong) new physx::PxDominanceGroupPair(a, b);
}
JNIEXPORT void JNICALL Java_physx_physics_PxDominanceGroupPair__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxDominanceGroupPair*) _address;
}
JNIEXPORT jbyte JNICALL Java_physx_physics_PxDominanceGroupPair__1getDominance0(JNIEnv*, jclass, jlong _address) {
    physx::PxDominanceGroupPair* _self = (physx::PxDominanceGroupPair*) _address;
    return (jbyte) _self->dominance0;
}
JNIEXPORT void JNICALL Java_physx_physics_PxDominanceGroupPair__1setDominance0(JNIEnv*, jclass, jlong _address, jbyte value) {
    physx::PxDominanceGroupPair* _self = (physx::PxDominanceGroupPair*) _address;
    _self->dominance0 = value;
}
JNIEXPORT jbyte JNICALL Java_physx_physics_PxDominanceGroupPair__1getDominance1(JNIEnv*, jclass, jlong _address) {
    physx::PxDominanceGroupPair* _self = (physx::PxDominanceGroupPair*) _address;
    return (jbyte) _self->dominance1;
}
JNIEXPORT void JNICALL Java_physx_physics_PxDominanceGroupPair__1setDominance1(JNIEnv*, jclass, jlong _address, jbyte value) {
    physx::PxDominanceGroupPair* _self = (physx::PxDominanceGroupPair*) _address;
    _self->dominance1 = value;
}

// PxFilterData
JNIEXPORT jint JNICALL Java_physx_physics_PxFilterData__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxFilterData);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxFilterData__1_1placement_1new_1PxFilterData__J(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxFilterData();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxFilterData__1_1placement_1new_1PxFilterData__JIIII(JNIEnv*, jclass, jlong _placement_address, jint w0, jint w1, jint w2, jint w3) {
    return (jlong) new((void*)_placement_address) physx::PxFilterData(w0, w1, w2, w3);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxFilterData__1PxFilterData__(JNIEnv*, jclass) {
    return (jlong) new physx::PxFilterData();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxFilterData__1PxFilterData__IIII(JNIEnv*, jclass, jint w0, jint w1, jint w2, jint w3) {
    return (jlong) new physx::PxFilterData(w0, w1, w2, w3);
}
JNIEXPORT void JNICALL Java_physx_physics_PxFilterData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxFilterData*) _address;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxFilterData__1getWord0(JNIEnv*, jclass, jlong _address) {
    physx::PxFilterData* _self = (physx::PxFilterData*) _address;
    return (jint) _self->word0;
}
JNIEXPORT void JNICALL Java_physx_physics_PxFilterData__1setWord0(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxFilterData* _self = (physx::PxFilterData*) _address;
    _self->word0 = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxFilterData__1getWord1(JNIEnv*, jclass, jlong _address) {
    physx::PxFilterData* _self = (physx::PxFilterData*) _address;
    return (jint) _self->word1;
}
JNIEXPORT void JNICALL Java_physx_physics_PxFilterData__1setWord1(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxFilterData* _self = (physx::PxFilterData*) _address;
    _self->word1 = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxFilterData__1getWord2(JNIEnv*, jclass, jlong _address) {
    physx::PxFilterData* _self = (physx::PxFilterData*) _address;
    return (jint) _self->word2;
}
JNIEXPORT void JNICALL Java_physx_physics_PxFilterData__1setWord2(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxFilterData* _self = (physx::PxFilterData*) _address;
    _self->word2 = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxFilterData__1getWord3(JNIEnv*, jclass, jlong _address) {
    physx::PxFilterData* _self = (physx::PxFilterData*) _address;
    return (jint) _self->word3;
}
JNIEXPORT void JNICALL Java_physx_physics_PxFilterData__1setWord3(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxFilterData* _self = (physx::PxFilterData*) _address;
    _self->word3 = value;
}

// PxMaterial
JNIEXPORT jint JNICALL Java_physx_physics_PxMaterial__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxMaterial);
}
JNIEXPORT void JNICALL Java_physx_physics_PxMaterial__1setDynamicFriction(JNIEnv*, jclass, jlong _address, jfloat coef) {
    physx::PxMaterial* self = (physx::PxMaterial*) _address;
    self->setDynamicFriction(coef);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxMaterial__1getDynamicFriction(JNIEnv*, jclass, jlong _address) {
    physx::PxMaterial* self = (physx::PxMaterial*) _address;
    return (jfloat) self->getDynamicFriction();
}
JNIEXPORT void JNICALL Java_physx_physics_PxMaterial__1setStaticFriction(JNIEnv*, jclass, jlong _address, jfloat coef) {
    physx::PxMaterial* self = (physx::PxMaterial*) _address;
    self->setStaticFriction(coef);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxMaterial__1getStaticFriction(JNIEnv*, jclass, jlong _address) {
    physx::PxMaterial* self = (physx::PxMaterial*) _address;
    return (jfloat) self->getStaticFriction();
}
JNIEXPORT void JNICALL Java_physx_physics_PxMaterial__1setRestitution(JNIEnv*, jclass, jlong _address, jfloat coef) {
    physx::PxMaterial* self = (physx::PxMaterial*) _address;
    self->setRestitution(coef);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxMaterial__1getRestitution(JNIEnv*, jclass, jlong _address) {
    physx::PxMaterial* self = (physx::PxMaterial*) _address;
    return (jfloat) self->getRestitution();
}
JNIEXPORT void JNICALL Java_physx_physics_PxMaterial__1setFlag(JNIEnv*, jclass, jlong _address, jint flag, jboolean b) {
    physx::PxMaterial* self = (physx::PxMaterial*) _address;
    self->setFlag((PxMaterialFlagEnum) flag, b);
}
JNIEXPORT void JNICALL Java_physx_physics_PxMaterial__1setFlags(JNIEnv*, jclass, jlong _address, jlong flags) {
    physx::PxMaterial* self = (physx::PxMaterial*) _address;
    self->setFlags(*((physx::PxMaterialFlags*) flags));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxMaterial__1getFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxMaterial* self = (physx::PxMaterial*) _address;
    static thread_local physx::PxMaterialFlags _cache = self->getFlags();
    _cache = self->getFlags();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxMaterial__1setFrictionCombineMode(JNIEnv*, jclass, jlong _address, jint combMode) {
    physx::PxMaterial* self = (physx::PxMaterial*) _address;
    self->setFrictionCombineMode((PxCombineModeEnum) combMode);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxMaterial__1getFrictionCombineMode(JNIEnv*, jclass, jlong _address) {
    physx::PxMaterial* self = (physx::PxMaterial*) _address;
    return (jint) self->getFrictionCombineMode();
}
JNIEXPORT void JNICALL Java_physx_physics_PxMaterial__1setRestitutionCombineMode(JNIEnv*, jclass, jlong _address, jint combMode) {
    physx::PxMaterial* self = (physx::PxMaterial*) _address;
    self->setRestitutionCombineMode((PxCombineModeEnum) combMode);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxMaterial__1getRestitutionCombineMode(JNIEnv*, jclass, jlong _address) {
    physx::PxMaterial* self = (physx::PxMaterial*) _address;
    return (jint) self->getRestitutionCombineMode();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxMaterial__1getUserData(JNIEnv*, jclass, jlong _address) {
    physx::PxMaterial* _self = (physx::PxMaterial*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_physx_physics_PxMaterial__1setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxMaterial* _self = (physx::PxMaterial*) _address;
    _self->userData = (void*) value;
}

// PxMaterialFlags
JNIEXPORT jint JNICALL Java_physx_physics_PxMaterialFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxMaterialFlags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxMaterialFlags__1_1placement_1new_1PxMaterialFlags(JNIEnv*, jclass, jlong _placement_address, jshort flags) {
    return (jlong) new((void*)_placement_address) physx::PxMaterialFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxMaterialFlags__1PxMaterialFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxMaterialFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxMaterialFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxMaterialFlags* self = (physx::PxMaterialFlags*) _address;
    return (jboolean) self->isSet((PxMaterialFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxMaterialFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxMaterialFlags* self = (physx::PxMaterialFlags*) _address;
    self->raise((PxMaterialFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxMaterialFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxMaterialFlags* self = (physx::PxMaterialFlags*) _address;
    self->clear((PxMaterialFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxMaterialFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxMaterialFlags*) _address;
}

// PxPairFlags
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxPairFlags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPairFlags__1_1placement_1new_1PxPairFlags(JNIEnv*, jclass, jlong _placement_address, jshort flags) {
    return (jlong) new((void*)_placement_address) physx::PxPairFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPairFlags__1PxPairFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxPairFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxPairFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxPairFlags* self = (physx::PxPairFlags*) _address;
    return (jboolean) self->isSet((PxPairFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxPairFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxPairFlags* self = (physx::PxPairFlags*) _address;
    self->raise((PxPairFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxPairFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxPairFlags* self = (physx::PxPairFlags*) _address;
    self->clear((PxPairFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxPairFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxPairFlags*) _address;
}

// PxPhysics
JNIEXPORT jint JNICALL Java_physx_physics_PxPhysics__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxPhysics);
}
JNIEXPORT void JNICALL Java_physx_physics_PxPhysics__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    self->release();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1getFoundation(JNIEnv*, jclass, jlong _address) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    return (jlong) &self->getFoundation();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1createAggregate(JNIEnv*, jclass, jlong _address, jint size, jint maxShape, jboolean enableSelfCollision) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    return (jlong) self->createAggregate(size, maxShape, enableSelfCollision);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1getTolerancesScale(JNIEnv*, jclass, jlong _address) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    return (jlong) &self->getTolerancesScale();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1createScene(JNIEnv*, jclass, jlong _address, jlong sceneDesc) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    return (jlong) self->createScene(*((physx::PxSceneDesc*) sceneDesc));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1createRigidStatic(JNIEnv*, jclass, jlong _address, jlong pose) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    return (jlong) self->createRigidStatic(*((physx::PxTransform*) pose));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1createRigidDynamic(JNIEnv*, jclass, jlong _address, jlong pose) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    return (jlong) self->createRigidDynamic(*((physx::PxTransform*) pose));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1createShape__JJJ(JNIEnv*, jclass, jlong _address, jlong geometry, jlong material) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    return (jlong) self->createShape(*((physx::PxGeometry*) geometry), *((physx::PxMaterial*) material));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1createShape__JJJZ(JNIEnv*, jclass, jlong _address, jlong geometry, jlong material, jboolean isExclusive) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    return (jlong) self->createShape(*((physx::PxGeometry*) geometry), *((physx::PxMaterial*) material), isExclusive);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1createShape__JJJZJ(JNIEnv*, jclass, jlong _address, jlong geometry, jlong material, jboolean isExclusive, jlong shapeFlags) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    return (jlong) self->createShape(*((physx::PxGeometry*) geometry), *((physx::PxMaterial*) material), isExclusive, *((physx::PxShapeFlags*) shapeFlags));
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPhysics__1getNbShapes(JNIEnv*, jclass, jlong _address) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    return (jint) self->getNbShapes();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1createArticulationReducedCoordinate(JNIEnv*, jclass, jlong _address) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    return (jlong) self->createArticulationReducedCoordinate();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1createMaterial(JNIEnv*, jclass, jlong _address, jfloat staticFriction, jfloat dynamicFriction, jfloat restitution) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    return (jlong) self->createMaterial(staticFriction, dynamicFriction, restitution);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1getPhysicsInsertionCallback(JNIEnv*, jclass, jlong _address) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    return (jlong) &self->getPhysicsInsertionCallback();
}
JNIEXPORT void JNICALL Java_physx_physics_PxPhysics__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxPhysics*) _address;
}

// PxSimulationEventCallback
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationEventCallback__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxSimulationEventCallback);
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationEventCallback__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSimulationEventCallback*) _address;
}

// SimpleSimulationEventCallback
JNIEXPORT jint JNICALL Java_physx_physics_SimpleSimulationEventCallback__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(SimpleSimulationEventCallback);
}
JNIEXPORT void JNICALL Java_physx_physics_SimpleSimulationEventCallback__1onConstraintBreak(JNIEnv*, jclass, jlong _address, jlong constraints, jint count) {
    SimpleSimulationEventCallback* self = (SimpleSimulationEventCallback*) _address;
    self->onConstraintBreak((physx::PxConstraintInfo*) constraints, count);
}
JNIEXPORT void JNICALL Java_physx_physics_SimpleSimulationEventCallback__1onWake(JNIEnv*, jclass, jlong _address, jlong actors, jint count) {
    SimpleSimulationEventCallback* self = (SimpleSimulationEventCallback*) _address;
    self->onWake((PxActorPtr*) actors, count);
}
JNIEXPORT void JNICALL Java_physx_physics_SimpleSimulationEventCallback__1onSleep(JNIEnv*, jclass, jlong _address, jlong actors, jint count) {
    SimpleSimulationEventCallback* self = (SimpleSimulationEventCallback*) _address;
    self->onSleep((PxActorPtr*) actors, count);
}
JNIEXPORT void JNICALL Java_physx_physics_SimpleSimulationEventCallback__1onContact(JNIEnv*, jclass, jlong _address, jlong pairHeader, jlong pairs, jint nbPairs) {
    SimpleSimulationEventCallback* self = (SimpleSimulationEventCallback*) _address;
    self->onContact(*((physx::PxContactPairHeader*) pairHeader), (physx::PxContactPair*) pairs, nbPairs);
}
JNIEXPORT void JNICALL Java_physx_physics_SimpleSimulationEventCallback__1onTrigger(JNIEnv*, jclass, jlong _address, jlong pairs, jint count) {
    SimpleSimulationEventCallback* self = (SimpleSimulationEventCallback*) _address;
    self->onTrigger((physx::PxTriggerPair*) pairs, count);
}
JNIEXPORT void JNICALL Java_physx_physics_SimpleSimulationEventCallback__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (SimpleSimulationEventCallback*) _address;
}

// PxSimulationEventCallbackImpl
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationEventCallbackImpl__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxSimulationEventCallbackImpl);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSimulationEventCallbackImpl__1PxSimulationEventCallbackImpl(JNIEnv* env, jobject obj) {
    return (jlong) new PxSimulationEventCallbackImpl(env, obj);
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationEventCallbackImpl__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (PxSimulationEventCallbackImpl*) address;
}

// PxSimulationFilterShader
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationFilterShader__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxSimulationFilterShader);
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationFilterShader__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSimulationFilterShader*) _address;
}

// PxSimulationStatistics
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxSimulationStatistics);
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSimulationStatistics*) _address;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbActiveConstraints(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbActiveConstraints;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbActiveConstraints(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbActiveConstraints = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbActiveDynamicBodies(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbActiveDynamicBodies;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbActiveDynamicBodies(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbActiveDynamicBodies = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbActiveKinematicBodies(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbActiveKinematicBodies;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbActiveKinematicBodies(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbActiveKinematicBodies = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbStaticBodies(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbStaticBodies;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbStaticBodies(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbStaticBodies = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbDynamicBodies(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbDynamicBodies;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbDynamicBodies(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbDynamicBodies = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbKinematicBodies(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbKinematicBodies;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbKinematicBodies(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbKinematicBodies = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbShapes(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbShapes[_index];
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbShapes(JNIEnv*, jclass, jlong _address, jint _index, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbShapes[_index] = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbAggregates(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbAggregates;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbAggregates(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbAggregates = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbArticulations(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbArticulations;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbArticulations(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbArticulations = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbAxisSolverConstraints(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbAxisSolverConstraints;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbAxisSolverConstraints(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbAxisSolverConstraints = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getCompressedContactSize(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->compressedContactSize;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setCompressedContactSize(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->compressedContactSize = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getRequiredContactConstraintMemory(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->requiredContactConstraintMemory;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setRequiredContactConstraintMemory(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->requiredContactConstraintMemory = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getPeakConstraintMemory(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->peakConstraintMemory;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setPeakConstraintMemory(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->peakConstraintMemory = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbDiscreteContactPairsTotal(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbDiscreteContactPairsTotal;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbDiscreteContactPairsTotal(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbDiscreteContactPairsTotal = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbDiscreteContactPairsWithCacheHits(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbDiscreteContactPairsWithCacheHits;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbDiscreteContactPairsWithCacheHits(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbDiscreteContactPairsWithCacheHits = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbDiscreteContactPairsWithContacts(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbDiscreteContactPairsWithContacts;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbDiscreteContactPairsWithContacts(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbDiscreteContactPairsWithContacts = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbNewPairs(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbNewPairs;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbNewPairs(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbNewPairs = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbLostPairs(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbLostPairs;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbLostPairs(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbLostPairs = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbNewTouches(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbNewTouches;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbNewTouches(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbNewTouches = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbLostTouches(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbLostTouches;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbLostTouches(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbLostTouches = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbPartitions(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbPartitions;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbPartitions(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbPartitions = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbBroadPhaseAdds(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbBroadPhaseAdds;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbBroadPhaseAdds(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbBroadPhaseAdds = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbBroadPhaseRemoves(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbBroadPhaseRemoves;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbBroadPhaseRemoves(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbBroadPhaseRemoves = value;
}

// PxTriggerPair
JNIEXPORT jint JNICALL Java_physx_physics_PxTriggerPair__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxTriggerPair);
}
JNIEXPORT void JNICALL Java_physx_physics_PxTriggerPair__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxTriggerPair*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxTriggerPair__1getTriggerShape(JNIEnv*, jclass, jlong _address) {
    physx::PxTriggerPair* _self = (physx::PxTriggerPair*) _address;
    return (jlong) _self->triggerShape;
}
JNIEXPORT void JNICALL Java_physx_physics_PxTriggerPair__1setTriggerShape(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxTriggerPair* _self = (physx::PxTriggerPair*) _address;
    _self->triggerShape = (physx::PxShape*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxTriggerPair__1getTriggerActor(JNIEnv*, jclass, jlong _address) {
    physx::PxTriggerPair* _self = (physx::PxTriggerPair*) _address;
    return (jlong) _self->triggerActor;
}
JNIEXPORT void JNICALL Java_physx_physics_PxTriggerPair__1setTriggerActor(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxTriggerPair* _self = (physx::PxTriggerPair*) _address;
    _self->triggerActor = (physx::PxActor*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxTriggerPair__1getOtherShape(JNIEnv*, jclass, jlong _address) {
    physx::PxTriggerPair* _self = (physx::PxTriggerPair*) _address;
    return (jlong) _self->otherShape;
}
JNIEXPORT void JNICALL Java_physx_physics_PxTriggerPair__1setOtherShape(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxTriggerPair* _self = (physx::PxTriggerPair*) _address;
    _self->otherShape = (physx::PxShape*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxTriggerPair__1getOtherActor(JNIEnv*, jclass, jlong _address) {
    physx::PxTriggerPair* _self = (physx::PxTriggerPair*) _address;
    return (jlong) _self->otherActor;
}
JNIEXPORT void JNICALL Java_physx_physics_PxTriggerPair__1setOtherActor(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxTriggerPair* _self = (physx::PxTriggerPair*) _address;
    _self->otherActor = (physx::PxActor*) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxTriggerPair__1getStatus(JNIEnv*, jclass, jlong _address) {
    physx::PxTriggerPair* _self = (physx::PxTriggerPair*) _address;
    return (jint) _self->status;
}
JNIEXPORT void JNICALL Java_physx_physics_PxTriggerPair__1setStatus(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxTriggerPair* _self = (physx::PxTriggerPair*) _address;
    _self->status = (PxPairFlagEnum) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxTriggerPair__1getFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxTriggerPair* _self = (physx::PxTriggerPair*) _address;
    return (jlong) &_self->flags;
}
JNIEXPORT void JNICALL Java_physx_physics_PxTriggerPair__1setFlags(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxTriggerPair* _self = (physx::PxTriggerPair*) _address;
    _self->flags = *((physx::PxTriggerPairFlags*) value);
}

// PxTriggerPairFlags
JNIEXPORT jint JNICALL Java_physx_physics_PxTriggerPairFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxTriggerPairFlags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxTriggerPairFlags__1_1placement_1new_1PxTriggerPairFlags(JNIEnv*, jclass, jlong _placement_address, jbyte flags) {
    return (jlong) new((void*)_placement_address) physx::PxTriggerPairFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxTriggerPairFlags__1PxTriggerPairFlags(JNIEnv*, jclass, jbyte flags) {
    return (jlong) new physx::PxTriggerPairFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxTriggerPairFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxTriggerPairFlags* self = (physx::PxTriggerPairFlags*) _address;
    return (jboolean) self->isSet((PxTriggerPairFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxTriggerPairFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxTriggerPairFlags* self = (physx::PxTriggerPairFlags*) _address;
    self->raise((PxTriggerPairFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxTriggerPairFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxTriggerPairFlags* self = (physx::PxTriggerPairFlags*) _address;
    self->clear((PxTriggerPairFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxTriggerPairFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxTriggerPairFlags*) _address;
}

// PxScene
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxScene);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1addActor__JJ(JNIEnv*, jclass, jlong _address, jlong actor) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->addActor(*((physx::PxActor*) actor));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1addActor__JJJ(JNIEnv*, jclass, jlong _address, jlong actor, jlong bvhStructure) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->addActor(*((physx::PxActor*) actor), (physx::PxBVHStructure*) bvhStructure);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1removeActor__JJ(JNIEnv*, jclass, jlong _address, jlong actor) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->removeActor(*((physx::PxActor*) actor));
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1removeActor__JJZ(JNIEnv*, jclass, jlong _address, jlong actor, jboolean wakeOnLostTouch) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->removeActor(*((physx::PxActor*) actor), wakeOnLostTouch);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1addAggregate(JNIEnv*, jclass, jlong _address, jlong aggregate) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->addAggregate(*((physx::PxAggregate*) aggregate));
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1removeAggregate__JJ(JNIEnv*, jclass, jlong _address, jlong aggregate) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->removeAggregate(*((physx::PxAggregate*) aggregate));
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1removeAggregate__JJZ(JNIEnv*, jclass, jlong _address, jlong aggregate, jboolean wakeOnLostTouch) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->removeAggregate(*((physx::PxAggregate*) aggregate), wakeOnLostTouch);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1addCollection(JNIEnv*, jclass, jlong _address, jlong collection) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->addCollection(*((physx::PxCollection*) collection));
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxScene__1getWakeCounterResetValue(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jfloat) self->getWakeCounterResetValue();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1shiftOrigin(JNIEnv*, jclass, jlong _address, jlong shift) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->shiftOrigin(*((physx::PxVec3*) shift));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1addArticulation(JNIEnv*, jclass, jlong _address, jlong articulation) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->addArticulation(*((physx::PxArticulationReducedCoordinate*) articulation));
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1removeArticulation__JJ(JNIEnv*, jclass, jlong _address, jlong articulation) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->removeArticulation(*((physx::PxArticulationReducedCoordinate*) articulation));
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1removeArticulation__JJZ(JNIEnv*, jclass, jlong _address, jlong articulation, jboolean wakeOnLostTouch) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->removeArticulation(*((physx::PxArticulationReducedCoordinate*) articulation), wakeOnLostTouch);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getNbActors(JNIEnv*, jclass, jlong _address, jlong types) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getNbActors(*((physx::PxActorTypeFlags*) types));
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getNbSoftBodies(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getNbSoftBodies();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getNbParticleSystems(JNIEnv*, jclass, jlong _address, jint type) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getNbParticleSystems((PxParticleSolverTypeEnum) type);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getNbArticulations(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getNbArticulations();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getNbConstraints(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getNbConstraints();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getNbAggregates(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getNbAggregates();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setDominanceGroupPair(JNIEnv*, jclass, jlong _address, jbyte group1, jbyte group2, jlong dominance) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setDominanceGroupPair(group1, group2, *((physx::PxDominanceGroupPair*) dominance));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxScene__1getDominanceGroupPair(JNIEnv*, jclass, jlong _address, jbyte group1, jbyte group2) {
    physx::PxScene* self = (physx::PxScene*) _address;
    static thread_local physx::PxDominanceGroupPair _cache = self->getDominanceGroupPair(group1, group2);
    _cache = self->getDominanceGroupPair(group1, group2);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxScene__1getCpuDispatcher(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jlong) self->getCpuDispatcher();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxScene__1getCudaContextManager(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jlong) self->getCudaContextManager();
}
JNIEXPORT jbyte JNICALL Java_physx_physics_PxScene__1createClient(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jbyte) self->createClient();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setSimulationEventCallback(JNIEnv*, jclass, jlong _address, jlong callback) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setSimulationEventCallback((physx::PxSimulationEventCallback*) callback);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxScene__1getSimulationEventCallback(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jlong) self->getSimulationEventCallback();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setFilterShaderData(JNIEnv*, jclass, jlong _address, jlong data, jint dataSize) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setFilterShaderData((void*) data, dataSize);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxScene__1getFilterShaderData(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jlong) self->getFilterShaderData();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getFilterShaderDataSize(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getFilterShaderDataSize();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxScene__1getFilterShader(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    static thread_local physx::PxSimulationFilterShader _cache = self->getFilterShader();
    _cache = self->getFilterShader();
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1resetFiltering(JNIEnv*, jclass, jlong _address, jlong actor) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->resetFiltering(*((physx::PxActor*) actor));
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getKinematicKinematicFilteringMode(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getKinematicKinematicFilteringMode();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getStaticKinematicFilteringMode(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getStaticKinematicFilteringMode();
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1simulate__JF(JNIEnv*, jclass, jlong _address, jfloat elapsedTime) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->simulate(elapsedTime);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1simulate__JFJ(JNIEnv*, jclass, jlong _address, jfloat elapsedTime, jlong completionTask) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->simulate(elapsedTime, (physx::PxBaseTask*) completionTask);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1simulate__JFJJ(JNIEnv*, jclass, jlong _address, jfloat elapsedTime, jlong completionTask, jlong scratchMemBlock) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->simulate(elapsedTime, (physx::PxBaseTask*) completionTask, (void*) scratchMemBlock);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1simulate__JFJJI(JNIEnv*, jclass, jlong _address, jfloat elapsedTime, jlong completionTask, jlong scratchMemBlock, jint scratchMemBlockSize) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->simulate(elapsedTime, (physx::PxBaseTask*) completionTask, (void*) scratchMemBlock, scratchMemBlockSize);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1simulate__JFJJIZ(JNIEnv*, jclass, jlong _address, jfloat elapsedTime, jlong completionTask, jlong scratchMemBlock, jint scratchMemBlockSize, jboolean controlSimulation) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->simulate(elapsedTime, (physx::PxBaseTask*) completionTask, (void*) scratchMemBlock, scratchMemBlockSize, controlSimulation);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1advance__J(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->advance();
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1advance__JJ(JNIEnv*, jclass, jlong _address, jlong completionTask) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->advance((physx::PxBaseTask*) completionTask);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1collide__JF(JNIEnv*, jclass, jlong _address, jfloat elapsedTime) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->collide(elapsedTime);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1collide__JFJ(JNIEnv*, jclass, jlong _address, jfloat elapsedTime, jlong completionTask) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->collide(elapsedTime, (physx::PxBaseTask*) completionTask);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1collide__JFJJ(JNIEnv*, jclass, jlong _address, jfloat elapsedTime, jlong completionTask, jlong scratchMemBlock) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->collide(elapsedTime, (physx::PxBaseTask*) completionTask, (void*) scratchMemBlock);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1collide__JFJJI(JNIEnv*, jclass, jlong _address, jfloat elapsedTime, jlong completionTask, jlong scratchMemBlock, jint scratchMemBlockSize) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->collide(elapsedTime, (physx::PxBaseTask*) completionTask, (void*) scratchMemBlock, scratchMemBlockSize);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1collide__JFJJIZ(JNIEnv*, jclass, jlong _address, jfloat elapsedTime, jlong completionTask, jlong scratchMemBlock, jint scratchMemBlockSize, jboolean controlSimulation) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->collide(elapsedTime, (physx::PxBaseTask*) completionTask, (void*) scratchMemBlock, scratchMemBlockSize, controlSimulation);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1checkResults__J(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->checkResults();
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1checkResults__JZ(JNIEnv*, jclass, jlong _address, jboolean block) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->checkResults(block);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1fetchCollision__J(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->fetchCollision();
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1fetchCollision__JZ(JNIEnv*, jclass, jlong _address, jboolean block) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->fetchCollision(block);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1fetchResults__J(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->fetchResults();
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1fetchResults__JZ(JNIEnv*, jclass, jlong _address, jboolean block) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->fetchResults(block);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1processCallbacks(JNIEnv*, jclass, jlong _address, jlong continuation) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->processCallbacks((physx::PxBaseTask*) continuation);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1fetchResultsParticleSystem(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->fetchResultsParticleSystem();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1flushSimulation__J(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->flushSimulation();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1flushSimulation__JZ(JNIEnv*, jclass, jlong _address, jboolean sendPendingReports) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->flushSimulation(sendPendingReports);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setGravity(JNIEnv*, jclass, jlong _address, jlong vec) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setGravity(*((physx::PxVec3*) vec));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxScene__1getGravity(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    static thread_local physx::PxVec3 _cache = self->getGravity();
    _cache = self->getGravity();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setBounceThresholdVelocity(JNIEnv*, jclass, jlong _address, jfloat t) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setBounceThresholdVelocity(t);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxScene__1getBounceThresholdVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jfloat) self->getBounceThresholdVelocity();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setCCDMaxPasses(JNIEnv*, jclass, jlong _address, jint ccdMaxPasses) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setCCDMaxPasses(ccdMaxPasses);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getCCDMaxPasses(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getCCDMaxPasses();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setCCDMaxSeparation(JNIEnv*, jclass, jlong _address, jfloat t) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setCCDMaxSeparation(t);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxScene__1getCCDMaxSeparation(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jfloat) self->getCCDMaxSeparation();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setCCDThreshold(JNIEnv*, jclass, jlong _address, jfloat t) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setCCDThreshold(t);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxScene__1getCCDThreshold(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jfloat) self->getCCDThreshold();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setMaxBiasCoefficient(JNIEnv*, jclass, jlong _address, jfloat t) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setMaxBiasCoefficient(t);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxScene__1getMaxBiasCoefficient(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jfloat) self->getMaxBiasCoefficient();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setFrictionOffsetThreshold(JNIEnv*, jclass, jlong _address, jfloat t) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setFrictionOffsetThreshold(t);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxScene__1getFrictionOffsetThreshold(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jfloat) self->getFrictionOffsetThreshold();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setFrictionCorrelationDistance(JNIEnv*, jclass, jlong _address, jfloat t) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setFrictionCorrelationDistance(t);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxScene__1getFrictionCorrelationDistance(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jfloat) self->getFrictionCorrelationDistance();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getFrictionType(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getFrictionType();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getSolverType(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getSolverType();
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1setVisualizationParameter(JNIEnv*, jclass, jlong _address, jint param, jfloat value) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->setVisualizationParameter((PxVisualizationParameterEnum) param, value);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxScene__1getVisualizationParameter(JNIEnv*, jclass, jlong _address, jint paramEnum) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jfloat) self->getVisualizationParameter((PxVisualizationParameterEnum) paramEnum);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setVisualizationCullingBox(JNIEnv*, jclass, jlong _address, jlong box) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setVisualizationCullingBox(*((physx::PxBounds3*) box));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxScene__1getVisualizationCullingBox(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    static thread_local physx::PxBounds3 _cache = self->getVisualizationCullingBox();
    _cache = self->getVisualizationCullingBox();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1getSimulationStatistics(JNIEnv*, jclass, jlong _address, jlong stats) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->getSimulationStatistics(*((physx::PxSimulationStatistics*) stats));
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getBroadPhaseType(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getBroadPhaseType();
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1getBroadPhaseCaps(JNIEnv*, jclass, jlong _address, jlong caps) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->getBroadPhaseCaps(*((physx::PxBroadPhaseCaps*) caps));
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getNbBroadPhaseRegions(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getNbBroadPhaseRegions();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getBroadPhaseRegions__JJI(JNIEnv*, jclass, jlong _address, jlong userBuffer, jint bufferSize) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getBroadPhaseRegions((physx::PxBroadPhaseRegionInfo*) userBuffer, bufferSize);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getBroadPhaseRegions__JJII(JNIEnv*, jclass, jlong _address, jlong userBuffer, jint bufferSize, jint startIndex) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getBroadPhaseRegions((physx::PxBroadPhaseRegionInfo*) userBuffer, bufferSize, startIndex);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1addBroadPhaseRegion__JJ(JNIEnv*, jclass, jlong _address, jlong region) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->addBroadPhaseRegion(*((physx::PxBroadPhaseRegion*) region));
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1addBroadPhaseRegion__JJZ(JNIEnv*, jclass, jlong _address, jlong region, jboolean populateRegion) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->addBroadPhaseRegion(*((physx::PxBroadPhaseRegion*) region), populateRegion);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1removeBroadPhaseRegion(JNIEnv*, jclass, jlong _address, jint handle) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->removeBroadPhaseRegion(handle);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1lockRead__J(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->lockRead();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1lockRead__JLjava_lang_String_2(JNIEnv* _env, jclass, jlong _address, jstring file) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->lockRead(_env->GetStringUTFChars(file, 0));
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1lockRead__JLjava_lang_String_2I(JNIEnv* _env, jclass, jlong _address, jstring file, jint line) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->lockRead(_env->GetStringUTFChars(file, 0), line);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1unlockRead(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->unlockRead();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1lockWrite__J(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->lockWrite();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1lockWrite__JLjava_lang_String_2(JNIEnv* _env, jclass, jlong _address, jstring file) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->lockWrite(_env->GetStringUTFChars(file, 0));
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1lockWrite__JLjava_lang_String_2I(JNIEnv* _env, jclass, jlong _address, jstring file, jint line) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->lockWrite(_env->GetStringUTFChars(file, 0), line);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1unlockWrite(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->unlockWrite();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setNbContactDataBlocks(JNIEnv*, jclass, jlong _address, jint numBlocks) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setNbContactDataBlocks(numBlocks);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getNbContactDataBlocksUsed(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getNbContactDataBlocksUsed();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getMaxNbContactDataBlocksUsed(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getMaxNbContactDataBlocksUsed();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getContactReportStreamBufferSize(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getContactReportStreamBufferSize();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setSolverBatchSize(JNIEnv*, jclass, jlong _address, jint solverBatchSize) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setSolverBatchSize(solverBatchSize);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getSolverBatchSize(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getSolverBatchSize();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setSolverArticulationBatchSize(JNIEnv*, jclass, jlong _address, jint solverBatchSize) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setSolverArticulationBatchSize(solverBatchSize);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getSolverArticulationBatchSize(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getSolverArticulationBatchSize();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->release();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setFlag(JNIEnv*, jclass, jlong _address, jint flag, jboolean value) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setFlag((PxSceneFlagEnum) flag, value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxScene__1getFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    static thread_local physx::PxSceneFlags _cache = self->getFlags();
    _cache = self->getFlags();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setLimits(JNIEnv*, jclass, jlong _address, jlong limits) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setLimits(*((physx::PxSceneLimits*) limits));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxScene__1getLimits(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    static thread_local physx::PxSceneLimits _cache = self->getLimits();
    _cache = self->getLimits();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxScene__1getPhysics(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jlong) &self->getPhysics();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getTimestamp(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getTimestamp();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxScene__1getUserData(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* _self = (physx::PxScene*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxScene* _self = (physx::PxScene*) _address;
    _self->userData = (void*) value;
}

// PxSceneDesc
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxSceneDesc);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1_1placement_1new_1PxSceneDesc(JNIEnv*, jclass, jlong _placement_address, jlong scale) {
    return (jlong) new((void*)_placement_address) physx::PxSceneDesc(*((physx::PxTolerancesScale*) scale));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1PxSceneDesc(JNIEnv*, jclass, jlong scale) {
    return (jlong) new physx::PxSceneDesc(*((physx::PxTolerancesScale*) scale));
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setToDefault(JNIEnv*, jclass, jlong _address, jlong scale) {
    physx::PxSceneDesc* self = (physx::PxSceneDesc*) _address;
    self->setToDefault(*((physx::PxTolerancesScale*) scale));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxSceneDesc__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* self = (physx::PxSceneDesc*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSceneDesc*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1getGravity(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jlong) &_self->gravity;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setGravity(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->gravity = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1getSimulationEventCallback(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jlong) _self->simulationEventCallback;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setSimulationEventCallback(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->simulationEventCallback = (physx::PxSimulationEventCallback*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1getFilterShaderData(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jlong) _self->filterShaderData;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setFilterShaderData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->filterShaderData = (void*) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getFilterShaderDataSize(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->filterShaderDataSize;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setFilterShaderDataSize(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->filterShaderDataSize = value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1getFilterShader(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jlong) &_self->filterShader;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setFilterShader(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->filterShader = *((physx::PxSimulationFilterShader*) value);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getKineKineFilteringMode(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->kineKineFilteringMode;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setKineKineFilteringMode(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->kineKineFilteringMode = (PxPairFilteringModeEnum) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getStaticKineFilteringMode(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->staticKineFilteringMode;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setStaticKineFilteringMode(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->staticKineFilteringMode = (PxPairFilteringModeEnum) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getBroadPhaseType(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->broadPhaseType;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setBroadPhaseType(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->broadPhaseType = (PxBroadPhaseTypeEnum) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1getLimits(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jlong) &_self->limits;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setLimits(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->limits = *((physx::PxSceneLimits*) value);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getFrictionType(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->frictionType;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setFrictionType(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->frictionType = (PxFrictionTypeEnum) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getSolverType(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->solverType;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setSolverType(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->solverType = (PxSolverTypeEnum) value;
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxSceneDesc__1getBounceThresholdVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jfloat) _self->bounceThresholdVelocity;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setBounceThresholdVelocity(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->bounceThresholdVelocity = value;
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxSceneDesc__1getFrictionOffsetThreshold(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jfloat) _self->frictionOffsetThreshold;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setFrictionOffsetThreshold(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->frictionOffsetThreshold = value;
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxSceneDesc__1getFrictionCorrelationDistance(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jfloat) _self->frictionCorrelationDistance;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setFrictionCorrelationDistance(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->frictionCorrelationDistance = value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1getFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jlong) &_self->flags;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setFlags(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->flags = *((physx::PxSceneFlags*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1getCpuDispatcher(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jlong) _self->cpuDispatcher;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setCpuDispatcher(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->cpuDispatcher = (physx::PxCpuDispatcher*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1getCudaContextManager(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jlong) _self->cudaContextManager;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setCudaContextManager(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->cudaContextManager = (physx::PxCudaContextManager*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1getUserData(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->userData = (void*) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getSolverBatchSize(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->solverBatchSize;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setSolverBatchSize(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->solverBatchSize = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getSolverArticulationBatchSize(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->solverArticulationBatchSize;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setSolverArticulationBatchSize(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->solverArticulationBatchSize = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getNbContactDataBlocks(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->nbContactDataBlocks;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setNbContactDataBlocks(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->nbContactDataBlocks = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getMaxNbContactDataBlocks(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->maxNbContactDataBlocks;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setMaxNbContactDataBlocks(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->maxNbContactDataBlocks = value;
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxSceneDesc__1getMaxBiasCoefficient(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jfloat) _self->maxBiasCoefficient;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setMaxBiasCoefficient(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->maxBiasCoefficient = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getContactReportStreamBufferSize(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->contactReportStreamBufferSize;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setContactReportStreamBufferSize(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->contactReportStreamBufferSize = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getCcdMaxPasses(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->ccdMaxPasses;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setCcdMaxPasses(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->ccdMaxPasses = value;
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxSceneDesc__1getCcdThreshold(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jfloat) _self->ccdThreshold;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setCcdThreshold(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->ccdThreshold = value;
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxSceneDesc__1getCcdMaxSeparation(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jfloat) _self->ccdMaxSeparation;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setCcdMaxSeparation(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->ccdMaxSeparation = value;
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxSceneDesc__1getWakeCounterResetValue(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jfloat) _self->wakeCounterResetValue;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setWakeCounterResetValue(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->wakeCounterResetValue = value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1getSanityBounds(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jlong) &_self->sanityBounds;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setSanityBounds(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->sanityBounds = *((physx::PxBounds3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1getGpuDynamicsConfig(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jlong) &_self->gpuDynamicsConfig;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setGpuDynamicsConfig(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->gpuDynamicsConfig = *((physx::PxgDynamicsMemoryConfig*) value);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getGpuMaxNumPartitions(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->gpuMaxNumPartitions;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setGpuMaxNumPartitions(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->gpuMaxNumPartitions = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getGpuMaxNumStaticPartitions(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->gpuMaxNumStaticPartitions;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setGpuMaxNumStaticPartitions(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->gpuMaxNumStaticPartitions = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getGpuComputeVersion(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->gpuComputeVersion;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setGpuComputeVersion(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->gpuComputeVersion = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getContactPairSlabSize(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->contactPairSlabSize;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setContactPairSlabSize(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->contactPairSlabSize = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getStaticStructure(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->staticStructure;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setStaticStructure(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->staticStructure = (PxPruningStructureTypeEnum) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getDynamicStructure(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->dynamicStructure;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setDynamicStructure(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->dynamicStructure = (PxPruningStructureTypeEnum) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getDynamicTreeRebuildRateHint(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->dynamicTreeRebuildRateHint;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setDynamicTreeRebuildRateHint(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->dynamicTreeRebuildRateHint = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getDynamicTreeSecondaryPruner(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->dynamicTreeSecondaryPruner;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setDynamicTreeSecondaryPruner(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->dynamicTreeSecondaryPruner = (PxDynamicTreeSecondaryPrunerEnum) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getStaticBVHBuildStrategy(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->staticBVHBuildStrategy;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setStaticBVHBuildStrategy(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->staticBVHBuildStrategy = (PxBVHBuildStrategyEnum) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getDynamicBVHBuildStrategy(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->dynamicBVHBuildStrategy;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setDynamicBVHBuildStrategy(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->dynamicBVHBuildStrategy = (PxBVHBuildStrategyEnum) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getStaticNbObjectsPerNode(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->staticNbObjectsPerNode;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setStaticNbObjectsPerNode(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->staticNbObjectsPerNode = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getDynamicNbObjectsPerNode(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->dynamicNbObjectsPerNode;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setDynamicNbObjectsPerNode(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->dynamicNbObjectsPerNode = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getSceneQueryUpdateMode(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->sceneQueryUpdateMode;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setSceneQueryUpdateMode(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->sceneQueryUpdateMode = (PxSceneQueryUpdateModeEnum) value;
}

// PxSceneFlags
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxSceneFlags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneFlags__1_1placement_1new_1PxSceneFlags(JNIEnv*, jclass, jlong _placement_address, jint flags) {
    return (jlong) new((void*)_placement_address) physx::PxSceneFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneFlags__1PxSceneFlags(JNIEnv*, jclass, jint flags) {
    return (jlong) new physx::PxSceneFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxSceneFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxSceneFlags* self = (physx::PxSceneFlags*) _address;
    return (jboolean) self->isSet((PxSceneFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxSceneFlags* self = (physx::PxSceneFlags*) _address;
    self->raise((PxSceneFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxSceneFlags* self = (physx::PxSceneFlags*) _address;
    self->clear((PxSceneFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSceneFlags*) _address;
}

// PxSceneLimits
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneLimits__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxSceneLimits);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneLimits__1_1placement_1new_1PxSceneLimits(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxSceneLimits();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneLimits__1PxSceneLimits(JNIEnv*, jclass) {
    return (jlong) new physx::PxSceneLimits();
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneLimits__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneLimits* self = (physx::PxSceneLimits*) _address;
    self->setToDefault();
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxSceneLimits__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneLimits* self = (physx::PxSceneLimits*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneLimits__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSceneLimits*) _address;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneLimits__1getMaxNbActors(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    return (jint) _self->maxNbActors;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneLimits__1setMaxNbActors(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    _self->maxNbActors = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneLimits__1getMaxNbBodies(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    return (jint) _self->maxNbBodies;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneLimits__1setMaxNbBodies(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    _self->maxNbBodies = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneLimits__1getMaxNbStaticShapes(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    return (jint) _self->maxNbStaticShapes;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneLimits__1setMaxNbStaticShapes(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    _self->maxNbStaticShapes = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneLimits__1getMaxNbDynamicShapes(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    return (jint) _self->maxNbDynamicShapes;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneLimits__1setMaxNbDynamicShapes(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    _self->maxNbDynamicShapes = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneLimits__1getMaxNbAggregates(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    return (jint) _self->maxNbAggregates;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneLimits__1setMaxNbAggregates(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    _self->maxNbAggregates = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneLimits__1getMaxNbConstraints(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    return (jint) _self->maxNbConstraints;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneLimits__1setMaxNbConstraints(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    _self->maxNbConstraints = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneLimits__1getMaxNbRegions(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    return (jint) _self->maxNbRegions;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneLimits__1setMaxNbRegions(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    _self->maxNbRegions = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneLimits__1getMaxNbBroadPhaseOverlaps(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    return (jint) _self->maxNbBroadPhaseOverlaps;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneLimits__1setMaxNbBroadPhaseOverlaps(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    _self->maxNbBroadPhaseOverlaps = value;
}

// PxGeomRaycastHit
JNIEXPORT jint JNICALL Java_physx_physics_PxGeomRaycastHit__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxGeomRaycastHit);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxGeomRaycastHit__1hadInitialOverlap(JNIEnv*, jclass, jlong _address) {
    physx::PxGeomRaycastHit* self = (physx::PxGeomRaycastHit*) _address;
    return (jboolean) self->hadInitialOverlap();
}
JNIEXPORT void JNICALL Java_physx_physics_PxGeomRaycastHit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxGeomRaycastHit*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxGeomRaycastHit__1getU(JNIEnv*, jclass, jlong _address) {
    physx::PxGeomRaycastHit* _self = (physx::PxGeomRaycastHit*) _address;
    return (jfloat) _self->u;
}
JNIEXPORT void JNICALL Java_physx_physics_PxGeomRaycastHit__1setU(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxGeomRaycastHit* _self = (physx::PxGeomRaycastHit*) _address;
    _self->u = value;
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxGeomRaycastHit__1getV(JNIEnv*, jclass, jlong _address) {
    physx::PxGeomRaycastHit* _self = (physx::PxGeomRaycastHit*) _address;
    return (jfloat) _self->v;
}
JNIEXPORT void JNICALL Java_physx_physics_PxGeomRaycastHit__1setV(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxGeomRaycastHit* _self = (physx::PxGeomRaycastHit*) _address;
    _self->v = value;
}

// PxGeomSweepHit
JNIEXPORT jint JNICALL Java_physx_physics_PxGeomSweepHit__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxGeomSweepHit);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxGeomSweepHit__1hadInitialOverlap(JNIEnv*, jclass, jlong _address) {
    physx::PxGeomSweepHit* self = (physx::PxGeomSweepHit*) _address;
    return (jboolean) self->hadInitialOverlap();
}
JNIEXPORT void JNICALL Java_physx_physics_PxGeomSweepHit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxGeomSweepHit*) _address;
}

// PxHitFlags
JNIEXPORT jint JNICALL Java_physx_physics_PxHitFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxHitFlags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxHitFlags__1_1placement_1new_1PxHitFlags(JNIEnv*, jclass, jlong _placement_address, jshort flags) {
    return (jlong) new((void*)_placement_address) physx::PxHitFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxHitFlags__1PxHitFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxHitFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxHitFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxHitFlags* self = (physx::PxHitFlags*) _address;
    return (jboolean) self->isSet((PxHitFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxHitFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxHitFlags* self = (physx::PxHitFlags*) _address;
    self->raise((PxHitFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxHitFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxHitFlags* self = (physx::PxHitFlags*) _address;
    self->clear((PxHitFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxHitFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxHitFlags*) _address;
}

// PxLocationHit
JNIEXPORT jint JNICALL Java_physx_physics_PxLocationHit__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxLocationHit);
}
JNIEXPORT void JNICALL Java_physx_physics_PxLocationHit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxLocationHit*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxLocationHit__1getFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxLocationHit* _self = (physx::PxLocationHit*) _address;
    return (jlong) &_self->flags;
}
JNIEXPORT void JNICALL Java_physx_physics_PxLocationHit__1setFlags(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxLocationHit* _self = (physx::PxLocationHit*) _address;
    _self->flags = *((physx::PxHitFlags*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxLocationHit__1getPosition(JNIEnv*, jclass, jlong _address) {
    physx::PxLocationHit* _self = (physx::PxLocationHit*) _address;
    return (jlong) &_self->position;
}
JNIEXPORT void JNICALL Java_physx_physics_PxLocationHit__1setPosition(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxLocationHit* _self = (physx::PxLocationHit*) _address;
    _self->position = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxLocationHit__1getNormal(JNIEnv*, jclass, jlong _address) {
    physx::PxLocationHit* _self = (physx::PxLocationHit*) _address;
    return (jlong) &_self->normal;
}
JNIEXPORT void JNICALL Java_physx_physics_PxLocationHit__1setNormal(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxLocationHit* _self = (physx::PxLocationHit*) _address;
    _self->normal = *((physx::PxVec3*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxLocationHit__1getDistance(JNIEnv*, jclass, jlong _address) {
    physx::PxLocationHit* _self = (physx::PxLocationHit*) _address;
    return (jfloat) _self->distance;
}
JNIEXPORT void JNICALL Java_physx_physics_PxLocationHit__1setDistance(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxLocationHit* _self = (physx::PxLocationHit*) _address;
    _self->distance = value;
}

// PxOverlapBuffer10
JNIEXPORT jint JNICALL Java_physx_physics_PxOverlapBuffer10__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxOverlapBuffer10);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxOverlapBuffer10__1PxOverlapBuffer10(JNIEnv*, jclass) {
    return (jlong) new PxOverlapBuffer10();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxOverlapBuffer10__1getNbAnyHits(JNIEnv*, jclass, jlong _address) {
    PxOverlapBuffer10* self = (PxOverlapBuffer10*) _address;
    return (jint) self->getNbAnyHits();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxOverlapBuffer10__1getAnyHit(JNIEnv*, jclass, jlong _address, jint index) {
    PxOverlapBuffer10* self = (PxOverlapBuffer10*) _address;
    return (jlong) &self->getAnyHit(index);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxOverlapBuffer10__1getNbTouches(JNIEnv*, jclass, jlong _address) {
    PxOverlapBuffer10* self = (PxOverlapBuffer10*) _address;
    return (jint) self->getNbTouches();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxOverlapBuffer10__1getTouches(JNIEnv*, jclass, jlong _address) {
    PxOverlapBuffer10* self = (PxOverlapBuffer10*) _address;
    return (jlong) self->getTouches();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxOverlapBuffer10__1getTouch(JNIEnv*, jclass, jlong _address, jint index) {
    PxOverlapBuffer10* self = (PxOverlapBuffer10*) _address;
    return (jlong) &self->getTouch(index);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxOverlapBuffer10__1getMaxNbTouches(JNIEnv*, jclass, jlong _address) {
    PxOverlapBuffer10* self = (PxOverlapBuffer10*) _address;
    return (jint) self->getMaxNbTouches();
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapBuffer10__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxOverlapBuffer10*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxOverlapBuffer10__1getBlock(JNIEnv*, jclass, jlong _address) {
    PxOverlapBuffer10* _self = (PxOverlapBuffer10*) _address;
    return (jlong) &_self->block;
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapBuffer10__1setBlock(JNIEnv*, jclass, jlong _address, jlong value) {
    PxOverlapBuffer10* _self = (PxOverlapBuffer10*) _address;
    _self->block = *((physx::PxOverlapHit*) value);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxOverlapBuffer10__1getHasBlock(JNIEnv*, jclass, jlong _address) {
    PxOverlapBuffer10* _self = (PxOverlapBuffer10*) _address;
    return (jboolean) _self->hasBlock;
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapBuffer10__1setHasBlock(JNIEnv*, jclass, jlong _address, jboolean value) {
    PxOverlapBuffer10* _self = (PxOverlapBuffer10*) _address;
    _self->hasBlock = value;
}

// PxOverlapResult
JNIEXPORT jint JNICALL Java_physx_physics_PxOverlapResult__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxOverlapResult);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxOverlapResult__1PxOverlapResult(JNIEnv*, jclass) {
    return (jlong) new PxOverlapResult();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxOverlapResult__1getNbAnyHits(JNIEnv*, jclass, jlong _address) {
    PxOverlapResult* self = (PxOverlapResult*) _address;
    return (jint) self->getNbAnyHits();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxOverlapResult__1getAnyHit(JNIEnv*, jclass, jlong _address, jint index) {
    PxOverlapResult* self = (PxOverlapResult*) _address;
    return (jlong) &self->getAnyHit(index);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxOverlapResult__1getNbTouches(JNIEnv*, jclass, jlong _address) {
    PxOverlapResult* self = (PxOverlapResult*) _address;
    return (jint) self->getNbTouches();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxOverlapResult__1getTouch(JNIEnv*, jclass, jlong _address, jint index) {
    PxOverlapResult* self = (PxOverlapResult*) _address;
    return (jlong) &self->getTouch(index);
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapResult__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxOverlapResult*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxOverlapResult__1getBlock(JNIEnv*, jclass, jlong _address) {
    PxOverlapResult* _self = (PxOverlapResult*) _address;
    return (jlong) &_self->block;
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapResult__1setBlock(JNIEnv*, jclass, jlong _address, jlong value) {
    PxOverlapResult* _self = (PxOverlapResult*) _address;
    _self->block = *((physx::PxOverlapHit*) value);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxOverlapResult__1getHasBlock(JNIEnv*, jclass, jlong _address) {
    PxOverlapResult* _self = (PxOverlapResult*) _address;
    return (jboolean) _self->hasBlock;
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapResult__1setHasBlock(JNIEnv*, jclass, jlong _address, jboolean value) {
    PxOverlapResult* _self = (PxOverlapResult*) _address;
    _self->hasBlock = value;
}

// PxOverlapCallback
JNIEXPORT jint JNICALL Java_physx_physics_PxOverlapCallback__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxOverlapCallback);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxOverlapCallback__1hasAnyHits(JNIEnv*, jclass, jlong _address) {
    physx::PxOverlapCallback* self = (physx::PxOverlapCallback*) _address;
    return (jboolean) self->hasAnyHits();
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapCallback__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxOverlapCallback*) _address;
}

// PxOverlapHit
JNIEXPORT jint JNICALL Java_physx_physics_PxOverlapHit__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxOverlapHit);
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapHit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxOverlapHit*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxOverlapHit__1getActor(JNIEnv*, jclass, jlong _address) {
    physx::PxOverlapHit* _self = (physx::PxOverlapHit*) _address;
    return (jlong) _self->actor;
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapHit__1setActor(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxOverlapHit* _self = (physx::PxOverlapHit*) _address;
    _self->actor = (physx::PxRigidActor*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxOverlapHit__1getShape(JNIEnv*, jclass, jlong _address) {
    physx::PxOverlapHit* _self = (physx::PxOverlapHit*) _address;
    return (jlong) _self->shape;
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapHit__1setShape(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxOverlapHit* _self = (physx::PxOverlapHit*) _address;
    _self->shape = (physx::PxShape*) value;
}

// PxQueryFilterCallback
JNIEXPORT jint JNICALL Java_physx_physics_PxQueryFilterCallback__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxQueryFilterCallback);
}
JNIEXPORT void JNICALL Java_physx_physics_PxQueryFilterCallback__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxQueryFilterCallback*) _address;
}

// SimpleQueryFilterCallback
JNIEXPORT jint JNICALL Java_physx_physics_SimpleQueryFilterCallback__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(SimpleQueryFilterCallback);
}
JNIEXPORT jint JNICALL Java_physx_physics_SimpleQueryFilterCallback__1simplePreFilter(JNIEnv*, jclass, jlong _address, jlong filterData, jlong shape, jlong actor, jlong queryFlags) {
    SimpleQueryFilterCallback* self = (SimpleQueryFilterCallback*) _address;
    return (jint) self->simplePreFilter(*((physx::PxFilterData*) filterData), (physx::PxShape*) shape, (physx::PxRigidActor*) actor, *((physx::PxHitFlags*) queryFlags));
}
JNIEXPORT jint JNICALL Java_physx_physics_SimpleQueryFilterCallback__1simplePostFilter(JNIEnv*, jclass, jlong _address, jlong filterData, jlong hit) {
    SimpleQueryFilterCallback* self = (SimpleQueryFilterCallback*) _address;
    return (jint) self->simplePostFilter(*((physx::PxFilterData*) filterData), *((physx::PxQueryHit*) hit));
}
JNIEXPORT void JNICALL Java_physx_physics_SimpleQueryFilterCallback__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (SimpleQueryFilterCallback*) _address;
}

// PxQueryFilterCallbackImpl
JNIEXPORT jint JNICALL Java_physx_physics_PxQueryFilterCallbackImpl__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxQueryFilterCallbackImpl);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxQueryFilterCallbackImpl__1PxQueryFilterCallbackImpl(JNIEnv* env, jobject obj) {
    return (jlong) new PxQueryFilterCallbackImpl(env, obj);
}
JNIEXPORT void JNICALL Java_physx_physics_PxQueryFilterCallbackImpl__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (PxQueryFilterCallbackImpl*) address;
}

// PxQueryFilterData
JNIEXPORT jint JNICALL Java_physx_physics_PxQueryFilterData__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxQueryFilterData);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxQueryFilterData__1_1placement_1new_1PxQueryFilterData__J(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxQueryFilterData();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxQueryFilterData__1_1placement_1new_1PxQueryFilterData__JJJ(JNIEnv*, jclass, jlong _placement_address, jlong fd, jlong f) {
    return (jlong) new((void*)_placement_address) physx::PxQueryFilterData(*((physx::PxFilterData*) fd), *((physx::PxQueryFlags*) f));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxQueryFilterData__1_1placement_1new_1PxQueryFilterData__JJ(JNIEnv*, jclass, jlong _placement_address, jlong f) {
    return (jlong) new((void*)_placement_address) physx::PxQueryFilterData(*((physx::PxQueryFlags*) f));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxQueryFilterData__1PxQueryFilterData__(JNIEnv*, jclass) {
    return (jlong) new physx::PxQueryFilterData();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxQueryFilterData__1PxQueryFilterData__JJ(JNIEnv*, jclass, jlong fd, jlong f) {
    return (jlong) new physx::PxQueryFilterData(*((physx::PxFilterData*) fd), *((physx::PxQueryFlags*) f));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxQueryFilterData__1PxQueryFilterData__J(JNIEnv*, jclass, jlong f) {
    return (jlong) new physx::PxQueryFilterData(*((physx::PxQueryFlags*) f));
}
JNIEXPORT void JNICALL Java_physx_physics_PxQueryFilterData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxQueryFilterData*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxQueryFilterData__1getData(JNIEnv*, jclass, jlong _address) {
    physx::PxQueryFilterData* _self = (physx::PxQueryFilterData*) _address;
    return (jlong) &_self->data;
}
JNIEXPORT void JNICALL Java_physx_physics_PxQueryFilterData__1setData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxQueryFilterData* _self = (physx::PxQueryFilterData*) _address;
    _self->data = *((physx::PxFilterData*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxQueryFilterData__1getFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxQueryFilterData* _self = (physx::PxQueryFilterData*) _address;
    return (jlong) &_self->flags;
}
JNIEXPORT void JNICALL Java_physx_physics_PxQueryFilterData__1setFlags(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxQueryFilterData* _self = (physx::PxQueryFilterData*) _address;
    _self->flags = *((physx::PxQueryFlags*) value);
}

// PxQueryFlags
JNIEXPORT jint JNICALL Java_physx_physics_PxQueryFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxQueryFlags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxQueryFlags__1_1placement_1new_1PxQueryFlags(JNIEnv*, jclass, jlong _placement_address, jshort flags) {
    return (jlong) new((void*)_placement_address) physx::PxQueryFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxQueryFlags__1PxQueryFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxQueryFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxQueryFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxQueryFlags* self = (physx::PxQueryFlags*) _address;
    return (jboolean) self->isSet((PxQueryFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxQueryFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxQueryFlags* self = (physx::PxQueryFlags*) _address;
    self->raise((PxQueryFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxQueryFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxQueryFlags* self = (physx::PxQueryFlags*) _address;
    self->clear((PxQueryFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxQueryFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxQueryFlags*) _address;
}

// PxQueryHit
JNIEXPORT jint JNICALL Java_physx_physics_PxQueryHit__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxQueryHit);
}
JNIEXPORT void JNICALL Java_physx_physics_PxQueryHit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxQueryHit*) _address;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxQueryHit__1getFaceIndex(JNIEnv*, jclass, jlong _address) {
    physx::PxQueryHit* _self = (physx::PxQueryHit*) _address;
    return (jint) _self->faceIndex;
}
JNIEXPORT void JNICALL Java_physx_physics_PxQueryHit__1setFaceIndex(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxQueryHit* _self = (physx::PxQueryHit*) _address;
    _self->faceIndex = value;
}

// PxRaycastBuffer10
JNIEXPORT jint JNICALL Java_physx_physics_PxRaycastBuffer10__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxRaycastBuffer10);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastBuffer10__1PxRaycastBuffer10(JNIEnv*, jclass) {
    return (jlong) new PxRaycastBuffer10();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRaycastBuffer10__1getNbAnyHits(JNIEnv*, jclass, jlong _address) {
    PxRaycastBuffer10* self = (PxRaycastBuffer10*) _address;
    return (jint) self->getNbAnyHits();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastBuffer10__1getAnyHit(JNIEnv*, jclass, jlong _address, jint index) {
    PxRaycastBuffer10* self = (PxRaycastBuffer10*) _address;
    return (jlong) &self->getAnyHit(index);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRaycastBuffer10__1getNbTouches(JNIEnv*, jclass, jlong _address) {
    PxRaycastBuffer10* self = (PxRaycastBuffer10*) _address;
    return (jint) self->getNbTouches();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastBuffer10__1getTouches(JNIEnv*, jclass, jlong _address) {
    PxRaycastBuffer10* self = (PxRaycastBuffer10*) _address;
    return (jlong) self->getTouches();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastBuffer10__1getTouch(JNIEnv*, jclass, jlong _address, jint index) {
    PxRaycastBuffer10* self = (PxRaycastBuffer10*) _address;
    return (jlong) &self->getTouch(index);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRaycastBuffer10__1getMaxNbTouches(JNIEnv*, jclass, jlong _address) {
    PxRaycastBuffer10* self = (PxRaycastBuffer10*) _address;
    return (jint) self->getMaxNbTouches();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastBuffer10__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxRaycastBuffer10*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastBuffer10__1getBlock(JNIEnv*, jclass, jlong _address) {
    PxRaycastBuffer10* _self = (PxRaycastBuffer10*) _address;
    return (jlong) &_self->block;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastBuffer10__1setBlock(JNIEnv*, jclass, jlong _address, jlong value) {
    PxRaycastBuffer10* _self = (PxRaycastBuffer10*) _address;
    _self->block = *((physx::PxRaycastHit*) value);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxRaycastBuffer10__1getHasBlock(JNIEnv*, jclass, jlong _address) {
    PxRaycastBuffer10* _self = (PxRaycastBuffer10*) _address;
    return (jboolean) _self->hasBlock;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastBuffer10__1setHasBlock(JNIEnv*, jclass, jlong _address, jboolean value) {
    PxRaycastBuffer10* _self = (PxRaycastBuffer10*) _address;
    _self->hasBlock = value;
}

// PxRaycastResult
JNIEXPORT jint JNICALL Java_physx_physics_PxRaycastResult__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxRaycastResult);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastResult__1PxRaycastResult(JNIEnv*, jclass) {
    return (jlong) new PxRaycastResult();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRaycastResult__1getNbAnyHits(JNIEnv*, jclass, jlong _address) {
    PxRaycastResult* self = (PxRaycastResult*) _address;
    return (jint) self->getNbAnyHits();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastResult__1getAnyHit(JNIEnv*, jclass, jlong _address, jint index) {
    PxRaycastResult* self = (PxRaycastResult*) _address;
    return (jlong) &self->getAnyHit(index);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRaycastResult__1getNbTouches(JNIEnv*, jclass, jlong _address) {
    PxRaycastResult* self = (PxRaycastResult*) _address;
    return (jint) self->getNbTouches();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastResult__1getTouch(JNIEnv*, jclass, jlong _address, jint index) {
    PxRaycastResult* self = (PxRaycastResult*) _address;
    return (jlong) &self->getTouch(index);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastResult__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxRaycastResult*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastResult__1getBlock(JNIEnv*, jclass, jlong _address) {
    PxRaycastResult* _self = (PxRaycastResult*) _address;
    return (jlong) &_self->block;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastResult__1setBlock(JNIEnv*, jclass, jlong _address, jlong value) {
    PxRaycastResult* _self = (PxRaycastResult*) _address;
    _self->block = *((physx::PxRaycastHit*) value);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxRaycastResult__1getHasBlock(JNIEnv*, jclass, jlong _address) {
    PxRaycastResult* _self = (PxRaycastResult*) _address;
    return (jboolean) _self->hasBlock;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastResult__1setHasBlock(JNIEnv*, jclass, jlong _address, jboolean value) {
    PxRaycastResult* _self = (PxRaycastResult*) _address;
    _self->hasBlock = value;
}

// PxRaycastCallback
JNIEXPORT jint JNICALL Java_physx_physics_PxRaycastCallback__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxRaycastCallback);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxRaycastCallback__1hasAnyHits(JNIEnv*, jclass, jlong _address) {
    physx::PxRaycastCallback* self = (physx::PxRaycastCallback*) _address;
    return (jboolean) self->hasAnyHits();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastCallback__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxRaycastCallback*) _address;
}

// PxRaycastHit
JNIEXPORT jint JNICALL Java_physx_physics_PxRaycastHit__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxRaycastHit);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastHit__1_1placement_1new_1PxRaycastHit(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxRaycastHit();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastHit__1PxRaycastHit(JNIEnv*, jclass) {
    return (jlong) new physx::PxRaycastHit();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastHit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxRaycastHit*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastHit__1getActor(JNIEnv*, jclass, jlong _address) {
    physx::PxRaycastHit* _self = (physx::PxRaycastHit*) _address;
    return (jlong) _self->actor;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastHit__1setActor(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxRaycastHit* _self = (physx::PxRaycastHit*) _address;
    _self->actor = (physx::PxRigidActor*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastHit__1getShape(JNIEnv*, jclass, jlong _address) {
    physx::PxRaycastHit* _self = (physx::PxRaycastHit*) _address;
    return (jlong) _self->shape;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastHit__1setShape(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxRaycastHit* _self = (physx::PxRaycastHit*) _address;
    _self->shape = (physx::PxShape*) value;
}

// PxSceneQuerySystemBase
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneQuerySystemBase__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxSceneQuerySystemBase);
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneQuerySystemBase__1setDynamicTreeRebuildRateHint(JNIEnv*, jclass, jlong _address, jint dynamicTreeRebuildRateHint) {
    physx::PxSceneQuerySystemBase* self = (physx::PxSceneQuerySystemBase*) _address;
    self->setDynamicTreeRebuildRateHint(dynamicTreeRebuildRateHint);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneQuerySystemBase__1getDynamicTreeRebuildRateHint(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneQuerySystemBase* self = (physx::PxSceneQuerySystemBase*) _address;
    return (jint) self->getDynamicTreeRebuildRateHint();
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneQuerySystemBase__1forceRebuildDynamicTree(JNIEnv*, jclass, jlong _address, jint prunerIndex) {
    physx::PxSceneQuerySystemBase* self = (physx::PxSceneQuerySystemBase*) _address;
    self->forceRebuildDynamicTree(prunerIndex);
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneQuerySystemBase__1setUpdateMode(JNIEnv*, jclass, jlong _address, jint updateMode) {
    physx::PxSceneQuerySystemBase* self = (physx::PxSceneQuerySystemBase*) _address;
    self->setUpdateMode((PxSceneQueryUpdateModeEnum) updateMode);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneQuerySystemBase__1getUpdateMode(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneQuerySystemBase* self = (physx::PxSceneQuerySystemBase*) _address;
    return (jint) self->getUpdateMode();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneQuerySystemBase__1getStaticTimestamp(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneQuerySystemBase* self = (physx::PxSceneQuerySystemBase*) _address;
    return (jint) self->getStaticTimestamp();
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneQuerySystemBase__1flushUpdates(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneQuerySystemBase* self = (physx::PxSceneQuerySystemBase*) _address;
    self->flushUpdates();
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxSceneQuerySystemBase__1raycast__JJJFJ(JNIEnv*, jclass, jlong _address, jlong origin, jlong unitDir, jfloat distance, jlong hitCall) {
    physx::PxSceneQuerySystemBase* self = (physx::PxSceneQuerySystemBase*) _address;
    return (jboolean) self->raycast(*((physx::PxVec3*) origin), *((physx::PxVec3*) unitDir), distance, *((physx::PxRaycastCallback*) hitCall));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxSceneQuerySystemBase__1raycast__JJJFJJ(JNIEnv*, jclass, jlong _address, jlong origin, jlong unitDir, jfloat distance, jlong hitCall, jlong hitFlags) {
    physx::PxSceneQuerySystemBase* self = (physx::PxSceneQuerySystemBase*) _address;
    return (jboolean) self->raycast(*((physx::PxVec3*) origin), *((physx::PxVec3*) unitDir), distance, *((physx::PxRaycastCallback*) hitCall), *((physx::PxHitFlags*) hitFlags));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxSceneQuerySystemBase__1raycast__JJJFJJJ(JNIEnv*, jclass, jlong _address, jlong origin, jlong unitDir, jfloat distance, jlong hitCall, jlong hitFlags, jlong filterData) {
    physx::PxSceneQuerySystemBase* self = (physx::PxSceneQuerySystemBase*) _address;
    return (jboolean) self->raycast(*((physx::PxVec3*) origin), *((physx::PxVec3*) unitDir), distance, *((physx::PxRaycastCallback*) hitCall), *((physx::PxHitFlags*) hitFlags), *((physx::PxQueryFilterData*) filterData));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxSceneQuerySystemBase__1sweep__JJJJFJ(JNIEnv*, jclass, jlong _address, jlong geometry, jlong pose, jlong unitDir, jfloat distance, jlong hitCall) {
    physx::PxSceneQuerySystemBase* self = (physx::PxSceneQuerySystemBase*) _address;
    return (jboolean) self->sweep(*((physx::PxGeometry*) geometry), *((physx::PxTransform*) pose), *((physx::PxVec3*) unitDir), distance, *((physx::PxSweepCallback*) hitCall));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxSceneQuerySystemBase__1sweep__JJJJFJJ(JNIEnv*, jclass, jlong _address, jlong geometry, jlong pose, jlong unitDir, jfloat distance, jlong hitCall, jlong hitFlags) {
    physx::PxSceneQuerySystemBase* self = (physx::PxSceneQuerySystemBase*) _address;
    return (jboolean) self->sweep(*((physx::PxGeometry*) geometry), *((physx::PxTransform*) pose), *((physx::PxVec3*) unitDir), distance, *((physx::PxSweepCallback*) hitCall), *((physx::PxHitFlags*) hitFlags));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxSceneQuerySystemBase__1sweep__JJJJFJJJ(JNIEnv*, jclass, jlong _address, jlong geometry, jlong pose, jlong unitDir, jfloat distance, jlong hitCall, jlong hitFlags, jlong filterData) {
    physx::PxSceneQuerySystemBase* self = (physx::PxSceneQuerySystemBase*) _address;
    return (jboolean) self->sweep(*((physx::PxGeometry*) geometry), *((physx::PxTransform*) pose), *((physx::PxVec3*) unitDir), distance, *((physx::PxSweepCallback*) hitCall), *((physx::PxHitFlags*) hitFlags), *((physx::PxQueryFilterData*) filterData));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxSceneQuerySystemBase__1overlap__JJJJ(JNIEnv*, jclass, jlong _address, jlong geometry, jlong pose, jlong hitCall) {
    physx::PxSceneQuerySystemBase* self = (physx::PxSceneQuerySystemBase*) _address;
    return (jboolean) self->overlap(*((physx::PxGeometry*) geometry), *((physx::PxTransform*) pose), *((physx::PxOverlapCallback*) hitCall));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxSceneQuerySystemBase__1overlap__JJJJJ(JNIEnv*, jclass, jlong _address, jlong geometry, jlong pose, jlong hitCall, jlong filterData) {
    physx::PxSceneQuerySystemBase* self = (physx::PxSceneQuerySystemBase*) _address;
    return (jboolean) self->overlap(*((physx::PxGeometry*) geometry), *((physx::PxTransform*) pose), *((physx::PxOverlapCallback*) hitCall), *((physx::PxQueryFilterData*) filterData));
}

// PxSceneSQSystem
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneSQSystem__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxSceneSQSystem);
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneSQSystem__1setSceneQueryUpdateMode(JNIEnv*, jclass, jlong _address, jint updateMode) {
    physx::PxSceneSQSystem* self = (physx::PxSceneSQSystem*) _address;
    self->setSceneQueryUpdateMode((PxSceneQueryUpdateModeEnum) updateMode);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneSQSystem__1getSceneQueryUpdateMode(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneSQSystem* self = (physx::PxSceneSQSystem*) _address;
    return (jint) self->getSceneQueryUpdateMode();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneSQSystem__1getSceneQueryStaticTimestamp(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneSQSystem* self = (physx::PxSceneSQSystem*) _address;
    return (jint) self->getSceneQueryStaticTimestamp();
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneSQSystem__1flushQueryUpdates(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneSQSystem* self = (physx::PxSceneSQSystem*) _address;
    self->flushQueryUpdates();
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneSQSystem__1forceDynamicTreeRebuild(JNIEnv*, jclass, jlong _address, jboolean rebuildStaticStructure, jboolean rebuildDynamicStructure) {
    physx::PxSceneSQSystem* self = (physx::PxSceneSQSystem*) _address;
    self->forceDynamicTreeRebuild(rebuildStaticStructure, rebuildDynamicStructure);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneSQSystem__1getStaticStructure(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneSQSystem* self = (physx::PxSceneSQSystem*) _address;
    return (jint) self->getStaticStructure();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneSQSystem__1getDynamicStructure(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneSQSystem* self = (physx::PxSceneSQSystem*) _address;
    return (jint) self->getDynamicStructure();
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneSQSystem__1sceneQueriesUpdate__J(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneSQSystem* self = (physx::PxSceneSQSystem*) _address;
    self->sceneQueriesUpdate();
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneSQSystem__1sceneQueriesUpdate__JJ(JNIEnv*, jclass, jlong _address, jlong completionTask) {
    physx::PxSceneSQSystem* self = (physx::PxSceneSQSystem*) _address;
    self->sceneQueriesUpdate((physx::PxBaseTask*) completionTask);
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneSQSystem__1sceneQueriesUpdate__JJZ(JNIEnv*, jclass, jlong _address, jlong completionTask, jboolean controlSimulation) {
    physx::PxSceneSQSystem* self = (physx::PxSceneSQSystem*) _address;
    self->sceneQueriesUpdate((physx::PxBaseTask*) completionTask, controlSimulation);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxSceneSQSystem__1checkQueries__J(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneSQSystem* self = (physx::PxSceneSQSystem*) _address;
    return (jboolean) self->checkQueries();
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxSceneSQSystem__1checkQueries__JZ(JNIEnv*, jclass, jlong _address, jboolean block) {
    physx::PxSceneSQSystem* self = (physx::PxSceneSQSystem*) _address;
    return (jboolean) self->checkQueries(block);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxSceneSQSystem__1fetchQueries__J(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneSQSystem* self = (physx::PxSceneSQSystem*) _address;
    return (jboolean) self->fetchQueries();
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxSceneSQSystem__1fetchQueries__JZ(JNIEnv*, jclass, jlong _address, jboolean block) {
    physx::PxSceneSQSystem* self = (physx::PxSceneSQSystem*) _address;
    return (jboolean) self->fetchQueries(block);
}

// PxSweepBuffer10
JNIEXPORT jint JNICALL Java_physx_physics_PxSweepBuffer10__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxSweepBuffer10);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSweepBuffer10__1PxSweepBuffer10(JNIEnv*, jclass) {
    return (jlong) new PxSweepBuffer10();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSweepBuffer10__1getNbAnyHits(JNIEnv*, jclass, jlong _address) {
    PxSweepBuffer10* self = (PxSweepBuffer10*) _address;
    return (jint) self->getNbAnyHits();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSweepBuffer10__1getAnyHit(JNIEnv*, jclass, jlong _address, jint index) {
    PxSweepBuffer10* self = (PxSweepBuffer10*) _address;
    return (jlong) &self->getAnyHit(index);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSweepBuffer10__1getNbTouches(JNIEnv*, jclass, jlong _address) {
    PxSweepBuffer10* self = (PxSweepBuffer10*) _address;
    return (jint) self->getNbTouches();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSweepBuffer10__1getTouches(JNIEnv*, jclass, jlong _address) {
    PxSweepBuffer10* self = (PxSweepBuffer10*) _address;
    return (jlong) self->getTouches();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSweepBuffer10__1getTouch(JNIEnv*, jclass, jlong _address, jint index) {
    PxSweepBuffer10* self = (PxSweepBuffer10*) _address;
    return (jlong) &self->getTouch(index);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSweepBuffer10__1getMaxNbTouches(JNIEnv*, jclass, jlong _address) {
    PxSweepBuffer10* self = (PxSweepBuffer10*) _address;
    return (jint) self->getMaxNbTouches();
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepBuffer10__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxSweepBuffer10*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSweepBuffer10__1getBlock(JNIEnv*, jclass, jlong _address) {
    PxSweepBuffer10* _self = (PxSweepBuffer10*) _address;
    return (jlong) &_self->block;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepBuffer10__1setBlock(JNIEnv*, jclass, jlong _address, jlong value) {
    PxSweepBuffer10* _self = (PxSweepBuffer10*) _address;
    _self->block = *((physx::PxSweepHit*) value);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxSweepBuffer10__1getHasBlock(JNIEnv*, jclass, jlong _address) {
    PxSweepBuffer10* _self = (PxSweepBuffer10*) _address;
    return (jboolean) _self->hasBlock;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepBuffer10__1setHasBlock(JNIEnv*, jclass, jlong _address, jboolean value) {
    PxSweepBuffer10* _self = (PxSweepBuffer10*) _address;
    _self->hasBlock = value;
}

// PxSweepResult
JNIEXPORT jint JNICALL Java_physx_physics_PxSweepResult__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxSweepResult);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSweepResult__1PxSweepResult(JNIEnv*, jclass) {
    return (jlong) new PxSweepResult();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSweepResult__1getNbAnyHits(JNIEnv*, jclass, jlong _address) {
    PxSweepResult* self = (PxSweepResult*) _address;
    return (jint) self->getNbAnyHits();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSweepResult__1getAnyHit(JNIEnv*, jclass, jlong _address, jint index) {
    PxSweepResult* self = (PxSweepResult*) _address;
    return (jlong) &self->getAnyHit(index);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSweepResult__1getNbTouches(JNIEnv*, jclass, jlong _address) {
    PxSweepResult* self = (PxSweepResult*) _address;
    return (jint) self->getNbTouches();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSweepResult__1getTouch(JNIEnv*, jclass, jlong _address, jint index) {
    PxSweepResult* self = (PxSweepResult*) _address;
    return (jlong) &self->getTouch(index);
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepResult__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxSweepResult*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSweepResult__1getBlock(JNIEnv*, jclass, jlong _address) {
    PxSweepResult* _self = (PxSweepResult*) _address;
    return (jlong) &_self->block;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepResult__1setBlock(JNIEnv*, jclass, jlong _address, jlong value) {
    PxSweepResult* _self = (PxSweepResult*) _address;
    _self->block = *((physx::PxSweepHit*) value);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxSweepResult__1getHasBlock(JNIEnv*, jclass, jlong _address) {
    PxSweepResult* _self = (PxSweepResult*) _address;
    return (jboolean) _self->hasBlock;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepResult__1setHasBlock(JNIEnv*, jclass, jlong _address, jboolean value) {
    PxSweepResult* _self = (PxSweepResult*) _address;
    _self->hasBlock = value;
}

// PxSweepCallback
JNIEXPORT jint JNICALL Java_physx_physics_PxSweepCallback__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxSweepCallback);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxSweepCallback__1hasAnyHits(JNIEnv*, jclass, jlong _address) {
    physx::PxSweepCallback* self = (physx::PxSweepCallback*) _address;
    return (jboolean) self->hasAnyHits();
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepCallback__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSweepCallback*) _address;
}

// PxSweepHit
JNIEXPORT jint JNICALL Java_physx_physics_PxSweepHit__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxSweepHit);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSweepHit__1_1placement_1new_1PxSweepHit(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxSweepHit();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSweepHit__1PxSweepHit(JNIEnv*, jclass) {
    return (jlong) new physx::PxSweepHit();
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepHit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSweepHit*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSweepHit__1getActor(JNIEnv*, jclass, jlong _address) {
    physx::PxSweepHit* _self = (physx::PxSweepHit*) _address;
    return (jlong) _self->actor;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepHit__1setActor(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSweepHit* _self = (physx::PxSweepHit*) _address;
    _self->actor = (physx::PxRigidActor*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSweepHit__1getShape(JNIEnv*, jclass, jlong _address) {
    physx::PxSweepHit* _self = (physx::PxSweepHit*) _address;
    return (jlong) _self->shape;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepHit__1setShape(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSweepHit* _self = (physx::PxSweepHit*) _address;
    _self->shape = (physx::PxShape*) value;
}

// PxShape
JNIEXPORT jint JNICALL Java_physx_physics_PxShape__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxShape);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxShape__1getGeometryType(JNIEnv*, jclass, jlong _address) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jint) self->getGeometryType();
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setGeometry(JNIEnv*, jclass, jlong _address, jlong geometry) {
    physx::PxShape* self = (physx::PxShape*) _address;
    self->setGeometry(*((physx::PxGeometry*) geometry));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxShape__1getGeometry(JNIEnv*, jclass, jlong _address) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jlong) &self->getGeometry();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxShape__1getActor(JNIEnv*, jclass, jlong _address) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jlong) self->getActor();
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setMaterials(JNIEnv*, jclass, jlong _address, jlong materials, jshort materialCount) {
    physx::PxShape* self = (physx::PxShape*) _address;
    self->setMaterials((PxMaterialPtr*) materials, materialCount);
}
JNIEXPORT jshort JNICALL Java_physx_physics_PxShape__1getNbMaterials(JNIEnv*, jclass, jlong _address) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jshort) self->getNbMaterials();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxShape__1getMaterials(JNIEnv*, jclass, jlong _address, jlong userBuffer, jint bufferSize, jint startIndex) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jint) self->getMaterials((PxMaterialPtr*) userBuffer, bufferSize, startIndex);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxShape__1getMaterialFromInternalFaceIndex(JNIEnv*, jclass, jlong _address, jint faceIndex) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jlong) self->getMaterialFromInternalFaceIndex(faceIndex);
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setContactOffset(JNIEnv*, jclass, jlong _address, jfloat contactOffset) {
    physx::PxShape* self = (physx::PxShape*) _address;
    self->setContactOffset(contactOffset);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxShape__1getContactOffset(JNIEnv*, jclass, jlong _address) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jfloat) self->getContactOffset();
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setRestOffset(JNIEnv*, jclass, jlong _address, jfloat restOffset) {
    physx::PxShape* self = (physx::PxShape*) _address;
    self->setRestOffset(restOffset);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxShape__1getRestOffset(JNIEnv*, jclass, jlong _address) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jfloat) self->getRestOffset();
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setTorsionalPatchRadius(JNIEnv*, jclass, jlong _address, jfloat radius) {
    physx::PxShape* self = (physx::PxShape*) _address;
    self->setTorsionalPatchRadius(radius);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxShape__1getTorsionalPatchRadius(JNIEnv*, jclass, jlong _address) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jfloat) self->getTorsionalPatchRadius();
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setMinTorsionalPatchRadius(JNIEnv*, jclass, jlong _address, jfloat radius) {
    physx::PxShape* self = (physx::PxShape*) _address;
    self->setMinTorsionalPatchRadius(radius);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxShape__1getMinTorsionalPatchRadius(JNIEnv*, jclass, jlong _address) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jfloat) self->getMinTorsionalPatchRadius();
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setFlag(JNIEnv*, jclass, jlong _address, jint flag, jboolean value) {
    physx::PxShape* self = (physx::PxShape*) _address;
    self->setFlag((PxShapeFlagEnum) flag, value);
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setFlags(JNIEnv*, jclass, jlong _address, jlong inFlags) {
    physx::PxShape* self = (physx::PxShape*) _address;
    self->setFlags(*((physx::PxShapeFlags*) inFlags));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxShape__1getFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxShape* self = (physx::PxShape*) _address;
    static thread_local physx::PxShapeFlags _cache = self->getFlags();
    _cache = self->getFlags();
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxShape__1isExclusive(JNIEnv*, jclass, jlong _address) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jboolean) self->isExclusive();
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setName(JNIEnv* _env, jclass, jlong _address, jstring name) {
    physx::PxShape* self = (physx::PxShape*) _address;
    self->setName(_env->GetStringUTFChars(name, 0));
}
JNIEXPORT jstring JNICALL Java_physx_physics_PxShape__1getName(JNIEnv* _env, jclass, jlong _address) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return _env->NewStringUTF(self->getName());
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setLocalPose(JNIEnv*, jclass, jlong _address, jlong pose) {
    physx::PxShape* self = (physx::PxShape*) _address;
    self->setLocalPose(*((physx::PxTransform*) pose));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxShape__1getLocalPose(JNIEnv*, jclass, jlong _address) {
    physx::PxShape* self = (physx::PxShape*) _address;
    static thread_local physx::PxTransform _cache = self->getLocalPose();
    _cache = self->getLocalPose();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setSimulationFilterData(JNIEnv*, jclass, jlong _address, jlong data) {
    physx::PxShape* self = (physx::PxShape*) _address;
    self->setSimulationFilterData(*((physx::PxFilterData*) data));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxShape__1getSimulationFilterData(JNIEnv*, jclass, jlong _address) {
    physx::PxShape* self = (physx::PxShape*) _address;
    static thread_local physx::PxFilterData _cache = self->getSimulationFilterData();
    _cache = self->getSimulationFilterData();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setQueryFilterData(JNIEnv*, jclass, jlong _address, jlong data) {
    physx::PxShape* self = (physx::PxShape*) _address;
    self->setQueryFilterData(*((physx::PxFilterData*) data));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxShape__1getQueryFilterData(JNIEnv*, jclass, jlong _address) {
    physx::PxShape* self = (physx::PxShape*) _address;
    static thread_local physx::PxFilterData _cache = self->getQueryFilterData();
    _cache = self->getQueryFilterData();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxShape__1getUserData(JNIEnv*, jclass, jlong _address) {
    physx::PxShape* _self = (physx::PxShape*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxShape* _self = (physx::PxShape*) _address;
    _self->userData = (void*) value;
}

// PxShapeExt
JNIEXPORT jint JNICALL Java_physx_physics_PxShapeExt__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxShapeExt);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxShapeExt__1getGlobalPose(JNIEnv*, jclass, jlong shape, jlong actor) {
    static thread_local physx::PxTransform _cache = physx::PxShapeExt::getGlobalPose(*((physx::PxShape*) shape), *((physx::PxRigidActor*) actor));
    _cache = physx::PxShapeExt::getGlobalPose(*((physx::PxShape*) shape), *((physx::PxRigidActor*) actor));
    return (jlong) &_cache;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxShapeExt__1raycast(JNIEnv*, jclass, jlong shape, jlong actor, jlong rayOrigin, jlong rayDir, jfloat maxDist, jlong hitFlags, jint maxHits, jlong rayHits) {
    return (jint) physx::PxShapeExt::raycast(*((physx::PxShape*) shape), *((physx::PxRigidActor*) actor), *((physx::PxVec3*) rayOrigin), *((physx::PxVec3*) rayDir), maxDist, *((physx::PxHitFlags*) hitFlags), maxHits, (physx::PxRaycastHit*) rayHits);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxShapeExt__1overlap(JNIEnv*, jclass, jlong shape, jlong actor, jlong otherGeom, jlong otherGeomPose) {
    return (jboolean) physx::PxShapeExt::overlap(*((physx::PxShape*) shape), *((physx::PxRigidActor*) actor), *((physx::PxGeometry*) otherGeom), *((physx::PxTransform*) otherGeomPose));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxShapeExt__1sweep(JNIEnv*, jclass, jlong shape, jlong actor, jlong unitDir, jfloat distance, jlong otherGeom, jlong otherGeomPose, jlong sweepHit, jlong hitFlags) {
    return (jboolean) physx::PxShapeExt::sweep(*((physx::PxShape*) shape), *((physx::PxRigidActor*) actor), *((physx::PxVec3*) unitDir), distance, *((physx::PxGeometry*) otherGeom), *((physx::PxTransform*) otherGeomPose), *((physx::PxSweepHit*) sweepHit), *((physx::PxHitFlags*) hitFlags));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxShapeExt__1getWorldBounds__JJ(JNIEnv*, jclass, jlong shape, jlong actor) {
    static thread_local physx::PxBounds3 _cache = physx::PxShapeExt::getWorldBounds(*((physx::PxShape*) shape), *((physx::PxRigidActor*) actor));
    _cache = physx::PxShapeExt::getWorldBounds(*((physx::PxShape*) shape), *((physx::PxRigidActor*) actor));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxShapeExt__1getWorldBounds__JJF(JNIEnv*, jclass, jlong shape, jlong actor, jfloat inflation) {
    static thread_local physx::PxBounds3 _cache = physx::PxShapeExt::getWorldBounds(*((physx::PxShape*) shape), *((physx::PxRigidActor*) actor), inflation);
    _cache = physx::PxShapeExt::getWorldBounds(*((physx::PxShape*) shape), *((physx::PxRigidActor*) actor), inflation);
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxShapeExt__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxShapeExt*) _address;
}

// PxShapeFlags
JNIEXPORT jint JNICALL Java_physx_physics_PxShapeFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxShapeFlags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxShapeFlags__1_1placement_1new_1PxShapeFlags(JNIEnv*, jclass, jlong _placement_address, jbyte flags) {
    return (jlong) new((void*)_placement_address) physx::PxShapeFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxShapeFlags__1PxShapeFlags(JNIEnv*, jclass, jbyte flags) {
    return (jlong) new physx::PxShapeFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxShapeFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxShapeFlags* self = (physx::PxShapeFlags*) _address;
    return (jboolean) self->isSet((PxShapeFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxShapeFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxShapeFlags* self = (physx::PxShapeFlags*) _address;
    self->raise((PxShapeFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxShapeFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxShapeFlags* self = (physx::PxShapeFlags*) _address;
    self->clear((PxShapeFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxShapeFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxShapeFlags*) _address;
}

// PxActorFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxActorFlagEnum__1geteVISUALIZATION(JNIEnv*, jclass) {
    return PxActorFlagEnum::eVISUALIZATION;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxActorFlagEnum__1geteDISABLE_1GRAVITY(JNIEnv*, jclass) {
    return PxActorFlagEnum::eDISABLE_GRAVITY;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxActorFlagEnum__1geteSEND_1SLEEP_1NOTIFIES(JNIEnv*, jclass) {
    return PxActorFlagEnum::eSEND_SLEEP_NOTIFIES;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxActorFlagEnum__1geteDISABLE_1SIMULATION(JNIEnv*, jclass) {
    return PxActorFlagEnum::eDISABLE_SIMULATION;
}

// PxActorTypeEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxActorTypeEnum__1geteRIGID_1STATIC(JNIEnv*, jclass) {
    return PxActorTypeEnum::eRIGID_STATIC;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxActorTypeEnum__1geteRIGID_1DYNAMIC(JNIEnv*, jclass) {
    return PxActorTypeEnum::eRIGID_DYNAMIC;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxActorTypeEnum__1geteARTICULATION_1LINK(JNIEnv*, jclass) {
    return PxActorTypeEnum::eARTICULATION_LINK;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxActorTypeEnum__1geteSOFTBODY(JNIEnv*, jclass) {
    return PxActorTypeEnum::eSOFTBODY;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxActorTypeEnum__1geteFEMCLOTH(JNIEnv*, jclass) {
    return PxActorTypeEnum::eFEMCLOTH;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxActorTypeEnum__1getePBD_1PARTICLESYSTEM(JNIEnv*, jclass) {
    return PxActorTypeEnum::ePBD_PARTICLESYSTEM;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxActorTypeEnum__1geteFLIP_1PARTICLESYSTEM(JNIEnv*, jclass) {
    return PxActorTypeEnum::eFLIP_PARTICLESYSTEM;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxActorTypeEnum__1geteMPM_1PARTICLESYSTEM(JNIEnv*, jclass) {
    return PxActorTypeEnum::eMPM_PARTICLESYSTEM;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxActorTypeEnum__1geteCUSTOM_1PARTICLESYSTEM(JNIEnv*, jclass) {
    return PxActorTypeEnum::eCUSTOM_PARTICLESYSTEM;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxActorTypeEnum__1geteHAIRSYSTEM(JNIEnv*, jclass) {
    return PxActorTypeEnum::eHAIRSYSTEM;
}

// PxActorTypeFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxActorTypeFlagEnum__1geteRIGID_1STATIC(JNIEnv*, jclass) {
    return PxActorTypeFlagEnum::eRIGID_STATIC;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxActorTypeFlagEnum__1geteRIGID_1DYNAMIC(JNIEnv*, jclass) {
    return PxActorTypeFlagEnum::eRIGID_DYNAMIC;
}

// PxRigidBodyFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidBodyFlagEnum__1geteKINEMATIC(JNIEnv*, jclass) {
    return PxRigidBodyFlagEnum::eKINEMATIC;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidBodyFlagEnum__1geteUSE_1KINEMATIC_1TARGET_1FOR_1SCENE_1QUERIES(JNIEnv*, jclass) {
    return PxRigidBodyFlagEnum::eUSE_KINEMATIC_TARGET_FOR_SCENE_QUERIES;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidBodyFlagEnum__1geteENABLE_1CCD(JNIEnv*, jclass) {
    return PxRigidBodyFlagEnum::eENABLE_CCD;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidBodyFlagEnum__1geteENABLE_1CCD_1FRICTION(JNIEnv*, jclass) {
    return PxRigidBodyFlagEnum::eENABLE_CCD_FRICTION;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidBodyFlagEnum__1geteENABLE_1POSE_1INTEGRATION_1PREVIEW(JNIEnv*, jclass) {
    return PxRigidBodyFlagEnum::eENABLE_POSE_INTEGRATION_PREVIEW;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidBodyFlagEnum__1geteENABLE_1SPECULATIVE_1CCD(JNIEnv*, jclass) {
    return PxRigidBodyFlagEnum::eENABLE_SPECULATIVE_CCD;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidBodyFlagEnum__1geteENABLE_1CCD_1MAX_1CONTACT_1IMPULSE(JNIEnv*, jclass) {
    return PxRigidBodyFlagEnum::eENABLE_CCD_MAX_CONTACT_IMPULSE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidBodyFlagEnum__1geteRETAIN_1ACCELERATIONS(JNIEnv*, jclass) {
    return PxRigidBodyFlagEnum::eRETAIN_ACCELERATIONS;
}

// PxRigidDynamicLockFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidDynamicLockFlagEnum__1geteLOCK_1LINEAR_1X(JNIEnv*, jclass) {
    return PxRigidDynamicLockFlagEnum::eLOCK_LINEAR_X;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidDynamicLockFlagEnum__1geteLOCK_1LINEAR_1Y(JNIEnv*, jclass) {
    return PxRigidDynamicLockFlagEnum::eLOCK_LINEAR_Y;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidDynamicLockFlagEnum__1geteLOCK_1LINEAR_1Z(JNIEnv*, jclass) {
    return PxRigidDynamicLockFlagEnum::eLOCK_LINEAR_Z;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidDynamicLockFlagEnum__1geteLOCK_1ANGULAR_1X(JNIEnv*, jclass) {
    return PxRigidDynamicLockFlagEnum::eLOCK_ANGULAR_X;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidDynamicLockFlagEnum__1geteLOCK_1ANGULAR_1Y(JNIEnv*, jclass) {
    return PxRigidDynamicLockFlagEnum::eLOCK_ANGULAR_Y;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidDynamicLockFlagEnum__1geteLOCK_1ANGULAR_1Z(JNIEnv*, jclass) {
    return PxRigidDynamicLockFlagEnum::eLOCK_ANGULAR_Z;
}

// PxArticulationAxisEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationAxisEnum__1geteTWIST(JNIEnv*, jclass) {
    return PxArticulationAxisEnum::eTWIST;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationAxisEnum__1geteSWING1(JNIEnv*, jclass) {
    return PxArticulationAxisEnum::eSWING1;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationAxisEnum__1geteSWING2(JNIEnv*, jclass) {
    return PxArticulationAxisEnum::eSWING2;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationAxisEnum__1geteX(JNIEnv*, jclass) {
    return PxArticulationAxisEnum::eX;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationAxisEnum__1geteY(JNIEnv*, jclass) {
    return PxArticulationAxisEnum::eY;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationAxisEnum__1geteZ(JNIEnv*, jclass) {
    return PxArticulationAxisEnum::eZ;
}

// PxArticulationCacheFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationCacheFlagEnum__1geteVELOCITY(JNIEnv*, jclass) {
    return PxArticulationCacheFlagEnum::eVELOCITY;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationCacheFlagEnum__1geteACCELERATION(JNIEnv*, jclass) {
    return PxArticulationCacheFlagEnum::eACCELERATION;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationCacheFlagEnum__1getePOSITION(JNIEnv*, jclass) {
    return PxArticulationCacheFlagEnum::ePOSITION;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationCacheFlagEnum__1geteFORCE(JNIEnv*, jclass) {
    return PxArticulationCacheFlagEnum::eFORCE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationCacheFlagEnum__1geteLINK_1VELOCITY(JNIEnv*, jclass) {
    return PxArticulationCacheFlagEnum::eLINK_VELOCITY;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationCacheFlagEnum__1geteLINK_1ACCELERATION(JNIEnv*, jclass) {
    return PxArticulationCacheFlagEnum::eLINK_ACCELERATION;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationCacheFlagEnum__1geteROOT_1TRANSFORM(JNIEnv*, jclass) {
    return PxArticulationCacheFlagEnum::eROOT_TRANSFORM;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationCacheFlagEnum__1geteROOT_1VELOCITIES(JNIEnv*, jclass) {
    return PxArticulationCacheFlagEnum::eROOT_VELOCITIES;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationCacheFlagEnum__1geteSENSOR_1FORCES(JNIEnv*, jclass) {
    return PxArticulationCacheFlagEnum::eSENSOR_FORCES;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationCacheFlagEnum__1geteJOINT_1SOLVER_1FORCES(JNIEnv*, jclass) {
    return PxArticulationCacheFlagEnum::eJOINT_SOLVER_FORCES;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationCacheFlagEnum__1geteALL(JNIEnv*, jclass) {
    return PxArticulationCacheFlagEnum::eALL;
}

// PxArticulationDriveTypeEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationDriveTypeEnum__1geteFORCE(JNIEnv*, jclass) {
    return PxArticulationDriveTypeEnum::eFORCE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationDriveTypeEnum__1geteACCELERATION(JNIEnv*, jclass) {
    return PxArticulationDriveTypeEnum::eACCELERATION;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationDriveTypeEnum__1geteTARGET(JNIEnv*, jclass) {
    return PxArticulationDriveTypeEnum::eTARGET;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationDriveTypeEnum__1geteVELOCITY(JNIEnv*, jclass) {
    return PxArticulationDriveTypeEnum::eVELOCITY;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationDriveTypeEnum__1geteNONE(JNIEnv*, jclass) {
    return PxArticulationDriveTypeEnum::eNONE;
}

// PxArticulationFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationFlagEnum__1geteFIX_1BASE(JNIEnv*, jclass) {
    return PxArticulationFlagEnum::eFIX_BASE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationFlagEnum__1geteDRIVE_1LIMITS_1ARE_1FORCES(JNIEnv*, jclass) {
    return PxArticulationFlagEnum::eDRIVE_LIMITS_ARE_FORCES;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationFlagEnum__1geteDISABLE_1SELF_1COLLISION(JNIEnv*, jclass) {
    return PxArticulationFlagEnum::eDISABLE_SELF_COLLISION;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationFlagEnum__1geteCOMPUTE_1JOINT_1FORCES(JNIEnv*, jclass) {
    return PxArticulationFlagEnum::eCOMPUTE_JOINT_FORCES;
}

// PxArticulationJointTypeEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationJointTypeEnum__1geteFIX(JNIEnv*, jclass) {
    return PxArticulationJointTypeEnum::eFIX;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationJointTypeEnum__1getePRISMATIC(JNIEnv*, jclass) {
    return PxArticulationJointTypeEnum::ePRISMATIC;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationJointTypeEnum__1geteREVOLUTE(JNIEnv*, jclass) {
    return PxArticulationJointTypeEnum::eREVOLUTE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationJointTypeEnum__1geteSPHERICAL(JNIEnv*, jclass) {
    return PxArticulationJointTypeEnum::eSPHERICAL;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationJointTypeEnum__1geteUNDEFINED(JNIEnv*, jclass) {
    return PxArticulationJointTypeEnum::eUNDEFINED;
}

// PxArticulationKinematicFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationKinematicFlagEnum__1getePOSITION(JNIEnv*, jclass) {
    return PxArticulationKinematicFlagEnum::ePOSITION;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationKinematicFlagEnum__1geteVELOCITY(JNIEnv*, jclass) {
    return PxArticulationKinematicFlagEnum::eVELOCITY;
}

// PxArticulationMotionEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationMotionEnum__1geteLOCKED(JNIEnv*, jclass) {
    return PxArticulationMotionEnum::eLOCKED;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationMotionEnum__1geteLIMITED(JNIEnv*, jclass) {
    return PxArticulationMotionEnum::eLIMITED;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationMotionEnum__1geteFREE(JNIEnv*, jclass) {
    return PxArticulationMotionEnum::eFREE;
}

// PxArticulationSensorFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationSensorFlagEnum__1geteFORWARD_1DYNAMICS_1FORCES(JNIEnv*, jclass) {
    return PxArticulationSensorFlagEnum::eFORWARD_DYNAMICS_FORCES;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationSensorFlagEnum__1geteCONSTRAINT_1SOLVER_1FORCES(JNIEnv*, jclass) {
    return PxArticulationSensorFlagEnum::eCONSTRAINT_SOLVER_FORCES;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationSensorFlagEnum__1geteWORLD_1FRAME(JNIEnv*, jclass) {
    return PxArticulationSensorFlagEnum::eWORLD_FRAME;
}

// PxBroadPhaseTypeEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxBroadPhaseTypeEnum__1geteSAP(JNIEnv*, jclass) {
    return PxBroadPhaseTypeEnum::eSAP;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxBroadPhaseTypeEnum__1geteMBP(JNIEnv*, jclass) {
    return PxBroadPhaseTypeEnum::eMBP;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxBroadPhaseTypeEnum__1geteABP(JNIEnv*, jclass) {
    return PxBroadPhaseTypeEnum::eABP;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxBroadPhaseTypeEnum__1getePABP(JNIEnv*, jclass) {
    return PxBroadPhaseTypeEnum::ePABP;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxBroadPhaseTypeEnum__1geteGPU(JNIEnv*, jclass) {
    return PxBroadPhaseTypeEnum::eGPU;
}

// PxBVHBuildStrategyEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxBVHBuildStrategyEnum__1geteFAST(JNIEnv*, jclass) {
    return PxBVHBuildStrategyEnum::eFAST;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxBVHBuildStrategyEnum__1geteDEFAULT(JNIEnv*, jclass) {
    return PxBVHBuildStrategyEnum::eDEFAULT;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxBVHBuildStrategyEnum__1geteSAH(JNIEnv*, jclass) {
    return PxBVHBuildStrategyEnum::eSAH;
}

// PxCombineModeEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxCombineModeEnum__1geteAVERAGE(JNIEnv*, jclass) {
    return PxCombineModeEnum::eAVERAGE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxCombineModeEnum__1geteMIN(JNIEnv*, jclass) {
    return PxCombineModeEnum::eMIN;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxCombineModeEnum__1geteMULTIPLY(JNIEnv*, jclass) {
    return PxCombineModeEnum::eMULTIPLY;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxCombineModeEnum__1geteMAX(JNIEnv*, jclass) {
    return PxCombineModeEnum::eMAX;
}

// PxConstraintFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintFlagEnum__1geteBROKEN(JNIEnv*, jclass) {
    return PxConstraintFlagEnum::eBROKEN;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintFlagEnum__1getePROJECT_1TO_1ACTOR0(JNIEnv*, jclass) {
    return PxConstraintFlagEnum::ePROJECT_TO_ACTOR0;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintFlagEnum__1getePROJECT_1TO_1ACTOR1(JNIEnv*, jclass) {
    return PxConstraintFlagEnum::ePROJECT_TO_ACTOR1;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintFlagEnum__1getePROJECTION(JNIEnv*, jclass) {
    return PxConstraintFlagEnum::ePROJECTION;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintFlagEnum__1geteCOLLISION_1ENABLED(JNIEnv*, jclass) {
    return PxConstraintFlagEnum::eCOLLISION_ENABLED;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintFlagEnum__1geteVISUALIZATION(JNIEnv*, jclass) {
    return PxConstraintFlagEnum::eVISUALIZATION;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintFlagEnum__1geteDRIVE_1LIMITS_1ARE_1FORCES(JNIEnv*, jclass) {
    return PxConstraintFlagEnum::eDRIVE_LIMITS_ARE_FORCES;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintFlagEnum__1geteIMPROVED_1SLERP(JNIEnv*, jclass) {
    return PxConstraintFlagEnum::eIMPROVED_SLERP;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintFlagEnum__1geteDISABLE_1PREPROCESSING(JNIEnv*, jclass) {
    return PxConstraintFlagEnum::eDISABLE_PREPROCESSING;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintFlagEnum__1geteENABLE_1EXTENDED_1LIMITS(JNIEnv*, jclass) {
    return PxConstraintFlagEnum::eENABLE_EXTENDED_LIMITS;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintFlagEnum__1geteGPU_1COMPATIBLE(JNIEnv*, jclass) {
    return PxConstraintFlagEnum::eGPU_COMPATIBLE;
}

// PxContactPairHeaderFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxContactPairHeaderFlagEnum__1geteREMOVED_1ACTOR_10(JNIEnv*, jclass) {
    return PxContactPairHeaderFlagEnum::eREMOVED_ACTOR_0;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxContactPairHeaderFlagEnum__1geteREMOVED_1ACTOR_11(JNIEnv*, jclass) {
    return PxContactPairHeaderFlagEnum::eREMOVED_ACTOR_1;
}

// PxContactPairFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxContactPairFlagEnum__1geteREMOVED_1SHAPE_10(JNIEnv*, jclass) {
    return PxContactPairFlagEnum::eREMOVED_SHAPE_0;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxContactPairFlagEnum__1geteREMOVED_1SHAPE_11(JNIEnv*, jclass) {
    return PxContactPairFlagEnum::eREMOVED_SHAPE_1;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxContactPairFlagEnum__1geteACTOR_1PAIR_1HAS_1FIRST_1TOUCH(JNIEnv*, jclass) {
    return PxContactPairFlagEnum::eACTOR_PAIR_HAS_FIRST_TOUCH;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxContactPairFlagEnum__1geteACTOR_1PAIR_1LOST_1TOUCH(JNIEnv*, jclass) {
    return PxContactPairFlagEnum::eACTOR_PAIR_LOST_TOUCH;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxContactPairFlagEnum__1geteINTERNAL_1HAS_1IMPULSES(JNIEnv*, jclass) {
    return PxContactPairFlagEnum::eINTERNAL_HAS_IMPULSES;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxContactPairFlagEnum__1geteINTERNAL_1CONTACTS_1ARE_1FLIPPED(JNIEnv*, jclass) {
    return PxContactPairFlagEnum::eINTERNAL_CONTACTS_ARE_FLIPPED;
}

// PxDynamicTreeSecondaryPrunerEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxDynamicTreeSecondaryPrunerEnum__1geteNONE(JNIEnv*, jclass) {
    return PxDynamicTreeSecondaryPrunerEnum::eNONE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxDynamicTreeSecondaryPrunerEnum__1geteBUCKET(JNIEnv*, jclass) {
    return PxDynamicTreeSecondaryPrunerEnum::eBUCKET;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxDynamicTreeSecondaryPrunerEnum__1geteINCREMENTAL(JNIEnv*, jclass) {
    return PxDynamicTreeSecondaryPrunerEnum::eINCREMENTAL;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxDynamicTreeSecondaryPrunerEnum__1geteBVH(JNIEnv*, jclass) {
    return PxDynamicTreeSecondaryPrunerEnum::eBVH;
}

// PxFilterFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxFilterFlagEnum__1geteKILL(JNIEnv*, jclass) {
    return PxFilterFlagEnum::eKILL;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxFilterFlagEnum__1geteSUPPRESS(JNIEnv*, jclass) {
    return PxFilterFlagEnum::eSUPPRESS;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxFilterFlagEnum__1geteCALLBACK(JNIEnv*, jclass) {
    return PxFilterFlagEnum::eCALLBACK;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxFilterFlagEnum__1geteNOTIFY(JNIEnv*, jclass) {
    return PxFilterFlagEnum::eNOTIFY;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxFilterFlagEnum__1geteDEFAULT(JNIEnv*, jclass) {
    return PxFilterFlagEnum::eDEFAULT;
}

// PxFilterObjectFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxFilterObjectFlagEnum__1geteKINEMATIC(JNIEnv*, jclass) {
    return PxFilterObjectFlagEnum::eKINEMATIC;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxFilterObjectFlagEnum__1geteTRIGGER(JNIEnv*, jclass) {
    return PxFilterObjectFlagEnum::eTRIGGER;
}

// PxForceModeEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxForceModeEnum__1geteFORCE(JNIEnv*, jclass) {
    return PxForceModeEnum::eFORCE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxForceModeEnum__1geteIMPULSE(JNIEnv*, jclass) {
    return PxForceModeEnum::eIMPULSE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxForceModeEnum__1geteVELOCITY_1CHANGE(JNIEnv*, jclass) {
    return PxForceModeEnum::eVELOCITY_CHANGE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxForceModeEnum__1geteACCELERATION(JNIEnv*, jclass) {
    return PxForceModeEnum::eACCELERATION;
}

// PxFrictionTypeEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxFrictionTypeEnum__1getePATCH(JNIEnv*, jclass) {
    return PxFrictionTypeEnum::ePATCH;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxFrictionTypeEnum__1geteONE_1DIRECTIONAL(JNIEnv*, jclass) {
    return PxFrictionTypeEnum::eONE_DIRECTIONAL;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxFrictionTypeEnum__1geteTWO_1DIRECTIONAL(JNIEnv*, jclass) {
    return PxFrictionTypeEnum::eTWO_DIRECTIONAL;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxFrictionTypeEnum__1geteFRICTION_1COUNT(JNIEnv*, jclass) {
    return PxFrictionTypeEnum::eFRICTION_COUNT;
}

// PxMaterialFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxMaterialFlagEnum__1geteDISABLE_1FRICTION(JNIEnv*, jclass) {
    return PxMaterialFlagEnum::eDISABLE_FRICTION;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxMaterialFlagEnum__1geteDISABLE_1STRONG_1FRICTION(JNIEnv*, jclass) {
    return PxMaterialFlagEnum::eDISABLE_STRONG_FRICTION;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxMaterialFlagEnum__1geteIMPROVED_1PATCH_1FRICTION(JNIEnv*, jclass) {
    return PxMaterialFlagEnum::eIMPROVED_PATCH_FRICTION;
}

// PxPairFilteringModeEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFilteringModeEnum__1geteKEEP(JNIEnv*, jclass) {
    return PxPairFilteringModeEnum::eKEEP;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFilteringModeEnum__1geteSUPPRESS(JNIEnv*, jclass) {
    return PxPairFilteringModeEnum::eSUPPRESS;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFilteringModeEnum__1geteKILL(JNIEnv*, jclass) {
    return PxPairFilteringModeEnum::eKILL;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFilteringModeEnum__1geteDEFAULT(JNIEnv*, jclass) {
    return PxPairFilteringModeEnum::eDEFAULT;
}

// PxPairFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteSOLVE_1CONTACT(JNIEnv*, jclass) {
    return PxPairFlagEnum::eSOLVE_CONTACT;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteMODIFY_1CONTACTS(JNIEnv*, jclass) {
    return PxPairFlagEnum::eMODIFY_CONTACTS;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteNOTIFY_1TOUCH_1FOUND(JNIEnv*, jclass) {
    return PxPairFlagEnum::eNOTIFY_TOUCH_FOUND;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteNOTIFY_1TOUCH_1PERSISTS(JNIEnv*, jclass) {
    return PxPairFlagEnum::eNOTIFY_TOUCH_PERSISTS;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteNOTIFY_1TOUCH_1LOST(JNIEnv*, jclass) {
    return PxPairFlagEnum::eNOTIFY_TOUCH_LOST;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteNOTIFY_1TOUCH_1CCD(JNIEnv*, jclass) {
    return PxPairFlagEnum::eNOTIFY_TOUCH_CCD;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteNOTIFY_1THRESHOLD_1FORCE_1FOUND(JNIEnv*, jclass) {
    return PxPairFlagEnum::eNOTIFY_THRESHOLD_FORCE_FOUND;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteNOTIFY_1THRESHOLD_1FORCE_1PERSISTS(JNIEnv*, jclass) {
    return PxPairFlagEnum::eNOTIFY_THRESHOLD_FORCE_PERSISTS;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteNOTIFY_1THRESHOLD_1FORCE_1LOST(JNIEnv*, jclass) {
    return PxPairFlagEnum::eNOTIFY_THRESHOLD_FORCE_LOST;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteNOTIFY_1CONTACT_1POINTS(JNIEnv*, jclass) {
    return PxPairFlagEnum::eNOTIFY_CONTACT_POINTS;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteDETECT_1DISCRETE_1CONTACT(JNIEnv*, jclass) {
    return PxPairFlagEnum::eDETECT_DISCRETE_CONTACT;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteDETECT_1CCD_1CONTACT(JNIEnv*, jclass) {
    return PxPairFlagEnum::eDETECT_CCD_CONTACT;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1getePRE_1SOLVER_1VELOCITY(JNIEnv*, jclass) {
    return PxPairFlagEnum::ePRE_SOLVER_VELOCITY;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1getePOST_1SOLVER_1VELOCITY(JNIEnv*, jclass) {
    return PxPairFlagEnum::ePOST_SOLVER_VELOCITY;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteCONTACT_1EVENT_1POSE(JNIEnv*, jclass) {
    return PxPairFlagEnum::eCONTACT_EVENT_POSE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteNEXT_1FREE(JNIEnv*, jclass) {
    return PxPairFlagEnum::eNEXT_FREE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteCONTACT_1DEFAULT(JNIEnv*, jclass) {
    return PxPairFlagEnum::eCONTACT_DEFAULT;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteTRIGGER_1DEFAULT(JNIEnv*, jclass) {
    return PxPairFlagEnum::eTRIGGER_DEFAULT;
}

// PxParticleSolverTypeEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxParticleSolverTypeEnum__1getePBD(JNIEnv*, jclass) {
    return PxParticleSolverTypeEnum::ePBD;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxParticleSolverTypeEnum__1geteFLIP(JNIEnv*, jclass) {
    return PxParticleSolverTypeEnum::eFLIP;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxParticleSolverTypeEnum__1geteMPM(JNIEnv*, jclass) {
    return PxParticleSolverTypeEnum::eMPM;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxParticleSolverTypeEnum__1geteCUSTOM(JNIEnv*, jclass) {
    return PxParticleSolverTypeEnum::eCUSTOM;
}

// PxPruningStructureTypeEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxPruningStructureTypeEnum__1geteNONE(JNIEnv*, jclass) {
    return PxPruningStructureTypeEnum::eNONE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPruningStructureTypeEnum__1geteDYNAMIC_1AABB_1TREE(JNIEnv*, jclass) {
    return PxPruningStructureTypeEnum::eDYNAMIC_AABB_TREE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPruningStructureTypeEnum__1geteSTATIC_1AABB_1TREE(JNIEnv*, jclass) {
    return PxPruningStructureTypeEnum::eSTATIC_AABB_TREE;
}

// PxSolverTypeEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxSolverTypeEnum__1getePGS(JNIEnv*, jclass) {
    return PxSolverTypeEnum::ePGS;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSolverTypeEnum__1geteTGS(JNIEnv*, jclass) {
    return PxSolverTypeEnum::eTGS;
}

// PxTriggerPairFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxTriggerPairFlagEnum__1geteREMOVED_1SHAPE_1TRIGGER(JNIEnv*, jclass) {
    return PxTriggerPairFlagEnum::eREMOVED_SHAPE_TRIGGER;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxTriggerPairFlagEnum__1geteREMOVED_1SHAPE_1OTHER(JNIEnv*, jclass) {
    return PxTriggerPairFlagEnum::eREMOVED_SHAPE_OTHER;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxTriggerPairFlagEnum__1geteNEXT_1FREE(JNIEnv*, jclass) {
    return PxTriggerPairFlagEnum::eNEXT_FREE;
}

// PxSceneFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteENABLE_1ACTIVE_1ACTORS(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eENABLE_ACTIVE_ACTORS;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteENABLE_1CCD(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eENABLE_CCD;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteDISABLE_1CCD_1RESWEEP(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eDISABLE_CCD_RESWEEP;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteENABLE_1PCM(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eENABLE_PCM;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteDISABLE_1CONTACT_1REPORT_1BUFFER_1RESIZE(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eDISABLE_CONTACT_REPORT_BUFFER_RESIZE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteDISABLE_1CONTACT_1CACHE(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eDISABLE_CONTACT_CACHE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteREQUIRE_1RW_1LOCK(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eREQUIRE_RW_LOCK;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteENABLE_1STABILIZATION(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eENABLE_STABILIZATION;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteENABLE_1AVERAGE_1POINT(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eENABLE_AVERAGE_POINT;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteEXCLUDE_1KINEMATICS_1FROM_1ACTIVE_1ACTORS(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eEXCLUDE_KINEMATICS_FROM_ACTIVE_ACTORS;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteENABLE_1GPU_1DYNAMICS(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eENABLE_GPU_DYNAMICS;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteENABLE_1ENHANCED_1DETERMINISM(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eENABLE_ENHANCED_DETERMINISM;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteENABLE_1FRICTION_1EVERY_1ITERATION(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eENABLE_FRICTION_EVERY_ITERATION;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteSUPPRESS_1READBACK(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eSUPPRESS_READBACK;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteFORCE_1READBACK(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eFORCE_READBACK;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteMUTABLE_1FLAGS(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eMUTABLE_FLAGS;
}

// PxSceneQueryUpdateModeEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneQueryUpdateModeEnum__1geteBUILD_1ENABLED_1COMMIT_1ENABLED(JNIEnv*, jclass) {
    return PxSceneQueryUpdateModeEnum::eBUILD_ENABLED_COMMIT_ENABLED;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneQueryUpdateModeEnum__1geteBUILD_1ENABLED_1COMMIT_1DISABLED(JNIEnv*, jclass) {
    return PxSceneQueryUpdateModeEnum::eBUILD_ENABLED_COMMIT_DISABLED;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneQueryUpdateModeEnum__1geteBUILD_1DISABLED_1COMMIT_1DISABLED(JNIEnv*, jclass) {
    return PxSceneQueryUpdateModeEnum::eBUILD_DISABLED_COMMIT_DISABLED;
}

// PxHitFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxHitFlagEnum__1getePOSITION(JNIEnv*, jclass) {
    return PxHitFlagEnum::ePOSITION;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxHitFlagEnum__1geteNORMAL(JNIEnv*, jclass) {
    return PxHitFlagEnum::eNORMAL;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxHitFlagEnum__1geteUV(JNIEnv*, jclass) {
    return PxHitFlagEnum::eUV;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxHitFlagEnum__1geteASSUME_1NO_1INITIAL_1OVERLAP(JNIEnv*, jclass) {
    return PxHitFlagEnum::eASSUME_NO_INITIAL_OVERLAP;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxHitFlagEnum__1geteMESH_1MULTIPLE(JNIEnv*, jclass) {
    return PxHitFlagEnum::eMESH_MULTIPLE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxHitFlagEnum__1geteMESH_1ANY(JNIEnv*, jclass) {
    return PxHitFlagEnum::eMESH_ANY;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxHitFlagEnum__1geteMESH_1BOTH_1SIDES(JNIEnv*, jclass) {
    return PxHitFlagEnum::eMESH_BOTH_SIDES;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxHitFlagEnum__1getePRECISE_1SWEEP(JNIEnv*, jclass) {
    return PxHitFlagEnum::ePRECISE_SWEEP;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxHitFlagEnum__1geteMTD(JNIEnv*, jclass) {
    return PxHitFlagEnum::eMTD;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxHitFlagEnum__1geteFACE_1INDEX(JNIEnv*, jclass) {
    return PxHitFlagEnum::eFACE_INDEX;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxHitFlagEnum__1geteDEFAULT(JNIEnv*, jclass) {
    return PxHitFlagEnum::eDEFAULT;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxHitFlagEnum__1geteMODIFIABLE_1FLAGS(JNIEnv*, jclass) {
    return PxHitFlagEnum::eMODIFIABLE_FLAGS;
}

// PxQueryFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxQueryFlagEnum__1geteSTATIC(JNIEnv*, jclass) {
    return PxQueryFlagEnum::eSTATIC;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxQueryFlagEnum__1geteDYNAMIC(JNIEnv*, jclass) {
    return PxQueryFlagEnum::eDYNAMIC;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxQueryFlagEnum__1getePREFILTER(JNIEnv*, jclass) {
    return PxQueryFlagEnum::ePREFILTER;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxQueryFlagEnum__1getePOSTFILTER(JNIEnv*, jclass) {
    return PxQueryFlagEnum::ePOSTFILTER;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxQueryFlagEnum__1geteANY_1HIT(JNIEnv*, jclass) {
    return PxQueryFlagEnum::eANY_HIT;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxQueryFlagEnum__1geteNO_1BLOCK(JNIEnv*, jclass) {
    return PxQueryFlagEnum::eNO_BLOCK;
}

// PxShapeFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxShapeFlagEnum__1geteSIMULATION_1SHAPE(JNIEnv*, jclass) {
    return PxShapeFlagEnum::eSIMULATION_SHAPE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxShapeFlagEnum__1geteSCENE_1QUERY_1SHAPE(JNIEnv*, jclass) {
    return PxShapeFlagEnum::eSCENE_QUERY_SHAPE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxShapeFlagEnum__1geteTRIGGER_1SHAPE(JNIEnv*, jclass) {
    return PxShapeFlagEnum::eTRIGGER_SHAPE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxShapeFlagEnum__1geteVISUALIZATION(JNIEnv*, jclass) {
    return PxShapeFlagEnum::eVISUALIZATION;
}

// SupportFunctions
JNIEXPORT jint JNICALL Java_physx_support_SupportFunctions__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(SupportFunctions);
}
JNIEXPORT jlong JNICALL Java_physx_support_SupportFunctions__1PxActor_1getShape(JNIEnv*, jclass, jlong actor, jint index) {
    return (jlong) SupportFunctions::PxActor_getShape(*((physx::PxRigidActor*) actor), index);
}
JNIEXPORT jlong JNICALL Java_physx_support_SupportFunctions__1PxScene_1getActiveActors(JNIEnv*, jclass, jlong scene) {
    return (jlong) &SupportFunctions::PxScene_getActiveActors((physx::PxScene*) scene);
}
JNIEXPORT jint JNICALL Java_physx_support_SupportFunctions__1PxArticulationReducedCoordinate_1getMinSolverPositionIterations(JNIEnv*, jclass, jlong articulation) {
    return (jint) SupportFunctions::PxArticulationReducedCoordinate_getMinSolverPositionIterations((physx::PxArticulationReducedCoordinate*) articulation);
}
JNIEXPORT jint JNICALL Java_physx_support_SupportFunctions__1PxArticulationReducedCoordinate_1getMinSolverVelocityIterations(JNIEnv*, jclass, jlong articulation) {
    return (jint) SupportFunctions::PxArticulationReducedCoordinate_getMinSolverVelocityIterations((physx::PxArticulationReducedCoordinate*) articulation);
}
JNIEXPORT void JNICALL Java_physx_support_SupportFunctions__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (SupportFunctions*) _address;
}

// PxU8Ptr
JNIEXPORT jint JNICALL Java_physx_support_PxU8Ptr__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxU8Ptr);
}
JNIEXPORT void JNICALL Java_physx_support_PxU8Ptr__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxU8Ptr*) _address;
}

// PxU8ConstPtr
JNIEXPORT jint JNICALL Java_physx_support_PxU8ConstPtr__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxU8ConstPtr);
}
JNIEXPORT void JNICALL Java_physx_support_PxU8ConstPtr__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxU8ConstPtr*) _address;
}

// PxU16Ptr
JNIEXPORT jint JNICALL Java_physx_support_PxU16Ptr__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxU16Ptr);
}
JNIEXPORT void JNICALL Java_physx_support_PxU16Ptr__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxU16Ptr*) _address;
}

// PxU16ConstPtr
JNIEXPORT jint JNICALL Java_physx_support_PxU16ConstPtr__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxU16ConstPtr);
}
JNIEXPORT void JNICALL Java_physx_support_PxU16ConstPtr__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxU16ConstPtr*) _address;
}

// PxU32Ptr
JNIEXPORT jint JNICALL Java_physx_support_PxU32Ptr__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxU32Ptr);
}
JNIEXPORT void JNICALL Java_physx_support_PxU32Ptr__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxU32Ptr*) _address;
}

// PxU32ConstPtr
JNIEXPORT jint JNICALL Java_physx_support_PxU32ConstPtr__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxU32ConstPtr);
}
JNIEXPORT void JNICALL Java_physx_support_PxU32ConstPtr__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxU32ConstPtr*) _address;
}

// PxRealPtr
JNIEXPORT jint JNICALL Java_physx_support_PxRealPtr__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxRealPtr);
}
JNIEXPORT void JNICALL Java_physx_support_PxRealPtr__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxRealPtr*) _address;
}

// PxActorPtr
JNIEXPORT jint JNICALL Java_physx_support_PxActorPtr__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxActorPtr);
}
JNIEXPORT void JNICALL Java_physx_support_PxActorPtr__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxActorPtr*) _address;
}

// PxMaterialPtr
JNIEXPORT jint JNICALL Java_physx_support_PxMaterialPtr__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxMaterialPtr);
}
JNIEXPORT void JNICALL Java_physx_support_PxMaterialPtr__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxMaterialPtr*) _address;
}

// PxMaterialConstPtr
JNIEXPORT jint JNICALL Java_physx_support_PxMaterialConstPtr__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxMaterialConstPtr);
}
JNIEXPORT void JNICALL Java_physx_support_PxMaterialConstPtr__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxMaterialConstPtr*) _address;
}

// PxVehicleWheelsPtr
JNIEXPORT jint JNICALL Java_physx_support_PxVehicleWheelsPtr__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxVehicleWheelsPtr);
}
JNIEXPORT void JNICALL Java_physx_support_PxVehicleWheelsPtr__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxVehicleWheelsPtr*) _address;
}

// NativeArrayHelpers
JNIEXPORT jint JNICALL Java_physx_support_NativeArrayHelpers__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(NativeArrayHelpers);
}
JNIEXPORT jbyte JNICALL Java_physx_support_NativeArrayHelpers__1getU8At(JNIEnv*, jclass, jlong base, jint index) {
    return (jbyte) NativeArrayHelpers::getU8At(*((PxU8ConstPtr*) base), index);
}
JNIEXPORT jshort JNICALL Java_physx_support_NativeArrayHelpers__1getU16At(JNIEnv*, jclass, jlong base, jint index) {
    return (jshort) NativeArrayHelpers::getU16At(*((PxU16ConstPtr*) base), index);
}
JNIEXPORT jint JNICALL Java_physx_support_NativeArrayHelpers__1getU32At(JNIEnv*, jclass, jlong base, jint index) {
    return (jint) NativeArrayHelpers::getU32At(*((PxU32ConstPtr*) base), index);
}
JNIEXPORT jfloat JNICALL Java_physx_support_NativeArrayHelpers__1getRealAt(JNIEnv*, jclass, jlong base, jint index) {
    return (jfloat) NativeArrayHelpers::getRealAt(*((PxRealPtr*) base), index);
}
JNIEXPORT jlong JNICALL Java_physx_support_NativeArrayHelpers__1voidToU8Ptr(JNIEnv*, jclass, jlong voidPtr) {
    static thread_local PxU8Ptr _cache = NativeArrayHelpers::voidToU8Ptr((void*) voidPtr);
    _cache = NativeArrayHelpers::voidToU8Ptr((void*) voidPtr);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_support_NativeArrayHelpers__1voidToU16Ptr(JNIEnv*, jclass, jlong voidPtr) {
    static thread_local PxU16Ptr _cache = NativeArrayHelpers::voidToU16Ptr((void*) voidPtr);
    _cache = NativeArrayHelpers::voidToU16Ptr((void*) voidPtr);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_support_NativeArrayHelpers__1voidToU32Ptr(JNIEnv*, jclass, jlong voidPtr) {
    static thread_local PxU32Ptr _cache = NativeArrayHelpers::voidToU32Ptr((void*) voidPtr);
    _cache = NativeArrayHelpers::voidToU32Ptr((void*) voidPtr);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_support_NativeArrayHelpers__1voidToRealPtr(JNIEnv*, jclass, jlong voidPtr) {
    static thread_local PxRealPtr _cache = NativeArrayHelpers::voidToRealPtr((void*) voidPtr);
    _cache = NativeArrayHelpers::voidToRealPtr((void*) voidPtr);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_support_NativeArrayHelpers__1getActorAt(JNIEnv*, jclass, jlong base, jint index) {
    return (jlong) NativeArrayHelpers::getActorAt((physx::PxActor*) base, index);
}
JNIEXPORT jlong JNICALL Java_physx_support_NativeArrayHelpers__1getBounds3At(JNIEnv*, jclass, jlong base, jint index) {
    return (jlong) NativeArrayHelpers::getBounds3At((physx::PxBounds3*) base, index);
}
JNIEXPORT jlong JNICALL Java_physx_support_NativeArrayHelpers__1getContactPairAt(JNIEnv*, jclass, jlong base, jint index) {
    return (jlong) NativeArrayHelpers::getContactPairAt((physx::PxContactPair*) base, index);
}
JNIEXPORT jlong JNICALL Java_physx_support_NativeArrayHelpers__1getContactPairHeaderAt(JNIEnv*, jclass, jlong base, jint index) {
    return (jlong) NativeArrayHelpers::getContactPairHeaderAt((physx::PxContactPairHeader*) base, index);
}
JNIEXPORT jlong JNICALL Java_physx_support_NativeArrayHelpers__1getControllerAt(JNIEnv*, jclass, jlong base, jint index) {
    return (jlong) NativeArrayHelpers::getControllerAt((physx::PxController*) base, index);
}
JNIEXPORT jlong JNICALL Java_physx_support_NativeArrayHelpers__1getControllerShapeHitAt(JNIEnv*, jclass, jlong base, jint index) {
    return (jlong) NativeArrayHelpers::getControllerShapeHitAt((physx::PxControllerShapeHit*) base, index);
}
JNIEXPORT jlong JNICALL Java_physx_support_NativeArrayHelpers__1getControllersHitAt(JNIEnv*, jclass, jlong base, jint index) {
    return (jlong) NativeArrayHelpers::getControllersHitAt((physx::PxControllersHit*) base, index);
}
JNIEXPORT jlong JNICALL Java_physx_support_NativeArrayHelpers__1getControllerObstacleHitAt(JNIEnv*, jclass, jlong base, jint index) {
    return (jlong) NativeArrayHelpers::getControllerObstacleHitAt((physx::PxControllerObstacleHit*) base, index);
}
JNIEXPORT jlong JNICALL Java_physx_support_NativeArrayHelpers__1getObstacleAt(JNIEnv*, jclass, jlong base, jint index) {
    return (jlong) NativeArrayHelpers::getObstacleAt((physx::PxObstacle*) base, index);
}
JNIEXPORT jlong JNICALL Java_physx_support_NativeArrayHelpers__1getShapeAt(JNIEnv*, jclass, jlong base, jint index) {
    return (jlong) NativeArrayHelpers::getShapeAt((physx::PxShape*) base, index);
}
JNIEXPORT jlong JNICALL Java_physx_support_NativeArrayHelpers__1getTriggerPairAt(JNIEnv*, jclass, jlong base, jint index) {
    return (jlong) NativeArrayHelpers::getTriggerPairAt((physx::PxTriggerPair*) base, index);
}
JNIEXPORT jlong JNICALL Java_physx_support_NativeArrayHelpers__1getVec3At(JNIEnv*, jclass, jlong base, jint index) {
    return (jlong) NativeArrayHelpers::getVec3At((physx::PxVec3*) base, index);
}
JNIEXPORT void JNICALL Java_physx_support_NativeArrayHelpers__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (NativeArrayHelpers*) _address;
}

// Vector_PxMaterialConst
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxMaterialConst__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(Vector_PxMaterialConst);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxMaterialConst__1Vector_1PxMaterialConst__(JNIEnv*, jclass) {
    return (jlong) new Vector_PxMaterialConst();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxMaterialConst__1Vector_1PxMaterialConst__I(JNIEnv*, jclass, jint size) {
    return (jlong) new Vector_PxMaterialConst(size);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxMaterialConst__1at(JNIEnv*, jclass, jlong _address, jint index) {
    Vector_PxMaterialConst* self = (Vector_PxMaterialConst*) _address;
    return (jlong) self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxMaterialConst__1data(JNIEnv*, jclass, jlong _address) {
    Vector_PxMaterialConst* self = (Vector_PxMaterialConst*) _address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxMaterialConst__1size(JNIEnv*, jclass, jlong _address) {
    Vector_PxMaterialConst* self = (Vector_PxMaterialConst*) _address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxMaterialConst__1push_1back(JNIEnv*, jclass, jlong _address, jlong value) {
    Vector_PxMaterialConst* self = (Vector_PxMaterialConst*) _address;
    self->push_back((physx::PxMaterial*) value);
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxMaterialConst__1clear(JNIEnv*, jclass, jlong _address) {
    Vector_PxMaterialConst* self = (Vector_PxMaterialConst*) _address;
    self->clear();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxMaterialConst__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (Vector_PxMaterialConst*) _address;
}

// Vector_PxHeightFieldSample
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxHeightFieldSample__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(Vector_PxHeightFieldSample);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxHeightFieldSample__1Vector_1PxHeightFieldSample__(JNIEnv*, jclass) {
    return (jlong) new Vector_PxHeightFieldSample();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxHeightFieldSample__1Vector_1PxHeightFieldSample__I(JNIEnv*, jclass, jint size) {
    return (jlong) new Vector_PxHeightFieldSample(size);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxHeightFieldSample__1at(JNIEnv*, jclass, jlong _address, jint index) {
    Vector_PxHeightFieldSample* self = (Vector_PxHeightFieldSample*) _address;
    return (jlong) &self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxHeightFieldSample__1data(JNIEnv*, jclass, jlong _address) {
    Vector_PxHeightFieldSample* self = (Vector_PxHeightFieldSample*) _address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxHeightFieldSample__1size(JNIEnv*, jclass, jlong _address) {
    Vector_PxHeightFieldSample* self = (Vector_PxHeightFieldSample*) _address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxHeightFieldSample__1push_1back(JNIEnv*, jclass, jlong _address, jlong value) {
    Vector_PxHeightFieldSample* self = (Vector_PxHeightFieldSample*) _address;
    self->push_back(*((physx::PxHeightFieldSample*) value));
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxHeightFieldSample__1clear(JNIEnv*, jclass, jlong _address) {
    Vector_PxHeightFieldSample* self = (Vector_PxHeightFieldSample*) _address;
    self->clear();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxHeightFieldSample__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (Vector_PxHeightFieldSample*) _address;
}

// Vector_PxReal
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxReal__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(Vector_PxReal);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxReal__1Vector_1PxReal__(JNIEnv*, jclass) {
    return (jlong) new Vector_PxReal();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxReal__1Vector_1PxReal__I(JNIEnv*, jclass, jint size) {
    return (jlong) new Vector_PxReal(size);
}
JNIEXPORT jfloat JNICALL Java_physx_support_Vector_1PxReal__1at(JNIEnv*, jclass, jlong _address, jint index) {
    Vector_PxReal* self = (Vector_PxReal*) _address;
    return (jfloat) self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxReal__1data(JNIEnv*, jclass, jlong _address) {
    Vector_PxReal* self = (Vector_PxReal*) _address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxReal__1size(JNIEnv*, jclass, jlong _address) {
    Vector_PxReal* self = (Vector_PxReal*) _address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxReal__1push_1back(JNIEnv*, jclass, jlong _address, jfloat value) {
    Vector_PxReal* self = (Vector_PxReal*) _address;
    self->push_back(value);
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxReal__1clear(JNIEnv*, jclass, jlong _address) {
    Vector_PxReal* self = (Vector_PxReal*) _address;
    self->clear();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxReal__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (Vector_PxReal*) _address;
}

// Vector_PxU8
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxU8__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(Vector_PxU8);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxU8__1Vector_1PxU8__(JNIEnv*, jclass) {
    return (jlong) new Vector_PxU8();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxU8__1Vector_1PxU8__I(JNIEnv*, jclass, jint size) {
    return (jlong) new Vector_PxU8(size);
}
JNIEXPORT jbyte JNICALL Java_physx_support_Vector_1PxU8__1at(JNIEnv*, jclass, jlong _address, jint index) {
    Vector_PxU8* self = (Vector_PxU8*) _address;
    return (jbyte) self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxU8__1data(JNIEnv*, jclass, jlong _address) {
    Vector_PxU8* self = (Vector_PxU8*) _address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxU8__1size(JNIEnv*, jclass, jlong _address) {
    Vector_PxU8* self = (Vector_PxU8*) _address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxU8__1push_1back(JNIEnv*, jclass, jlong _address, jbyte value) {
    Vector_PxU8* self = (Vector_PxU8*) _address;
    self->push_back(value);
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxU8__1clear(JNIEnv*, jclass, jlong _address) {
    Vector_PxU8* self = (Vector_PxU8*) _address;
    self->clear();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxU8__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (Vector_PxU8*) _address;
}

// Vector_PxU16
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxU16__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(Vector_PxU16);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxU16__1Vector_1PxU16__(JNIEnv*, jclass) {
    return (jlong) new Vector_PxU16();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxU16__1Vector_1PxU16__I(JNIEnv*, jclass, jint size) {
    return (jlong) new Vector_PxU16(size);
}
JNIEXPORT jshort JNICALL Java_physx_support_Vector_1PxU16__1at(JNIEnv*, jclass, jlong _address, jint index) {
    Vector_PxU16* self = (Vector_PxU16*) _address;
    return (jshort) self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxU16__1data(JNIEnv*, jclass, jlong _address) {
    Vector_PxU16* self = (Vector_PxU16*) _address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxU16__1size(JNIEnv*, jclass, jlong _address) {
    Vector_PxU16* self = (Vector_PxU16*) _address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxU16__1push_1back(JNIEnv*, jclass, jlong _address, jshort value) {
    Vector_PxU16* self = (Vector_PxU16*) _address;
    self->push_back(value);
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxU16__1clear(JNIEnv*, jclass, jlong _address) {
    Vector_PxU16* self = (Vector_PxU16*) _address;
    self->clear();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxU16__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (Vector_PxU16*) _address;
}

// Vector_PxU32
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxU32__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(Vector_PxU32);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxU32__1Vector_1PxU32__(JNIEnv*, jclass) {
    return (jlong) new Vector_PxU32();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxU32__1Vector_1PxU32__I(JNIEnv*, jclass, jint size) {
    return (jlong) new Vector_PxU32(size);
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxU32__1at(JNIEnv*, jclass, jlong _address, jint index) {
    Vector_PxU32* self = (Vector_PxU32*) _address;
    return (jint) self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxU32__1data(JNIEnv*, jclass, jlong _address) {
    Vector_PxU32* self = (Vector_PxU32*) _address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxU32__1size(JNIEnv*, jclass, jlong _address) {
    Vector_PxU32* self = (Vector_PxU32*) _address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxU32__1push_1back(JNIEnv*, jclass, jlong _address, jint value) {
    Vector_PxU32* self = (Vector_PxU32*) _address;
    self->push_back(value);
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxU32__1clear(JNIEnv*, jclass, jlong _address) {
    Vector_PxU32* self = (Vector_PxU32*) _address;
    self->clear();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxU32__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (Vector_PxU32*) _address;
}

// Vector_PxVec3
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxVec3__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(Vector_PxVec3);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVec3__1Vector_1PxVec3__(JNIEnv*, jclass) {
    return (jlong) new Vector_PxVec3();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVec3__1Vector_1PxVec3__I(JNIEnv*, jclass, jint size) {
    return (jlong) new Vector_PxVec3(size);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVec3__1at(JNIEnv*, jclass, jlong _address, jint index) {
    Vector_PxVec3* self = (Vector_PxVec3*) _address;
    return (jlong) &self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVec3__1data(JNIEnv*, jclass, jlong _address) {
    Vector_PxVec3* self = (Vector_PxVec3*) _address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxVec3__1size(JNIEnv*, jclass, jlong _address) {
    Vector_PxVec3* self = (Vector_PxVec3*) _address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxVec3__1push_1back(JNIEnv*, jclass, jlong _address, jlong value) {
    Vector_PxVec3* self = (Vector_PxVec3*) _address;
    self->push_back(*((physx::PxVec3*) value));
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxVec3__1clear(JNIEnv*, jclass, jlong _address) {
    Vector_PxVec3* self = (Vector_PxVec3*) _address;
    self->clear();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxVec3__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (Vector_PxVec3*) _address;
}

// Vector_PxActorPtr
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxActorPtr__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(Vector_PxActorPtr);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxActorPtr__1Vector_1PxActorPtr__(JNIEnv*, jclass) {
    return (jlong) new Vector_PxActorPtr();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxActorPtr__1Vector_1PxActorPtr__I(JNIEnv*, jclass, jint size) {
    return (jlong) new Vector_PxActorPtr(size);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxActorPtr__1at(JNIEnv*, jclass, jlong _address, jint index) {
    Vector_PxActorPtr* self = (Vector_PxActorPtr*) _address;
    return (jlong) self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxActorPtr__1data(JNIEnv*, jclass, jlong _address) {
    Vector_PxActorPtr* self = (Vector_PxActorPtr*) _address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxActorPtr__1size(JNIEnv*, jclass, jlong _address) {
    Vector_PxActorPtr* self = (Vector_PxActorPtr*) _address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxActorPtr__1push_1back(JNIEnv*, jclass, jlong _address, jlong value) {
    Vector_PxActorPtr* self = (Vector_PxActorPtr*) _address;
    self->push_back((physx::PxActor*) value);
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxActorPtr__1clear(JNIEnv*, jclass, jlong _address) {
    Vector_PxActorPtr* self = (Vector_PxActorPtr*) _address;
    self->clear();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxActorPtr__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (Vector_PxActorPtr*) _address;
}

// Vector_PxContactPairPoint
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxContactPairPoint__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(Vector_PxContactPairPoint);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxContactPairPoint__1Vector_1PxContactPairPoint__(JNIEnv*, jclass) {
    return (jlong) new Vector_PxContactPairPoint();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxContactPairPoint__1Vector_1PxContactPairPoint__I(JNIEnv*, jclass, jint size) {
    return (jlong) new Vector_PxContactPairPoint(size);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxContactPairPoint__1at(JNIEnv*, jclass, jlong _address, jint index) {
    Vector_PxContactPairPoint* self = (Vector_PxContactPairPoint*) _address;
    return (jlong) &self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxContactPairPoint__1data(JNIEnv*, jclass, jlong _address) {
    Vector_PxContactPairPoint* self = (Vector_PxContactPairPoint*) _address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxContactPairPoint__1size(JNIEnv*, jclass, jlong _address) {
    Vector_PxContactPairPoint* self = (Vector_PxContactPairPoint*) _address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxContactPairPoint__1push_1back(JNIEnv*, jclass, jlong _address, jlong value) {
    Vector_PxContactPairPoint* self = (Vector_PxContactPairPoint*) _address;
    self->push_back(*((physx::PxContactPairPoint*) value));
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxContactPairPoint__1clear(JNIEnv*, jclass, jlong _address) {
    Vector_PxContactPairPoint* self = (Vector_PxContactPairPoint*) _address;
    self->clear();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxContactPairPoint__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (Vector_PxContactPairPoint*) _address;
}

// Vector_PxRaycastHit
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxRaycastHit__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(Vector_PxRaycastHit);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxRaycastHit__1Vector_1PxRaycastHit__(JNIEnv*, jclass) {
    return (jlong) new Vector_PxRaycastHit();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxRaycastHit__1Vector_1PxRaycastHit__I(JNIEnv*, jclass, jint size) {
    return (jlong) new Vector_PxRaycastHit(size);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxRaycastHit__1at(JNIEnv*, jclass, jlong _address, jint index) {
    Vector_PxRaycastHit* self = (Vector_PxRaycastHit*) _address;
    return (jlong) &self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxRaycastHit__1data(JNIEnv*, jclass, jlong _address) {
    Vector_PxRaycastHit* self = (Vector_PxRaycastHit*) _address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxRaycastHit__1size(JNIEnv*, jclass, jlong _address) {
    Vector_PxRaycastHit* self = (Vector_PxRaycastHit*) _address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxRaycastHit__1push_1back(JNIEnv*, jclass, jlong _address, jlong value) {
    Vector_PxRaycastHit* self = (Vector_PxRaycastHit*) _address;
    self->push_back(*((physx::PxRaycastHit*) value));
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxRaycastHit__1clear(JNIEnv*, jclass, jlong _address) {
    Vector_PxRaycastHit* self = (Vector_PxRaycastHit*) _address;
    self->clear();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxRaycastHit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (Vector_PxRaycastHit*) _address;
}

// Vector_PxSweepHit
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxSweepHit__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(Vector_PxSweepHit);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxSweepHit__1Vector_1PxSweepHit__(JNIEnv*, jclass) {
    return (jlong) new Vector_PxSweepHit();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxSweepHit__1Vector_1PxSweepHit__I(JNIEnv*, jclass, jint size) {
    return (jlong) new Vector_PxSweepHit(size);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxSweepHit__1at(JNIEnv*, jclass, jlong _address, jint index) {
    Vector_PxSweepHit* self = (Vector_PxSweepHit*) _address;
    return (jlong) &self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxSweepHit__1data(JNIEnv*, jclass, jlong _address) {
    Vector_PxSweepHit* self = (Vector_PxSweepHit*) _address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxSweepHit__1size(JNIEnv*, jclass, jlong _address) {
    Vector_PxSweepHit* self = (Vector_PxSweepHit*) _address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxSweepHit__1push_1back(JNIEnv*, jclass, jlong _address, jlong value) {
    Vector_PxSweepHit* self = (Vector_PxSweepHit*) _address;
    self->push_back(*((physx::PxSweepHit*) value));
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxSweepHit__1clear(JNIEnv*, jclass, jlong _address) {
    Vector_PxSweepHit* self = (Vector_PxSweepHit*) _address;
    self->clear();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxSweepHit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (Vector_PxSweepHit*) _address;
}

// PassThroughFilterShader
JNIEXPORT jint JNICALL Java_physx_support_PassThroughFilterShader__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PassThroughFilterShader);
}
JNIEXPORT jint JNICALL Java_physx_support_PassThroughFilterShader__1filterShader(JNIEnv*, jclass, jlong _address, jint attributes0, jint filterData0w0, jint filterData0w1, jint filterData0w2, jint filterData0w3, jint attributes1, jint filterData1w0, jint filterData1w1, jint filterData1w2, jint filterData1w3) {
    PassThroughFilterShader* self = (PassThroughFilterShader*) _address;
    return (jint) self->filterShader(attributes0, filterData0w0, filterData0w1, filterData0w2, filterData0w3, attributes1, filterData1w0, filterData1w1, filterData1w2, filterData1w3);
}
JNIEXPORT void JNICALL Java_physx_support_PassThroughFilterShader__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PassThroughFilterShader*) _address;
}
JNIEXPORT jint JNICALL Java_physx_support_PassThroughFilterShader__1getOutputPairFlags(JNIEnv*, jclass, jlong _address) {
    PassThroughFilterShader* _self = (PassThroughFilterShader*) _address;
    return (jint) _self->outputPairFlags;
}
JNIEXPORT void JNICALL Java_physx_support_PassThroughFilterShader__1setOutputPairFlags(JNIEnv*, jclass, jlong _address, jint value) {
    PassThroughFilterShader* _self = (PassThroughFilterShader*) _address;
    _self->outputPairFlags = value;
}

// PassThroughFilterShaderImpl
JNIEXPORT jint JNICALL Java_physx_support_PassThroughFilterShaderImpl__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PassThroughFilterShaderImpl);
}
JNIEXPORT jlong JNICALL Java_physx_support_PassThroughFilterShaderImpl__1PassThroughFilterShaderImpl(JNIEnv* env, jobject obj) {
    return (jlong) new PassThroughFilterShaderImpl(env, obj);
}
JNIEXPORT void JNICALL Java_physx_support_PassThroughFilterShaderImpl__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (PassThroughFilterShaderImpl*) address;
}

// PxPvd
JNIEXPORT jint JNICALL Java_physx_support_PxPvd__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxPvd);
}
JNIEXPORT jboolean JNICALL Java_physx_support_PxPvd__1connect(JNIEnv*, jclass, jlong _address, jlong transport, jlong flags) {
    physx::PxPvd* self = (physx::PxPvd*) _address;
    return (jboolean) self->connect(*((physx::PxPvdTransport*) transport), *((physx::PxPvdInstrumentationFlags*) flags));
}
JNIEXPORT void JNICALL Java_physx_support_PxPvd__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxPvd* self = (physx::PxPvd*) _address;
    self->release();
}

// PxPvdTransport
JNIEXPORT jint JNICALL Java_physx_support_PxPvdTransport__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxPvdTransport);
}
JNIEXPORT jboolean JNICALL Java_physx_support_PxPvdTransport__1connect(JNIEnv*, jclass, jlong _address) {
    physx::PxPvdTransport* self = (physx::PxPvdTransport*) _address;
    return (jboolean) self->connect();
}
JNIEXPORT jboolean JNICALL Java_physx_support_PxPvdTransport__1isConnected(JNIEnv*, jclass, jlong _address) {
    physx::PxPvdTransport* self = (physx::PxPvdTransport*) _address;
    return (jboolean) self->isConnected();
}
JNIEXPORT void JNICALL Java_physx_support_PxPvdTransport__1disconnect(JNIEnv*, jclass, jlong _address) {
    physx::PxPvdTransport* self = (physx::PxPvdTransport*) _address;
    self->disconnect();
}
JNIEXPORT void JNICALL Java_physx_support_PxPvdTransport__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxPvdTransport* self = (physx::PxPvdTransport*) _address;
    self->release();
}
JNIEXPORT void JNICALL Java_physx_support_PxPvdTransport__1flush(JNIEnv*, jclass, jlong _address) {
    physx::PxPvdTransport* self = (physx::PxPvdTransport*) _address;
    self->flush();
}

// SimplePvdTransport
JNIEXPORT jint JNICALL Java_physx_support_SimplePvdTransport__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(SimplePvdTransport);
}
JNIEXPORT void JNICALL Java_physx_support_SimplePvdTransport__1send(JNIEnv*, jclass, jlong _address, jlong inBytes, jint inLength) {
    SimplePvdTransport* self = (SimplePvdTransport*) _address;
    self->send((void*) inBytes, inLength);
}
JNIEXPORT void JNICALL Java_physx_support_SimplePvdTransport__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (SimplePvdTransport*) _address;
}

// SimplPvdTransportImpl
JNIEXPORT jint JNICALL Java_physx_support_SimplPvdTransportImpl__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(SimplPvdTransportImpl);
}
JNIEXPORT jlong JNICALL Java_physx_support_SimplPvdTransportImpl__1SimplPvdTransportImpl(JNIEnv* env, jobject obj) {
    return (jlong) new SimplPvdTransportImpl(env, obj);
}
JNIEXPORT void JNICALL Java_physx_support_SimplPvdTransportImpl__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (SimplPvdTransportImpl*) address;
}

// PxPvdInstrumentationFlags
JNIEXPORT jint JNICALL Java_physx_support_PxPvdInstrumentationFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxPvdInstrumentationFlags);
}
JNIEXPORT jlong JNICALL Java_physx_support_PxPvdInstrumentationFlags__1PxPvdInstrumentationFlags(JNIEnv*, jclass, jbyte flags) {
    return (jlong) new physx::PxPvdInstrumentationFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_support_PxPvdInstrumentationFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxPvdInstrumentationFlags* self = (physx::PxPvdInstrumentationFlags*) _address;
    return (jboolean) self->isSet((PxPvdInstrumentationFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_support_PxPvdInstrumentationFlags__1raise(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxPvdInstrumentationFlags* self = (physx::PxPvdInstrumentationFlags*) _address;
    self->raise((PxPvdInstrumentationFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_support_PxPvdInstrumentationFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxPvdInstrumentationFlags* self = (physx::PxPvdInstrumentationFlags*) _address;
    self->clear((PxPvdInstrumentationFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_support_PxPvdInstrumentationFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxPvdInstrumentationFlags*) _address;
}

// PxOmniPvd
JNIEXPORT jint JNICALL Java_physx_support_PxOmniPvd__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxOmniPvd);
}
JNIEXPORT jlong JNICALL Java_physx_support_PxOmniPvd__1getWriter(JNIEnv*, jclass, jlong _address) {
    physx::PxOmniPvd* self = (physx::PxOmniPvd*) _address;
    return (jlong) self->getWriter();
}
JNIEXPORT jlong JNICALL Java_physx_support_PxOmniPvd__1getFileWriteStream(JNIEnv*, jclass, jlong _address) {
    physx::PxOmniPvd* self = (physx::PxOmniPvd*) _address;
    return (jlong) self->getFileWriteStream();
}
JNIEXPORT jboolean JNICALL Java_physx_support_PxOmniPvd__1startSampling(JNIEnv*, jclass, jlong _address) {
    physx::PxOmniPvd* self = (physx::PxOmniPvd*) _address;
    return (jboolean) self->startSampling();
}
JNIEXPORT void JNICALL Java_physx_support_PxOmniPvd__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxOmniPvd* self = (physx::PxOmniPvd*) _address;
    self->release();
}
JNIEXPORT void JNICALL Java_physx_support_PxOmniPvd__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxOmniPvd*) _address;
}

// OmniPvdWriter
JNIEXPORT jint JNICALL Java_physx_support_OmniPvdWriter__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(OmniPvdWriter);
}
JNIEXPORT void JNICALL Java_physx_support_OmniPvdWriter__1setWriteStream(JNIEnv*, jclass, jlong _address, jlong writeStream) {
    OmniPvdWriter* self = (OmniPvdWriter*) _address;
    self->setWriteStream((OmniPvdFileWriteStream*) writeStream);
}
JNIEXPORT void JNICALL Java_physx_support_OmniPvdWriter__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (OmniPvdWriter*) _address;
}

// OmniPvdFileWriteStream
JNIEXPORT jint JNICALL Java_physx_support_OmniPvdFileWriteStream__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(OmniPvdFileWriteStream);
}
JNIEXPORT void JNICALL Java_physx_support_OmniPvdFileWriteStream__1setFileName(JNIEnv* _env, jclass, jlong _address, jstring fileName) {
    OmniPvdFileWriteStream* self = (OmniPvdFileWriteStream*) _address;
    self->setFileName(_env->GetStringUTFChars(fileName, 0));
}

// PxVisualizationParameterEnum
JNIEXPORT jint JNICALL Java_physx_support_PxVisualizationParameterEnum__1geteSCALE(JNIEnv*, jclass) {
    return PxVisualizationParameterEnum::eSCALE;
}
JNIEXPORT jint JNICALL Java_physx_support_PxVisualizationParameterEnum__1geteWORLD_1AXES(JNIEnv*, jclass) {
    return PxVisualizationParameterEnum::eWORLD_AXES;
}
JNIEXPORT jint JNICALL Java_physx_support_PxVisualizationParameterEnum__1geteBODY_1AXES(JNIEnv*, jclass) {
    return PxVisualizationParameterEnum::eBODY_AXES;
}
JNIEXPORT jint JNICALL Java_physx_support_PxVisualizationParameterEnum__1geteBODY_1MASS_1AXES(JNIEnv*, jclass) {
    return PxVisualizationParameterEnum::eBODY_MASS_AXES;
}
JNIEXPORT jint JNICALL Java_physx_support_PxVisualizationParameterEnum__1geteBODY_1LIN_1VELOCITY(JNIEnv*, jclass) {
    return PxVisualizationParameterEnum::eBODY_LIN_VELOCITY;
}
JNIEXPORT jint JNICALL Java_physx_support_PxVisualizationParameterEnum__1geteBODY_1ANG_1VELOCITY(JNIEnv*, jclass) {
    return PxVisualizationParameterEnum::eBODY_ANG_VELOCITY;
}
JNIEXPORT jint JNICALL Java_physx_support_PxVisualizationParameterEnum__1geteCONTACT_1POINT(JNIEnv*, jclass) {
    return PxVisualizationParameterEnum::eCONTACT_POINT;
}
JNIEXPORT jint JNICALL Java_physx_support_PxVisualizationParameterEnum__1geteCONTACT_1NORMAL(JNIEnv*, jclass) {
    return PxVisualizationParameterEnum::eCONTACT_NORMAL;
}
JNIEXPORT jint JNICALL Java_physx_support_PxVisualizationParameterEnum__1geteCONTACT_1ERROR(JNIEnv*, jclass) {
    return PxVisualizationParameterEnum::eCONTACT_ERROR;
}
JNIEXPORT jint JNICALL Java_physx_support_PxVisualizationParameterEnum__1geteCONTACT_1FORCE(JNIEnv*, jclass) {
    return PxVisualizationParameterEnum::eCONTACT_FORCE;
}
JNIEXPORT jint JNICALL Java_physx_support_PxVisualizationParameterEnum__1geteACTOR_1AXES(JNIEnv*, jclass) {
    return PxVisualizationParameterEnum::eACTOR_AXES;
}
JNIEXPORT jint JNICALL Java_physx_support_PxVisualizationParameterEnum__1geteCOLLISION_1AABBS(JNIEnv*, jclass) {
    return PxVisualizationParameterEnum::eCOLLISION_AABBS;
}
JNIEXPORT jint JNICALL Java_physx_support_PxVisualizationParameterEnum__1geteCOLLISION_1SHAPES(JNIEnv*, jclass) {
    return PxVisualizationParameterEnum::eCOLLISION_SHAPES;
}
JNIEXPORT jint JNICALL Java_physx_support_PxVisualizationParameterEnum__1geteCOLLISION_1AXES(JNIEnv*, jclass) {
    return PxVisualizationParameterEnum::eCOLLISION_AXES;
}
JNIEXPORT jint JNICALL Java_physx_support_PxVisualizationParameterEnum__1geteCOLLISION_1COMPOUNDS(JNIEnv*, jclass) {
    return PxVisualizationParameterEnum::eCOLLISION_COMPOUNDS;
}
JNIEXPORT jint JNICALL Java_physx_support_PxVisualizationParameterEnum__1geteCOLLISION_1FNORMALS(JNIEnv*, jclass) {
    return PxVisualizationParameterEnum::eCOLLISION_FNORMALS;
}
JNIEXPORT jint JNICALL Java_physx_support_PxVisualizationParameterEnum__1geteCOLLISION_1EDGES(JNIEnv*, jclass) {
    return PxVisualizationParameterEnum::eCOLLISION_EDGES;
}
JNIEXPORT jint JNICALL Java_physx_support_PxVisualizationParameterEnum__1geteCOLLISION_1STATIC(JNIEnv*, jclass) {
    return PxVisualizationParameterEnum::eCOLLISION_STATIC;
}
JNIEXPORT jint JNICALL Java_physx_support_PxVisualizationParameterEnum__1geteCOLLISION_1DYNAMIC(JNIEnv*, jclass) {
    return PxVisualizationParameterEnum::eCOLLISION_DYNAMIC;
}
JNIEXPORT jint JNICALL Java_physx_support_PxVisualizationParameterEnum__1geteJOINT_1LOCAL_1FRAMES(JNIEnv*, jclass) {
    return PxVisualizationParameterEnum::eJOINT_LOCAL_FRAMES;
}
JNIEXPORT jint JNICALL Java_physx_support_PxVisualizationParameterEnum__1geteJOINT_1LIMITS(JNIEnv*, jclass) {
    return PxVisualizationParameterEnum::eJOINT_LIMITS;
}
JNIEXPORT jint JNICALL Java_physx_support_PxVisualizationParameterEnum__1geteCULL_1BOX(JNIEnv*, jclass) {
    return PxVisualizationParameterEnum::eCULL_BOX;
}
JNIEXPORT jint JNICALL Java_physx_support_PxVisualizationParameterEnum__1geteMBP_1REGIONS(JNIEnv*, jclass) {
    return PxVisualizationParameterEnum::eMBP_REGIONS;
}
JNIEXPORT jint JNICALL Java_physx_support_PxVisualizationParameterEnum__1geteSIMULATION_1MESH(JNIEnv*, jclass) {
    return PxVisualizationParameterEnum::eSIMULATION_MESH;
}
JNIEXPORT jint JNICALL Java_physx_support_PxVisualizationParameterEnum__1geteSDF(JNIEnv*, jclass) {
    return PxVisualizationParameterEnum::eSDF;
}
JNIEXPORT jint JNICALL Java_physx_support_PxVisualizationParameterEnum__1geteNUM_1VALUES(JNIEnv*, jclass) {
    return PxVisualizationParameterEnum::eNUM_VALUES;
}
JNIEXPORT jint JNICALL Java_physx_support_PxVisualizationParameterEnum__1geteFORCE_1DWORD(JNIEnv*, jclass) {
    return PxVisualizationParameterEnum::eFORCE_DWORD;
}

// PxPvdInstrumentationFlagEnum
JNIEXPORT jint JNICALL Java_physx_support_PxPvdInstrumentationFlagEnum__1geteDEBUG(JNIEnv*, jclass) {
    return PxPvdInstrumentationFlagEnum::eDEBUG;
}
JNIEXPORT jint JNICALL Java_physx_support_PxPvdInstrumentationFlagEnum__1getePROFILE(JNIEnv*, jclass) {
    return PxPvdInstrumentationFlagEnum::ePROFILE;
}
JNIEXPORT jint JNICALL Java_physx_support_PxPvdInstrumentationFlagEnum__1geteMEMORY(JNIEnv*, jclass) {
    return PxPvdInstrumentationFlagEnum::eMEMORY;
}
JNIEXPORT jint JNICALL Java_physx_support_PxPvdInstrumentationFlagEnum__1geteALL(JNIEnv*, jclass) {
    return PxPvdInstrumentationFlagEnum::eALL;
}

// PxVehicleTopLevelFunctions
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTopLevelFunctions__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxVehicleTopLevelFunctions);
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleTopLevelFunctions__1InitVehicleExtension(JNIEnv*, jclass, jlong foundation) {
    return (jboolean) PxVehicleTopLevelFunctions::InitVehicleExtension(*((physx::PxFoundation*) foundation));
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTopLevelFunctions__1CloseVehicleExtension(JNIEnv*, jclass) {
    PxVehicleTopLevelFunctions::CloseVehicleExtension();
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleTopLevelFunctions__1VehicleComputeSprungMasses(JNIEnv*, jclass, jint nbSprungMasses, jlong sprungMassCoordinates, jfloat totalMass, jint gravityDirection, jlong sprungMasses) {
    return (jboolean) PxVehicleTopLevelFunctions::VehicleComputeSprungMasses(nbSprungMasses, *((Vector_PxVec3*) sprungMassCoordinates), totalMass, (PxVehicleAxesEnum) gravityDirection, *((Vector_PxReal*) sprungMasses));
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTopLevelFunctions__1VehicleUnitCylinderSweepMeshCreate(JNIEnv*, jclass, jlong vehicleFrame, jlong physics, jlong params) {
    return (jlong) PxVehicleTopLevelFunctions::VehicleUnitCylinderSweepMeshCreate(*((physx::vehicle2::PxVehicleFrame*) vehicleFrame), *((physx::PxPhysics*) physics), *((physx::PxCookingParams*) params));
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTopLevelFunctions__1VehicleUnitCylinderSweepMeshDestroy(JNIEnv*, jclass, jlong mesh) {
    PxVehicleTopLevelFunctions::VehicleUnitCylinderSweepMeshDestroy((physx::PxConvexMesh*) mesh);
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTopLevelFunctions__1getMAX_1NB_1ENGINE_1TORQUE_1CURVE_1ENTRIES(JNIEnv*, jclass) {
    return (jint) PxVehicleTopLevelFunctions::MAX_NB_ENGINE_TORQUE_CURVE_ENTRIES;
}

// PxVehicleAckermannParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleAckermannParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleAckermannParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleAckermannParams__1PxVehicleAckermannParams(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleAckermannParams();
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleAckermannParams__1isValid(JNIEnv*, jclass, jlong _address, jlong axleDesc) {
    physx::vehicle2::PxVehicleAckermannParams* self = (physx::vehicle2::PxVehicleAckermannParams*) _address;
    return (jboolean) self->isValid(*((physx::vehicle2::PxVehicleAxleDescription*) axleDesc));
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleAckermannParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    physx::vehicle2::PxVehicleAckermannParams* self = (physx::vehicle2::PxVehicleAckermannParams*) _address;
    static thread_local physx::vehicle2::PxVehicleAckermannParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleAckermannParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleAckermannParams*) _address;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleAckermannParams__1getWheelIds(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleAckermannParams* _self = (physx::vehicle2::PxVehicleAckermannParams*) _address;
    return (jint) _self->wheelIds[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleAckermannParams__1setWheelIds(JNIEnv*, jclass, jlong _address, jint _index, jint value) {
    physx::vehicle2::PxVehicleAckermannParams* _self = (physx::vehicle2::PxVehicleAckermannParams*) _address;
    _self->wheelIds[_index] = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleAckermannParams__1getWheelBase(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleAckermannParams* _self = (physx::vehicle2::PxVehicleAckermannParams*) _address;
    return (jfloat) _self->wheelBase;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleAckermannParams__1setWheelBase(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleAckermannParams* _self = (physx::vehicle2::PxVehicleAckermannParams*) _address;
    _self->wheelBase = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleAckermannParams__1getTrackWidth(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleAckermannParams* _self = (physx::vehicle2::PxVehicleAckermannParams*) _address;
    return (jfloat) _self->trackWidth;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleAckermannParams__1setTrackWidth(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleAckermannParams* _self = (physx::vehicle2::PxVehicleAckermannParams*) _address;
    _self->trackWidth = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleAckermannParams__1getStrength(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleAckermannParams* _self = (physx::vehicle2::PxVehicleAckermannParams*) _address;
    return (jfloat) _self->strength;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleAckermannParams__1setStrength(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleAckermannParams* _self = (physx::vehicle2::PxVehicleAckermannParams*) _address;
    _self->strength = value;
}

// PxVehicleAntiRollForceParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleAntiRollForceParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleAntiRollForceParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleAntiRollForceParams__1PxVehicleAntiRollForceParams(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleAntiRollForceParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleAntiRollForceParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    physx::vehicle2::PxVehicleAntiRollForceParams* self = (physx::vehicle2::PxVehicleAntiRollForceParams*) _address;
    static thread_local physx::vehicle2::PxVehicleAntiRollForceParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleAntiRollForceParams__1isValid(JNIEnv*, jclass, jlong _address, jlong axleDesc) {
    physx::vehicle2::PxVehicleAntiRollForceParams* self = (physx::vehicle2::PxVehicleAntiRollForceParams*) _address;
    return (jboolean) self->isValid(*((physx::vehicle2::PxVehicleAxleDescription*) axleDesc));
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleAntiRollForceParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleAntiRollForceParams*) _address;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleAntiRollForceParams__1getWheel0(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleAntiRollForceParams* _self = (physx::vehicle2::PxVehicleAntiRollForceParams*) _address;
    return (jint) _self->wheel0;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleAntiRollForceParams__1setWheel0(JNIEnv*, jclass, jlong _address, jint value) {
    physx::vehicle2::PxVehicleAntiRollForceParams* _self = (physx::vehicle2::PxVehicleAntiRollForceParams*) _address;
    _self->wheel0 = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleAntiRollForceParams__1getWheel1(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleAntiRollForceParams* _self = (physx::vehicle2::PxVehicleAntiRollForceParams*) _address;
    return (jint) _self->wheel1;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleAntiRollForceParams__1setWheel1(JNIEnv*, jclass, jlong _address, jint value) {
    physx::vehicle2::PxVehicleAntiRollForceParams* _self = (physx::vehicle2::PxVehicleAntiRollForceParams*) _address;
    _self->wheel1 = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleAntiRollForceParams__1getStiffness(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleAntiRollForceParams* _self = (physx::vehicle2::PxVehicleAntiRollForceParams*) _address;
    return (jfloat) _self->stiffness;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleAntiRollForceParams__1setStiffness(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleAntiRollForceParams* _self = (physx::vehicle2::PxVehicleAntiRollForceParams*) _address;
    _self->stiffness = value;
}

// PxVehicleAntiRollTorque
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleAntiRollTorque__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleAntiRollTorque);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleAntiRollTorque__1PxVehicleAntiRollTorque(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleAntiRollTorque();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleAntiRollTorque__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleAntiRollTorque* self = (physx::vehicle2::PxVehicleAntiRollTorque*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleAntiRollTorque__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleAntiRollTorque*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleAntiRollTorque__1getAntiRollTorque(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleAntiRollTorque* _self = (physx::vehicle2::PxVehicleAntiRollTorque*) _address;
    return (jlong) &_self->antiRollTorque;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleAntiRollTorque__1setAntiRollTorque(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleAntiRollTorque* _self = (physx::vehicle2::PxVehicleAntiRollTorque*) _address;
    _self->antiRollTorque = *((physx::PxVec3*) value);
}

// PxVehicleAutoboxParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleAutoboxParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleAutoboxParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleAutoboxParams__1_1placement_1new_1PxVehicleAutoboxParams(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::vehicle2::PxVehicleAutoboxParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleAutoboxParams__1PxVehicleAutoboxParams(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleAutoboxParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleAutoboxParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    physx::vehicle2::PxVehicleAutoboxParams* self = (physx::vehicle2::PxVehicleAutoboxParams*) _address;
    static thread_local physx::vehicle2::PxVehicleAutoboxParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleAutoboxParams__1isValid(JNIEnv*, jclass, jlong _address, jlong gearboxParams) {
    physx::vehicle2::PxVehicleAutoboxParams* self = (physx::vehicle2::PxVehicleAutoboxParams*) _address;
    return (jboolean) self->isValid(*((physx::vehicle2::PxVehicleGearboxParams*) gearboxParams));
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleAutoboxParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleAutoboxParams*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleAutoboxParams__1getUpRatios(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleAutoboxParams* _self = (physx::vehicle2::PxVehicleAutoboxParams*) _address;
    return (jfloat) _self->upRatios[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleAutoboxParams__1setUpRatios(JNIEnv*, jclass, jlong _address, jint _index, jfloat value) {
    physx::vehicle2::PxVehicleAutoboxParams* _self = (physx::vehicle2::PxVehicleAutoboxParams*) _address;
    _self->upRatios[_index] = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleAutoboxParams__1getDownRatios(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleAutoboxParams* _self = (physx::vehicle2::PxVehicleAutoboxParams*) _address;
    return (jfloat) _self->downRatios[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleAutoboxParams__1setDownRatios(JNIEnv*, jclass, jlong _address, jint _index, jfloat value) {
    physx::vehicle2::PxVehicleAutoboxParams* _self = (physx::vehicle2::PxVehicleAutoboxParams*) _address;
    _self->downRatios[_index] = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleAutoboxParams__1getLatency(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleAutoboxParams* _self = (physx::vehicle2::PxVehicleAutoboxParams*) _address;
    return (jfloat) _self->latency;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleAutoboxParams__1setLatency(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleAutoboxParams* _self = (physx::vehicle2::PxVehicleAutoboxParams*) _address;
    _self->latency = value;
}

// PxVehicleAutoboxState
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleAutoboxState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleAutoboxState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleAutoboxState__1PxVehicleAutoboxState(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleAutoboxState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleAutoboxState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleAutoboxState* self = (physx::vehicle2::PxVehicleAutoboxState*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleAutoboxState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleAutoboxState*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleAutoboxState__1getTimeSinceLastShift(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleAutoboxState* _self = (physx::vehicle2::PxVehicleAutoboxState*) _address;
    return (jfloat) _self->timeSinceLastShift;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleAutoboxState__1setTimeSinceLastShift(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleAutoboxState* _self = (physx::vehicle2::PxVehicleAutoboxState*) _address;
    _self->timeSinceLastShift = value;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleAutoboxState__1getActiveAutoboxGearShift(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleAutoboxState* _self = (physx::vehicle2::PxVehicleAutoboxState*) _address;
    return (jboolean) _self->activeAutoboxGearShift;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleAutoboxState__1setActiveAutoboxGearShift(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::vehicle2::PxVehicleAutoboxState* _self = (physx::vehicle2::PxVehicleAutoboxState*) _address;
    _self->activeAutoboxGearShift = value;
}

// PxVehicleAxleDescription
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleAxleDescription__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleAxleDescription);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleAxleDescription__1PxVehicleAxleDescription(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleAxleDescription();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleAxleDescription__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleAxleDescription* self = (physx::vehicle2::PxVehicleAxleDescription*) _address;
    self->setToDefault();
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleAxleDescription__1getNbWheelsOnAxle(JNIEnv*, jclass, jlong _address, jint i) {
    physx::vehicle2::PxVehicleAxleDescription* self = (physx::vehicle2::PxVehicleAxleDescription*) _address;
    return (jint) self->getNbWheelsOnAxle(i);
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleAxleDescription__1getWheelOnAxle(JNIEnv*, jclass, jlong _address, jint j, jint i) {
    physx::vehicle2::PxVehicleAxleDescription* self = (physx::vehicle2::PxVehicleAxleDescription*) _address;
    return (jint) self->getWheelOnAxle(j, i);
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleAxleDescription__1getAxle(JNIEnv*, jclass, jlong _address, jint wheelId) {
    physx::vehicle2::PxVehicleAxleDescription* self = (physx::vehicle2::PxVehicleAxleDescription*) _address;
    return (jint) self->getAxle(wheelId);
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleAxleDescription__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleAxleDescription* self = (physx::vehicle2::PxVehicleAxleDescription*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleAxleDescription__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleAxleDescription*) _address;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleAxleDescription__1getNbAxles(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleAxleDescription* _self = (physx::vehicle2::PxVehicleAxleDescription*) _address;
    return (jint) _self->nbAxles;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleAxleDescription__1setNbAxles(JNIEnv*, jclass, jlong _address, jint value) {
    physx::vehicle2::PxVehicleAxleDescription* _self = (physx::vehicle2::PxVehicleAxleDescription*) _address;
    _self->nbAxles = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleAxleDescription__1getNbWheelsPerAxle(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleAxleDescription* _self = (physx::vehicle2::PxVehicleAxleDescription*) _address;
    return (jint) _self->nbWheelsPerAxle[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleAxleDescription__1setNbWheelsPerAxle(JNIEnv*, jclass, jlong _address, jint _index, jint value) {
    physx::vehicle2::PxVehicleAxleDescription* _self = (physx::vehicle2::PxVehicleAxleDescription*) _address;
    _self->nbWheelsPerAxle[_index] = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleAxleDescription__1getAxleToWheelIds(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleAxleDescription* _self = (physx::vehicle2::PxVehicleAxleDescription*) _address;
    return (jint) _self->axleToWheelIds[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleAxleDescription__1setAxleToWheelIds(JNIEnv*, jclass, jlong _address, jint _index, jint value) {
    physx::vehicle2::PxVehicleAxleDescription* _self = (physx::vehicle2::PxVehicleAxleDescription*) _address;
    _self->axleToWheelIds[_index] = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleAxleDescription__1getWheelIdsInAxleOrder(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleAxleDescription* _self = (physx::vehicle2::PxVehicleAxleDescription*) _address;
    return (jint) _self->wheelIdsInAxleOrder[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleAxleDescription__1setWheelIdsInAxleOrder(JNIEnv*, jclass, jlong _address, jint _index, jint value) {
    physx::vehicle2::PxVehicleAxleDescription* _self = (physx::vehicle2::PxVehicleAxleDescription*) _address;
    _self->wheelIdsInAxleOrder[_index] = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleAxleDescription__1getNbWheels(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleAxleDescription* _self = (physx::vehicle2::PxVehicleAxleDescription*) _address;
    return (jint) _self->nbWheels;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleAxleDescription__1setNbWheels(JNIEnv*, jclass, jlong _address, jint value) {
    physx::vehicle2::PxVehicleAxleDescription* _self = (physx::vehicle2::PxVehicleAxleDescription*) _address;
    _self->nbWheels = value;
}

// PxVehicleBrakeCommandResponseParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleBrakeCommandResponseParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleBrakeCommandResponseParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleBrakeCommandResponseParams__1PxVehicleBrakeCommandResponseParams(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleBrakeCommandResponseParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleBrakeCommandResponseParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    physx::vehicle2::PxVehicleBrakeCommandResponseParams* self = (physx::vehicle2::PxVehicleBrakeCommandResponseParams*) _address;
    static thread_local physx::vehicle2::PxVehicleBrakeCommandResponseParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleBrakeCommandResponseParams__1isValid(JNIEnv*, jclass, jlong _address, jlong axleDesc) {
    physx::vehicle2::PxVehicleBrakeCommandResponseParams* self = (physx::vehicle2::PxVehicleBrakeCommandResponseParams*) _address;
    return (jboolean) self->isValid(*((physx::vehicle2::PxVehicleAxleDescription*) axleDesc));
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleBrakeCommandResponseParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleBrakeCommandResponseParams*) _address;
}

// PxVehicleClutchCommandResponseParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleClutchCommandResponseParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleClutchCommandResponseParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleClutchCommandResponseParams__1_1placement_1new_1PxVehicleClutchCommandResponseParams(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::vehicle2::PxVehicleClutchCommandResponseParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleClutchCommandResponseParams__1PxVehicleClutchCommandResponseParams(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleClutchCommandResponseParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleClutchCommandResponseParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    physx::vehicle2::PxVehicleClutchCommandResponseParams* self = (physx::vehicle2::PxVehicleClutchCommandResponseParams*) _address;
    static thread_local physx::vehicle2::PxVehicleClutchCommandResponseParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleClutchCommandResponseParams__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleClutchCommandResponseParams* self = (physx::vehicle2::PxVehicleClutchCommandResponseParams*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleClutchCommandResponseParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleClutchCommandResponseParams*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleClutchCommandResponseParams__1getMaxResponse(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleClutchCommandResponseParams* _self = (physx::vehicle2::PxVehicleClutchCommandResponseParams*) _address;
    return (jfloat) _self->maxResponse;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleClutchCommandResponseParams__1setMaxResponse(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleClutchCommandResponseParams* _self = (physx::vehicle2::PxVehicleClutchCommandResponseParams*) _address;
    _self->maxResponse = value;
}

// PxVehicleClutchCommandResponseState
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleClutchCommandResponseState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleClutchCommandResponseState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleClutchCommandResponseState__1PxVehicleClutchCommandResponseState(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleClutchCommandResponseState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleClutchCommandResponseState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleClutchCommandResponseState* self = (physx::vehicle2::PxVehicleClutchCommandResponseState*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleClutchCommandResponseState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleClutchCommandResponseState*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleClutchCommandResponseState__1getNormalisedCommandResponse(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleClutchCommandResponseState* _self = (physx::vehicle2::PxVehicleClutchCommandResponseState*) _address;
    return (jfloat) _self->normalisedCommandResponse;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleClutchCommandResponseState__1setNormalisedCommandResponse(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleClutchCommandResponseState* _self = (physx::vehicle2::PxVehicleClutchCommandResponseState*) _address;
    _self->normalisedCommandResponse = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleClutchCommandResponseState__1getCommandResponse(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleClutchCommandResponseState* _self = (physx::vehicle2::PxVehicleClutchCommandResponseState*) _address;
    return (jfloat) _self->commandResponse;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleClutchCommandResponseState__1setCommandResponse(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleClutchCommandResponseState* _self = (physx::vehicle2::PxVehicleClutchCommandResponseState*) _address;
    _self->commandResponse = value;
}

// PxVehicleClutchParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleClutchParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleClutchParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleClutchParams__1_1placement_1new_1PxVehicleClutchParams(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::vehicle2::PxVehicleClutchParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleClutchParams__1PxVehicleClutchParams(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleClutchParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleClutchParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    physx::vehicle2::PxVehicleClutchParams* self = (physx::vehicle2::PxVehicleClutchParams*) _address;
    static thread_local physx::vehicle2::PxVehicleClutchParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleClutchParams__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleClutchParams* self = (physx::vehicle2::PxVehicleClutchParams*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleClutchParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleClutchParams*) _address;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleClutchParams__1getAccuracyMode(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleClutchParams* _self = (physx::vehicle2::PxVehicleClutchParams*) _address;
    return (jint) _self->accuracyMode;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleClutchParams__1setAccuracyMode(JNIEnv*, jclass, jlong _address, jint value) {
    physx::vehicle2::PxVehicleClutchParams* _self = (physx::vehicle2::PxVehicleClutchParams*) _address;
    _self->accuracyMode = (PxVehicleClutchAccuracyModeEnum) value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleClutchParams__1getEstimateIterations(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleClutchParams* _self = (physx::vehicle2::PxVehicleClutchParams*) _address;
    return (jint) _self->estimateIterations;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleClutchParams__1setEstimateIterations(JNIEnv*, jclass, jlong _address, jint value) {
    physx::vehicle2::PxVehicleClutchParams* _self = (physx::vehicle2::PxVehicleClutchParams*) _address;
    _self->estimateIterations = value;
}

// PxVehicleClutchSlipState
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleClutchSlipState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleClutchSlipState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleClutchSlipState__1PxVehicleClutchSlipState(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleClutchSlipState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleClutchSlipState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleClutchSlipState* self = (physx::vehicle2::PxVehicleClutchSlipState*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleClutchSlipState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleClutchSlipState*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleClutchSlipState__1getClutchSlip(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleClutchSlipState* _self = (physx::vehicle2::PxVehicleClutchSlipState*) _address;
    return (jfloat) _self->clutchSlip;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleClutchSlipState__1setClutchSlip(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleClutchSlipState* _self = (physx::vehicle2::PxVehicleClutchSlipState*) _address;
    _self->clutchSlip = value;
}

// PxVehicleCommandNonLinearResponseParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleCommandNonLinearResponseParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleCommandNonLinearResponseParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleCommandNonLinearResponseParams__1PxVehicleCommandNonLinearResponseParams(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleCommandNonLinearResponseParams();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleCommandNonLinearResponseParams__1clear(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleCommandNonLinearResponseParams* self = (physx::vehicle2::PxVehicleCommandNonLinearResponseParams*) _address;
    self->clear();
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleCommandNonLinearResponseParams__1addResponse(JNIEnv*, jclass, jlong _address, jlong commandValueSpeedResponses) {
    physx::vehicle2::PxVehicleCommandNonLinearResponseParams* self = (physx::vehicle2::PxVehicleCommandNonLinearResponseParams*) _address;
    return (jboolean) self->addResponse(*((physx::vehicle2::PxVehicleCommandValueResponseTable*) commandValueSpeedResponses));
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleCommandNonLinearResponseParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleCommandNonLinearResponseParams*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleCommandNonLinearResponseParams__1getSpeedResponses(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleCommandNonLinearResponseParams* _self = (physx::vehicle2::PxVehicleCommandNonLinearResponseParams*) _address;
    return (jfloat) _self->speedResponses[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleCommandNonLinearResponseParams__1setSpeedResponses(JNIEnv*, jclass, jlong _address, jint _index, jfloat value) {
    physx::vehicle2::PxVehicleCommandNonLinearResponseParams* _self = (physx::vehicle2::PxVehicleCommandNonLinearResponseParams*) _address;
    _self->speedResponses[_index] = value;
}
JNIEXPORT jshort JNICALL Java_physx_vehicle2_PxVehicleCommandNonLinearResponseParams__1getNbSpeedResponses(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleCommandNonLinearResponseParams* _self = (physx::vehicle2::PxVehicleCommandNonLinearResponseParams*) _address;
    return (jshort) _self->nbSpeedResponses;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleCommandNonLinearResponseParams__1setNbSpeedResponses(JNIEnv*, jclass, jlong _address, jshort value) {
    physx::vehicle2::PxVehicleCommandNonLinearResponseParams* _self = (physx::vehicle2::PxVehicleCommandNonLinearResponseParams*) _address;
    _self->nbSpeedResponses = value;
}
JNIEXPORT jshort JNICALL Java_physx_vehicle2_PxVehicleCommandNonLinearResponseParams__1getSpeedResponsesPerCommandValue(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleCommandNonLinearResponseParams* _self = (physx::vehicle2::PxVehicleCommandNonLinearResponseParams*) _address;
    return (jshort) _self->speedResponsesPerCommandValue[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleCommandNonLinearResponseParams__1setSpeedResponsesPerCommandValue(JNIEnv*, jclass, jlong _address, jint _index, jshort value) {
    physx::vehicle2::PxVehicleCommandNonLinearResponseParams* _self = (physx::vehicle2::PxVehicleCommandNonLinearResponseParams*) _address;
    _self->speedResponsesPerCommandValue[_index] = value;
}
JNIEXPORT jshort JNICALL Java_physx_vehicle2_PxVehicleCommandNonLinearResponseParams__1getNbSpeedRenponsesPerCommandValue(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleCommandNonLinearResponseParams* _self = (physx::vehicle2::PxVehicleCommandNonLinearResponseParams*) _address;
    return (jshort) _self->nbSpeedRenponsesPerCommandValue[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleCommandNonLinearResponseParams__1setNbSpeedRenponsesPerCommandValue(JNIEnv*, jclass, jlong _address, jint _index, jshort value) {
    physx::vehicle2::PxVehicleCommandNonLinearResponseParams* _self = (physx::vehicle2::PxVehicleCommandNonLinearResponseParams*) _address;
    _self->nbSpeedRenponsesPerCommandValue[_index] = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleCommandNonLinearResponseParams__1getCommandValues(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleCommandNonLinearResponseParams* _self = (physx::vehicle2::PxVehicleCommandNonLinearResponseParams*) _address;
    return (jfloat) _self->commandValues[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleCommandNonLinearResponseParams__1setCommandValues(JNIEnv*, jclass, jlong _address, jint _index, jfloat value) {
    physx::vehicle2::PxVehicleCommandNonLinearResponseParams* _self = (physx::vehicle2::PxVehicleCommandNonLinearResponseParams*) _address;
    _self->commandValues[_index] = value;
}
JNIEXPORT jshort JNICALL Java_physx_vehicle2_PxVehicleCommandNonLinearResponseParams__1getNbCommandValues(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleCommandNonLinearResponseParams* _self = (physx::vehicle2::PxVehicleCommandNonLinearResponseParams*) _address;
    return (jshort) _self->nbCommandValues;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleCommandNonLinearResponseParams__1setNbCommandValues(JNIEnv*, jclass, jlong _address, jshort value) {
    physx::vehicle2::PxVehicleCommandNonLinearResponseParams* _self = (physx::vehicle2::PxVehicleCommandNonLinearResponseParams*) _address;
    _self->nbCommandValues = value;
}

// PxVehicleCommandResponseParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleCommandResponseParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleCommandResponseParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleCommandResponseParams__1PxVehicleCommandResponseParams(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleCommandResponseParams();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleCommandResponseParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleCommandResponseParams*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleCommandResponseParams__1getNonlinearResponse(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleCommandResponseParams* _self = (physx::vehicle2::PxVehicleCommandResponseParams*) _address;
    return (jlong) &_self->nonlinearResponse;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleCommandResponseParams__1setNonlinearResponse(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleCommandResponseParams* _self = (physx::vehicle2::PxVehicleCommandResponseParams*) _address;
    _self->nonlinearResponse = *((physx::vehicle2::PxVehicleCommandNonLinearResponseParams*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleCommandResponseParams__1getWheelResponseMultipliers(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleCommandResponseParams* _self = (physx::vehicle2::PxVehicleCommandResponseParams*) _address;
    return (jfloat) _self->wheelResponseMultipliers[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleCommandResponseParams__1setWheelResponseMultipliers(JNIEnv*, jclass, jlong _address, jint _index, jfloat value) {
    physx::vehicle2::PxVehicleCommandResponseParams* _self = (physx::vehicle2::PxVehicleCommandResponseParams*) _address;
    _self->wheelResponseMultipliers[_index] = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleCommandResponseParams__1getMaxResponse(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleCommandResponseParams* _self = (physx::vehicle2::PxVehicleCommandResponseParams*) _address;
    return (jfloat) _self->maxResponse;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleCommandResponseParams__1setMaxResponse(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleCommandResponseParams* _self = (physx::vehicle2::PxVehicleCommandResponseParams*) _address;
    _self->maxResponse = value;
}

// PxVehicleCommandState
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleCommandState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleCommandState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleCommandState__1PxVehicleCommandState(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleCommandState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleCommandState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleCommandState* self = (physx::vehicle2::PxVehicleCommandState*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleCommandState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleCommandState*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleCommandState__1getBrakes(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleCommandState* _self = (physx::vehicle2::PxVehicleCommandState*) _address;
    return (jfloat) _self->brakes[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleCommandState__1setBrakes(JNIEnv*, jclass, jlong _address, jint _index, jfloat value) {
    physx::vehicle2::PxVehicleCommandState* _self = (physx::vehicle2::PxVehicleCommandState*) _address;
    _self->brakes[_index] = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleCommandState__1getNbBrakes(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleCommandState* _self = (physx::vehicle2::PxVehicleCommandState*) _address;
    return (jint) _self->nbBrakes;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleCommandState__1setNbBrakes(JNIEnv*, jclass, jlong _address, jint value) {
    physx::vehicle2::PxVehicleCommandState* _self = (physx::vehicle2::PxVehicleCommandState*) _address;
    _self->nbBrakes = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleCommandState__1getThrottle(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleCommandState* _self = (physx::vehicle2::PxVehicleCommandState*) _address;
    return (jfloat) _self->throttle;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleCommandState__1setThrottle(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleCommandState* _self = (physx::vehicle2::PxVehicleCommandState*) _address;
    _self->throttle = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleCommandState__1getSteer(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleCommandState* _self = (physx::vehicle2::PxVehicleCommandState*) _address;
    return (jfloat) _self->steer;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleCommandState__1setSteer(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleCommandState* _self = (physx::vehicle2::PxVehicleCommandState*) _address;
    _self->steer = value;
}

// PxVehicleCommandValueResponseTable
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleCommandValueResponseTable__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleCommandValueResponseTable);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleCommandValueResponseTable__1PxVehicleCommandValueResponseTable(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleCommandValueResponseTable();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleCommandValueResponseTable__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleCommandValueResponseTable*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleCommandValueResponseTable__1getCommandValue(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleCommandValueResponseTable* _self = (physx::vehicle2::PxVehicleCommandValueResponseTable*) _address;
    return (jfloat) _self->commandValue;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleCommandValueResponseTable__1setCommandValue(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleCommandValueResponseTable* _self = (physx::vehicle2::PxVehicleCommandValueResponseTable*) _address;
    _self->commandValue = value;
}

// PxVehicleComponent
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleComponent__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleComponent);
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleComponent__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleComponent*) _address;
}

// PxVehicleComponentSequence
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleComponentSequence__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleComponentSequence);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleComponentSequence__1PxVehicleComponentSequence(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleComponentSequence();
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleComponentSequence__1add(JNIEnv*, jclass, jlong _address, jlong component) {
    physx::vehicle2::PxVehicleComponentSequence* self = (physx::vehicle2::PxVehicleComponentSequence*) _address;
    return (jboolean) self->add((physx::vehicle2::PxVehicleComponent*) component);
}
JNIEXPORT jbyte JNICALL Java_physx_vehicle2_PxVehicleComponentSequence__1beginSubstepGroup__J(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleComponentSequence* self = (physx::vehicle2::PxVehicleComponentSequence*) _address;
    return (jbyte) self->beginSubstepGroup();
}
JNIEXPORT jbyte JNICALL Java_physx_vehicle2_PxVehicleComponentSequence__1beginSubstepGroup__JB(JNIEnv*, jclass, jlong _address, jbyte nbSubSteps) {
    physx::vehicle2::PxVehicleComponentSequence* self = (physx::vehicle2::PxVehicleComponentSequence*) _address;
    return (jbyte) self->beginSubstepGroup(nbSubSteps);
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleComponentSequence__1endSubstepGroup(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleComponentSequence* self = (physx::vehicle2::PxVehicleComponentSequence*) _address;
    self->endSubstepGroup();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleComponentSequence__1setSubsteps(JNIEnv*, jclass, jlong _address, jbyte subGroupHandle, jbyte nbSteps) {
    physx::vehicle2::PxVehicleComponentSequence* self = (physx::vehicle2::PxVehicleComponentSequence*) _address;
    self->setSubsteps(subGroupHandle, nbSteps);
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleComponentSequence__1update(JNIEnv*, jclass, jlong _address, jfloat dt, jlong context) {
    physx::vehicle2::PxVehicleComponentSequence* self = (physx::vehicle2::PxVehicleComponentSequence*) _address;
    self->update(dt, *((physx::vehicle2::PxVehicleSimulationContext*) context));
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleComponentSequence__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleComponentSequence*) _address;
}

// PxVehicleConstraintConnector
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleConstraintConnector__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleConstraintConnector);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleConstraintConnector__1PxVehicleConstraintConnector__(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleConstraintConnector();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleConstraintConnector__1PxVehicleConstraintConnector__J(JNIEnv*, jclass, jlong vehicleConstraintState) {
    return (jlong) new physx::vehicle2::PxVehicleConstraintConnector((physx::vehicle2::PxVehiclePhysXConstraintState*) vehicleConstraintState);
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleConstraintConnector__1setConstraintState(JNIEnv*, jclass, jlong _address, jlong constraintState) {
    physx::vehicle2::PxVehicleConstraintConnector* self = (physx::vehicle2::PxVehicleConstraintConnector*) _address;
    self->setConstraintState((physx::vehicle2::PxVehiclePhysXConstraintState*) constraintState);
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleConstraintConnector__1getConstantBlock(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleConstraintConnector* self = (physx::vehicle2::PxVehicleConstraintConnector*) _address;
    self->getConstantBlock();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleConstraintConnector__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleConstraintConnector*) _address;
}

// PxVehicleDifferentialState
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleDifferentialState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleDifferentialState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleDifferentialState__1PxVehicleDifferentialState(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleDifferentialState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleDifferentialState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleDifferentialState* self = (physx::vehicle2::PxVehicleDifferentialState*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleDifferentialState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleDifferentialState*) _address;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleDifferentialState__1getConnectedWheels(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleDifferentialState* _self = (physx::vehicle2::PxVehicleDifferentialState*) _address;
    return (jint) _self->connectedWheels[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleDifferentialState__1setConnectedWheels(JNIEnv*, jclass, jlong _address, jint _index, jint value) {
    physx::vehicle2::PxVehicleDifferentialState* _self = (physx::vehicle2::PxVehicleDifferentialState*) _address;
    _self->connectedWheels[_index] = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleDifferentialState__1getNbConnectedWheels(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleDifferentialState* _self = (physx::vehicle2::PxVehicleDifferentialState*) _address;
    return (jint) _self->nbConnectedWheels;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleDifferentialState__1setNbConnectedWheels(JNIEnv*, jclass, jlong _address, jint value) {
    physx::vehicle2::PxVehicleDifferentialState* _self = (physx::vehicle2::PxVehicleDifferentialState*) _address;
    _self->nbConnectedWheels = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleDifferentialState__1getTorqueRatiosAllWheels(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleDifferentialState* _self = (physx::vehicle2::PxVehicleDifferentialState*) _address;
    return (jfloat) _self->torqueRatiosAllWheels[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleDifferentialState__1setTorqueRatiosAllWheels(JNIEnv*, jclass, jlong _address, jint _index, jfloat value) {
    physx::vehicle2::PxVehicleDifferentialState* _self = (physx::vehicle2::PxVehicleDifferentialState*) _address;
    _self->torqueRatiosAllWheels[_index] = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleDifferentialState__1getAveWheelSpeedContributionAllWheels(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleDifferentialState* _self = (physx::vehicle2::PxVehicleDifferentialState*) _address;
    return (jfloat) _self->aveWheelSpeedContributionAllWheels[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleDifferentialState__1setAveWheelSpeedContributionAllWheels(JNIEnv*, jclass, jlong _address, jint _index, jfloat value) {
    physx::vehicle2::PxVehicleDifferentialState* _self = (physx::vehicle2::PxVehicleDifferentialState*) _address;
    _self->aveWheelSpeedContributionAllWheels[_index] = value;
}

// PxVehicleDirectDriveThrottleCommandResponseParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleDirectDriveThrottleCommandResponseParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleDirectDriveThrottleCommandResponseParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleDirectDriveThrottleCommandResponseParams__1PxVehicleDirectDriveThrottleCommandResponseParams(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleDirectDriveThrottleCommandResponseParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleDirectDriveThrottleCommandResponseParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    physx::vehicle2::PxVehicleDirectDriveThrottleCommandResponseParams* self = (physx::vehicle2::PxVehicleDirectDriveThrottleCommandResponseParams*) _address;
    static thread_local physx::vehicle2::PxVehicleDirectDriveThrottleCommandResponseParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleDirectDriveThrottleCommandResponseParams__1isValid(JNIEnv*, jclass, jlong _address, jlong axleDesc) {
    physx::vehicle2::PxVehicleDirectDriveThrottleCommandResponseParams* self = (physx::vehicle2::PxVehicleDirectDriveThrottleCommandResponseParams*) _address;
    return (jboolean) self->isValid(*((physx::vehicle2::PxVehicleAxleDescription*) axleDesc));
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleDirectDriveThrottleCommandResponseParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleDirectDriveThrottleCommandResponseParams*) _address;
}

// PxVehicleDirectDriveTransmissionCommandState
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleDirectDriveTransmissionCommandState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleDirectDriveTransmissionCommandState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleDirectDriveTransmissionCommandState__1PxVehicleDirectDriveTransmissionCommandState(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleDirectDriveTransmissionCommandState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleDirectDriveTransmissionCommandState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleDirectDriveTransmissionCommandState* self = (physx::vehicle2::PxVehicleDirectDriveTransmissionCommandState*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleDirectDriveTransmissionCommandState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleDirectDriveTransmissionCommandState*) _address;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleDirectDriveTransmissionCommandState__1getGear(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleDirectDriveTransmissionCommandState* _self = (physx::vehicle2::PxVehicleDirectDriveTransmissionCommandState*) _address;
    return (jint) _self->gear;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleDirectDriveTransmissionCommandState__1setGear(JNIEnv*, jclass, jlong _address, jint value) {
    physx::vehicle2::PxVehicleDirectDriveTransmissionCommandState* _self = (physx::vehicle2::PxVehicleDirectDriveTransmissionCommandState*) _address;
    _self->gear = (PxVehicleDirectDriveTransmissionCommandStateEnum) value;
}

// PxVehicleEngineDriveThrottleCommandResponseState
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleEngineDriveThrottleCommandResponseState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleEngineDriveThrottleCommandResponseState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleEngineDriveThrottleCommandResponseState__1PxVehicleEngineDriveThrottleCommandResponseState(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleEngineDriveThrottleCommandResponseState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleEngineDriveThrottleCommandResponseState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleEngineDriveThrottleCommandResponseState* self = (physx::vehicle2::PxVehicleEngineDriveThrottleCommandResponseState*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleEngineDriveThrottleCommandResponseState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleEngineDriveThrottleCommandResponseState*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleEngineDriveThrottleCommandResponseState__1getCommandResponse(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleEngineDriveThrottleCommandResponseState* _self = (physx::vehicle2::PxVehicleEngineDriveThrottleCommandResponseState*) _address;
    return (jfloat) _self->commandResponse;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleEngineDriveThrottleCommandResponseState__1setCommandResponse(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleEngineDriveThrottleCommandResponseState* _self = (physx::vehicle2::PxVehicleEngineDriveThrottleCommandResponseState*) _address;
    _self->commandResponse = value;
}

// PxVehicleEngineDriveTransmissionCommandState
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleEngineDriveTransmissionCommandState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleEngineDriveTransmissionCommandState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleEngineDriveTransmissionCommandState__1PxVehicleEngineDriveTransmissionCommandState(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleEngineDriveTransmissionCommandState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleEngineDriveTransmissionCommandState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleEngineDriveTransmissionCommandState* self = (physx::vehicle2::PxVehicleEngineDriveTransmissionCommandState*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleEngineDriveTransmissionCommandState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleEngineDriveTransmissionCommandState*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleEngineDriveTransmissionCommandState__1getClutch(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleEngineDriveTransmissionCommandState* _self = (physx::vehicle2::PxVehicleEngineDriveTransmissionCommandState*) _address;
    return (jfloat) _self->clutch;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleEngineDriveTransmissionCommandState__1setClutch(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleEngineDriveTransmissionCommandState* _self = (physx::vehicle2::PxVehicleEngineDriveTransmissionCommandState*) _address;
    _self->clutch = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleEngineDriveTransmissionCommandState__1getTargetGear(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleEngineDriveTransmissionCommandState* _self = (physx::vehicle2::PxVehicleEngineDriveTransmissionCommandState*) _address;
    return (jint) _self->targetGear;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleEngineDriveTransmissionCommandState__1setTargetGear(JNIEnv*, jclass, jlong _address, jint value) {
    physx::vehicle2::PxVehicleEngineDriveTransmissionCommandState* _self = (physx::vehicle2::PxVehicleEngineDriveTransmissionCommandState*) _address;
    _self->targetGear = value;
}

// PxVehicleEngineParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleEngineParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleEngineParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleEngineParams__1_1placement_1new_1PxVehicleEngineParams(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::vehicle2::PxVehicleEngineParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleEngineParams__1PxVehicleEngineParams(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleEngineParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleEngineParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    physx::vehicle2::PxVehicleEngineParams* self = (physx::vehicle2::PxVehicleEngineParams*) _address;
    static thread_local physx::vehicle2::PxVehicleEngineParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleEngineParams__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleEngineParams* self = (physx::vehicle2::PxVehicleEngineParams*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleEngineParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleEngineParams*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleEngineParams__1getTorqueCurve(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleEngineParams* _self = (physx::vehicle2::PxVehicleEngineParams*) _address;
    return (jlong) &_self->torqueCurve;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleEngineParams__1setTorqueCurve(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleEngineParams* _self = (physx::vehicle2::PxVehicleEngineParams*) _address;
    _self->torqueCurve = *((PxVehicleTorqueCurveLookupTable*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleEngineParams__1getMoi(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleEngineParams* _self = (physx::vehicle2::PxVehicleEngineParams*) _address;
    return (jfloat) _self->moi;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleEngineParams__1setMoi(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleEngineParams* _self = (physx::vehicle2::PxVehicleEngineParams*) _address;
    _self->moi = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleEngineParams__1getPeakTorque(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleEngineParams* _self = (physx::vehicle2::PxVehicleEngineParams*) _address;
    return (jfloat) _self->peakTorque;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleEngineParams__1setPeakTorque(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleEngineParams* _self = (physx::vehicle2::PxVehicleEngineParams*) _address;
    _self->peakTorque = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleEngineParams__1getIdleOmega(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleEngineParams* _self = (physx::vehicle2::PxVehicleEngineParams*) _address;
    return (jfloat) _self->idleOmega;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleEngineParams__1setIdleOmega(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleEngineParams* _self = (physx::vehicle2::PxVehicleEngineParams*) _address;
    _self->idleOmega = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleEngineParams__1getMaxOmega(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleEngineParams* _self = (physx::vehicle2::PxVehicleEngineParams*) _address;
    return (jfloat) _self->maxOmega;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleEngineParams__1setMaxOmega(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleEngineParams* _self = (physx::vehicle2::PxVehicleEngineParams*) _address;
    _self->maxOmega = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleEngineParams__1getDampingRateFullThrottle(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleEngineParams* _self = (physx::vehicle2::PxVehicleEngineParams*) _address;
    return (jfloat) _self->dampingRateFullThrottle;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleEngineParams__1setDampingRateFullThrottle(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleEngineParams* _self = (physx::vehicle2::PxVehicleEngineParams*) _address;
    _self->dampingRateFullThrottle = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleEngineParams__1getDampingRateZeroThrottleClutchEngaged(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleEngineParams* _self = (physx::vehicle2::PxVehicleEngineParams*) _address;
    return (jfloat) _self->dampingRateZeroThrottleClutchEngaged;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleEngineParams__1setDampingRateZeroThrottleClutchEngaged(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleEngineParams* _self = (physx::vehicle2::PxVehicleEngineParams*) _address;
    _self->dampingRateZeroThrottleClutchEngaged = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleEngineParams__1getDampingRateZeroThrottleClutchDisengaged(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleEngineParams* _self = (physx::vehicle2::PxVehicleEngineParams*) _address;
    return (jfloat) _self->dampingRateZeroThrottleClutchDisengaged;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleEngineParams__1setDampingRateZeroThrottleClutchDisengaged(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleEngineParams* _self = (physx::vehicle2::PxVehicleEngineParams*) _address;
    _self->dampingRateZeroThrottleClutchDisengaged = value;
}

// PxVehicleEngineState
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleEngineState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleEngineState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleEngineState__1PxVehicleEngineState(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleEngineState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleEngineState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleEngineState* self = (physx::vehicle2::PxVehicleEngineState*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleEngineState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleEngineState*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleEngineState__1getRotationSpeed(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleEngineState* _self = (physx::vehicle2::PxVehicleEngineState*) _address;
    return (jfloat) _self->rotationSpeed;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleEngineState__1setRotationSpeed(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleEngineState* _self = (physx::vehicle2::PxVehicleEngineState*) _address;
    _self->rotationSpeed = value;
}

// PxVehicleFixedSizeLookupTableFloat_3
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleFixedSizeLookupTableFloat_13__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxVehicleFixedSizeLookupTableFloat_3);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleFixedSizeLookupTableFloat_13__1PxVehicleFixedSizeLookupTableFloat_13(JNIEnv*, jclass) {
    return (jlong) new PxVehicleFixedSizeLookupTableFloat_3();
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleFixedSizeLookupTableFloat_13__1addPair(JNIEnv*, jclass, jlong _address, jfloat x, jfloat y) {
    PxVehicleFixedSizeLookupTableFloat_3* self = (PxVehicleFixedSizeLookupTableFloat_3*) _address;
    return (jboolean) self->addPair(x, y);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleFixedSizeLookupTableFloat_13__1interpolate(JNIEnv*, jclass, jlong _address, jfloat x) {
    PxVehicleFixedSizeLookupTableFloat_3* self = (PxVehicleFixedSizeLookupTableFloat_3*) _address;
    return (jfloat) self->interpolate(x);
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleFixedSizeLookupTableFloat_13__1clear(JNIEnv*, jclass, jlong _address) {
    PxVehicleFixedSizeLookupTableFloat_3* self = (PxVehicleFixedSizeLookupTableFloat_3*) _address;
    self->clear();
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleFixedSizeLookupTableFloat_13__1isValid(JNIEnv*, jclass, jlong _address) {
    PxVehicleFixedSizeLookupTableFloat_3* self = (PxVehicleFixedSizeLookupTableFloat_3*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleFixedSizeLookupTableFloat_13__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxVehicleFixedSizeLookupTableFloat_3*) _address;
}

// PxVehicleFixedSizeLookupTableVec3_3
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleFixedSizeLookupTableVec3_13__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxVehicleFixedSizeLookupTableVec3_3);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleFixedSizeLookupTableVec3_13__1PxVehicleFixedSizeLookupTableVec3_13(JNIEnv*, jclass) {
    return (jlong) new PxVehicleFixedSizeLookupTableVec3_3();
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleFixedSizeLookupTableVec3_13__1addPair(JNIEnv*, jclass, jlong _address, jfloat x, jlong y) {
    PxVehicleFixedSizeLookupTableVec3_3* self = (PxVehicleFixedSizeLookupTableVec3_3*) _address;
    return (jboolean) self->addPair(x, *((physx::PxVec3*) y));
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleFixedSizeLookupTableVec3_13__1interpolate(JNIEnv*, jclass, jlong _address, jfloat x) {
    PxVehicleFixedSizeLookupTableVec3_3* self = (PxVehicleFixedSizeLookupTableVec3_3*) _address;
    static thread_local physx::PxVec3 _cache = self->interpolate(x);
    _cache = self->interpolate(x);
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleFixedSizeLookupTableVec3_13__1clear(JNIEnv*, jclass, jlong _address) {
    PxVehicleFixedSizeLookupTableVec3_3* self = (PxVehicleFixedSizeLookupTableVec3_3*) _address;
    self->clear();
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleFixedSizeLookupTableVec3_13__1isValid(JNIEnv*, jclass, jlong _address) {
    PxVehicleFixedSizeLookupTableVec3_3* self = (PxVehicleFixedSizeLookupTableVec3_3*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleFixedSizeLookupTableVec3_13__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxVehicleFixedSizeLookupTableVec3_3*) _address;
}

// PxVehicleFourWheelDriveDifferentialParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleFourWheelDriveDifferentialParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleFourWheelDriveDifferentialParams__1_1placement_1new_1PxVehicleFourWheelDriveDifferentialParams(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleFourWheelDriveDifferentialParams__1PxVehicleFourWheelDriveDifferentialParams(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleFourWheelDriveDifferentialParams__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams* self = (physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams*) _address;
    self->setToDefault();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleFourWheelDriveDifferentialParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams* self = (physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams*) _address;
    static thread_local physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleFourWheelDriveDifferentialParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams*) _address;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleFourWheelDriveDifferentialParams__1getFrontWheelIds(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams*) _address;
    return (jint) _self->frontWheelIds[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleFourWheelDriveDifferentialParams__1setFrontWheelIds(JNIEnv*, jclass, jlong _address, jint _index, jint value) {
    physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams*) _address;
    _self->frontWheelIds[_index] = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleFourWheelDriveDifferentialParams__1getRearWheelIds(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams*) _address;
    return (jint) _self->rearWheelIds[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleFourWheelDriveDifferentialParams__1setRearWheelIds(JNIEnv*, jclass, jlong _address, jint _index, jint value) {
    physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams*) _address;
    _self->rearWheelIds[_index] = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleFourWheelDriveDifferentialParams__1getFrontBias(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams*) _address;
    return (jfloat) _self->frontBias;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleFourWheelDriveDifferentialParams__1setFrontBias(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams*) _address;
    _self->frontBias = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleFourWheelDriveDifferentialParams__1getFrontTarget(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams*) _address;
    return (jfloat) _self->frontTarget;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleFourWheelDriveDifferentialParams__1setFrontTarget(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams*) _address;
    _self->frontTarget = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleFourWheelDriveDifferentialParams__1getRearBias(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams*) _address;
    return (jfloat) _self->rearBias;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleFourWheelDriveDifferentialParams__1setRearBias(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams*) _address;
    _self->rearBias = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleFourWheelDriveDifferentialParams__1getRearTarget(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams*) _address;
    return (jfloat) _self->rearTarget;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleFourWheelDriveDifferentialParams__1setRearTarget(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams*) _address;
    _self->rearTarget = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleFourWheelDriveDifferentialParams__1getCenterBias(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams*) _address;
    return (jfloat) _self->centerBias;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleFourWheelDriveDifferentialParams__1setCenterBias(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams*) _address;
    _self->centerBias = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleFourWheelDriveDifferentialParams__1getCenterTarget(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams*) _address;
    return (jfloat) _self->centerTarget;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleFourWheelDriveDifferentialParams__1setCenterTarget(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams*) _address;
    _self->centerTarget = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleFourWheelDriveDifferentialParams__1getRate(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams*) _address;
    return (jfloat) _self->rate;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleFourWheelDriveDifferentialParams__1setRate(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams*) _address;
    _self->rate = value;
}

// PxVehicleFrame
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleFrame__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleFrame);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleFrame__1PxVehicleFrame(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleFrame();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleFrame__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleFrame* self = (physx::vehicle2::PxVehicleFrame*) _address;
    self->setToDefault();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleFrame__1getFrame(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleFrame* self = (physx::vehicle2::PxVehicleFrame*) _address;
    static thread_local physx::PxMat33 _cache = self->getFrame();
    _cache = self->getFrame();
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleFrame__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleFrame* self = (physx::vehicle2::PxVehicleFrame*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleFrame__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleFrame*) _address;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleFrame__1getLngAxis(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleFrame* _self = (physx::vehicle2::PxVehicleFrame*) _address;
    return (jint) _self->lngAxis;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleFrame__1setLngAxis(JNIEnv*, jclass, jlong _address, jint value) {
    physx::vehicle2::PxVehicleFrame* _self = (physx::vehicle2::PxVehicleFrame*) _address;
    _self->lngAxis = (PxVehicleAxesEnum) value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleFrame__1getLatAxis(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleFrame* _self = (physx::vehicle2::PxVehicleFrame*) _address;
    return (jint) _self->latAxis;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleFrame__1setLatAxis(JNIEnv*, jclass, jlong _address, jint value) {
    physx::vehicle2::PxVehicleFrame* _self = (physx::vehicle2::PxVehicleFrame*) _address;
    _self->latAxis = (PxVehicleAxesEnum) value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleFrame__1getVrtAxis(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleFrame* _self = (physx::vehicle2::PxVehicleFrame*) _address;
    return (jint) _self->vrtAxis;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleFrame__1setVrtAxis(JNIEnv*, jclass, jlong _address, jint value) {
    physx::vehicle2::PxVehicleFrame* _self = (physx::vehicle2::PxVehicleFrame*) _address;
    _self->vrtAxis = (PxVehicleAxesEnum) value;
}

// PxVehicleGearboxParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleGearboxParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleGearboxParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleGearboxParams__1_1placement_1new_1PxVehicleGearboxParams(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::vehicle2::PxVehicleGearboxParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleGearboxParams__1PxVehicleGearboxParams(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleGearboxParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleGearboxParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    physx::vehicle2::PxVehicleGearboxParams* self = (physx::vehicle2::PxVehicleGearboxParams*) _address;
    static thread_local physx::vehicle2::PxVehicleGearboxParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleGearboxParams__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleGearboxParams* self = (physx::vehicle2::PxVehicleGearboxParams*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleGearboxParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleGearboxParams*) _address;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleGearboxParams__1getNeutralGear(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleGearboxParams* _self = (physx::vehicle2::PxVehicleGearboxParams*) _address;
    return (jint) _self->neutralGear;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleGearboxParams__1setNeutralGear(JNIEnv*, jclass, jlong _address, jint value) {
    physx::vehicle2::PxVehicleGearboxParams* _self = (physx::vehicle2::PxVehicleGearboxParams*) _address;
    _self->neutralGear = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleGearboxParams__1getRatios(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleGearboxParams* _self = (physx::vehicle2::PxVehicleGearboxParams*) _address;
    return (jfloat) _self->ratios[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleGearboxParams__1setRatios(JNIEnv*, jclass, jlong _address, jint _index, jfloat value) {
    physx::vehicle2::PxVehicleGearboxParams* _self = (physx::vehicle2::PxVehicleGearboxParams*) _address;
    _self->ratios[_index] = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleGearboxParams__1getFinalRatio(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleGearboxParams* _self = (physx::vehicle2::PxVehicleGearboxParams*) _address;
    return (jfloat) _self->finalRatio;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleGearboxParams__1setFinalRatio(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleGearboxParams* _self = (physx::vehicle2::PxVehicleGearboxParams*) _address;
    _self->finalRatio = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleGearboxParams__1getNbRatios(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleGearboxParams* _self = (physx::vehicle2::PxVehicleGearboxParams*) _address;
    return (jint) _self->nbRatios;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleGearboxParams__1setNbRatios(JNIEnv*, jclass, jlong _address, jint value) {
    physx::vehicle2::PxVehicleGearboxParams* _self = (physx::vehicle2::PxVehicleGearboxParams*) _address;
    _self->nbRatios = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleGearboxParams__1getSwitchTime(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleGearboxParams* _self = (physx::vehicle2::PxVehicleGearboxParams*) _address;
    return (jfloat) _self->switchTime;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleGearboxParams__1setSwitchTime(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleGearboxParams* _self = (physx::vehicle2::PxVehicleGearboxParams*) _address;
    _self->switchTime = value;
}

// PxVehicleGearboxState
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleGearboxState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleGearboxState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleGearboxState__1PxVehicleGearboxState(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleGearboxState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleGearboxState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleGearboxState* self = (physx::vehicle2::PxVehicleGearboxState*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleGearboxState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleGearboxState*) _address;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleGearboxState__1getCurrentGear(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleGearboxState* _self = (physx::vehicle2::PxVehicleGearboxState*) _address;
    return (jint) _self->currentGear;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleGearboxState__1setCurrentGear(JNIEnv*, jclass, jlong _address, jint value) {
    physx::vehicle2::PxVehicleGearboxState* _self = (physx::vehicle2::PxVehicleGearboxState*) _address;
    _self->currentGear = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleGearboxState__1getTargetGear(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleGearboxState* _self = (physx::vehicle2::PxVehicleGearboxState*) _address;
    return (jint) _self->targetGear;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleGearboxState__1setTargetGear(JNIEnv*, jclass, jlong _address, jint value) {
    physx::vehicle2::PxVehicleGearboxState* _self = (physx::vehicle2::PxVehicleGearboxState*) _address;
    _self->targetGear = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleGearboxState__1getGearSwitchTime(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleGearboxState* _self = (physx::vehicle2::PxVehicleGearboxState*) _address;
    return (jfloat) _self->gearSwitchTime;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleGearboxState__1setGearSwitchTime(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleGearboxState* _self = (physx::vehicle2::PxVehicleGearboxState*) _address;
    _self->gearSwitchTime = value;
}

// PxVehicleMultiWheelDriveDifferentialParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleMultiWheelDriveDifferentialParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleMultiWheelDriveDifferentialParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleMultiWheelDriveDifferentialParams__1_1placement_1new_1PxVehicleMultiWheelDriveDifferentialParams(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::vehicle2::PxVehicleMultiWheelDriveDifferentialParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleMultiWheelDriveDifferentialParams__1PxVehicleMultiWheelDriveDifferentialParams(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleMultiWheelDriveDifferentialParams();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleMultiWheelDriveDifferentialParams__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleMultiWheelDriveDifferentialParams* self = (physx::vehicle2::PxVehicleMultiWheelDriveDifferentialParams*) _address;
    self->setToDefault();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleMultiWheelDriveDifferentialParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    physx::vehicle2::PxVehicleMultiWheelDriveDifferentialParams* self = (physx::vehicle2::PxVehicleMultiWheelDriveDifferentialParams*) _address;
    static thread_local physx::vehicle2::PxVehicleMultiWheelDriveDifferentialParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleMultiWheelDriveDifferentialParams__1isValid(JNIEnv*, jclass, jlong _address, jlong axleDesc) {
    physx::vehicle2::PxVehicleMultiWheelDriveDifferentialParams* self = (physx::vehicle2::PxVehicleMultiWheelDriveDifferentialParams*) _address;
    return (jboolean) self->isValid(*((physx::vehicle2::PxVehicleAxleDescription*) axleDesc));
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleMultiWheelDriveDifferentialParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleMultiWheelDriveDifferentialParams*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleMultiWheelDriveDifferentialParams__1getTorqueRatios(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleMultiWheelDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleMultiWheelDriveDifferentialParams*) _address;
    return (jfloat) _self->torqueRatios[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleMultiWheelDriveDifferentialParams__1setTorqueRatios(JNIEnv*, jclass, jlong _address, jint _index, jfloat value) {
    physx::vehicle2::PxVehicleMultiWheelDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleMultiWheelDriveDifferentialParams*) _address;
    _self->torqueRatios[_index] = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleMultiWheelDriveDifferentialParams__1getAveWheelSpeedRatios(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleMultiWheelDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleMultiWheelDriveDifferentialParams*) _address;
    return (jfloat) _self->aveWheelSpeedRatios[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleMultiWheelDriveDifferentialParams__1setAveWheelSpeedRatios(JNIEnv*, jclass, jlong _address, jint _index, jfloat value) {
    physx::vehicle2::PxVehicleMultiWheelDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleMultiWheelDriveDifferentialParams*) _address;
    _self->aveWheelSpeedRatios[_index] = value;
}

// PxVehiclePhysXActor
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehiclePhysXActor__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehiclePhysXActor);
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXActor__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXActor* self = (physx::vehicle2::PxVehiclePhysXActor*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXActor__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehiclePhysXActor*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehiclePhysXActor__1getRigidBody(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXActor* _self = (physx::vehicle2::PxVehiclePhysXActor*) _address;
    return (jlong) _self->rigidBody;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXActor__1setRigidBody(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehiclePhysXActor* _self = (physx::vehicle2::PxVehiclePhysXActor*) _address;
    _self->rigidBody = (physx::PxRigidBody*) value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehiclePhysXActor__1getWheelShapes(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehiclePhysXActor* _self = (physx::vehicle2::PxVehiclePhysXActor*) _address;
    return (jlong) _self->wheelShapes[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXActor__1setWheelShapes(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    physx::vehicle2::PxVehiclePhysXActor* _self = (physx::vehicle2::PxVehiclePhysXActor*) _address;
    _self->wheelShapes[_index] = (physx::PxShape*) value;
}

// PxVehiclePhysXConstraints
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraints__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehiclePhysXConstraints);
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraints__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXConstraints* self = (physx::vehicle2::PxVehiclePhysXConstraints*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraints__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehiclePhysXConstraints*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraints__1getConstraintStates(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehiclePhysXConstraints* _self = (physx::vehicle2::PxVehiclePhysXConstraints*) _address;
    return (jlong) &_self->constraintStates[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraints__1setConstraintStates(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    physx::vehicle2::PxVehiclePhysXConstraints* _self = (physx::vehicle2::PxVehiclePhysXConstraints*) _address;
    _self->constraintStates[_index] = *((physx::vehicle2::PxVehiclePhysXConstraintState*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraints__1getConstraints(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehiclePhysXConstraints* _self = (physx::vehicle2::PxVehiclePhysXConstraints*) _address;
    return (jlong) _self->constraints[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraints__1setConstraints(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    physx::vehicle2::PxVehiclePhysXConstraints* _self = (physx::vehicle2::PxVehiclePhysXConstraints*) _address;
    _self->constraints[_index] = (physx::PxConstraint*) value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraints__1getConstraintConnectors(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehiclePhysXConstraints* _self = (physx::vehicle2::PxVehiclePhysXConstraints*) _address;
    return (jlong) _self->constraintConnectors[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraints__1setConstraintConnectors(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    physx::vehicle2::PxVehiclePhysXConstraints* _self = (physx::vehicle2::PxVehiclePhysXConstraints*) _address;
    _self->constraintConnectors[_index] = (physx::vehicle2::PxVehicleConstraintConnector*) value;
}

// PxVehiclePhysXConstraintState
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraintState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehiclePhysXConstraintState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraintState__1PxVehiclePhysXConstraintState(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehiclePhysXConstraintState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraintState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXConstraintState* self = (physx::vehicle2::PxVehiclePhysXConstraintState*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraintState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehiclePhysXConstraintState*) _address;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraintState__1getTireActiveStatus(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehiclePhysXConstraintState* _self = (physx::vehicle2::PxVehiclePhysXConstraintState*) _address;
    return (jboolean) _self->tireActiveStatus[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraintState__1setTireActiveStatus(JNIEnv*, jclass, jlong _address, jint _index, jboolean value) {
    physx::vehicle2::PxVehiclePhysXConstraintState* _self = (physx::vehicle2::PxVehiclePhysXConstraintState*) _address;
    _self->tireActiveStatus[_index] = value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraintState__1getTireLinears(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehiclePhysXConstraintState* _self = (physx::vehicle2::PxVehiclePhysXConstraintState*) _address;
    return (jlong) &_self->tireLinears[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraintState__1setTireLinears(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    physx::vehicle2::PxVehiclePhysXConstraintState* _self = (physx::vehicle2::PxVehiclePhysXConstraintState*) _address;
    _self->tireLinears[_index] = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraintState__1getTireAngulars(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehiclePhysXConstraintState* _self = (physx::vehicle2::PxVehiclePhysXConstraintState*) _address;
    return (jlong) &_self->tireAngulars[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraintState__1setTireAngulars(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    physx::vehicle2::PxVehiclePhysXConstraintState* _self = (physx::vehicle2::PxVehiclePhysXConstraintState*) _address;
    _self->tireAngulars[_index] = *((physx::PxVec3*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraintState__1getTireDamping(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehiclePhysXConstraintState* _self = (physx::vehicle2::PxVehiclePhysXConstraintState*) _address;
    return (jfloat) _self->tireDamping[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraintState__1setTireDamping(JNIEnv*, jclass, jlong _address, jint _index, jfloat value) {
    physx::vehicle2::PxVehiclePhysXConstraintState* _self = (physx::vehicle2::PxVehiclePhysXConstraintState*) _address;
    _self->tireDamping[_index] = value;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraintState__1getSuspActiveStatus(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXConstraintState* _self = (physx::vehicle2::PxVehiclePhysXConstraintState*) _address;
    return (jboolean) _self->suspActiveStatus;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraintState__1setSuspActiveStatus(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::vehicle2::PxVehiclePhysXConstraintState* _self = (physx::vehicle2::PxVehiclePhysXConstraintState*) _address;
    _self->suspActiveStatus = value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraintState__1getSuspLinear(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXConstraintState* _self = (physx::vehicle2::PxVehiclePhysXConstraintState*) _address;
    return (jlong) &_self->suspLinear;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraintState__1setSuspLinear(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehiclePhysXConstraintState* _self = (physx::vehicle2::PxVehiclePhysXConstraintState*) _address;
    _self->suspLinear = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraintState__1getSuspAngular(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXConstraintState* _self = (physx::vehicle2::PxVehiclePhysXConstraintState*) _address;
    return (jlong) &_self->suspAngular;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraintState__1setSuspAngular(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehiclePhysXConstraintState* _self = (physx::vehicle2::PxVehiclePhysXConstraintState*) _address;
    _self->suspAngular = *((physx::PxVec3*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraintState__1getSuspGeometricError(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXConstraintState* _self = (physx::vehicle2::PxVehiclePhysXConstraintState*) _address;
    return (jfloat) _self->suspGeometricError;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraintState__1setSuspGeometricError(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehiclePhysXConstraintState* _self = (physx::vehicle2::PxVehiclePhysXConstraintState*) _address;
    _self->suspGeometricError = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraintState__1getRestitution(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXConstraintState* _self = (physx::vehicle2::PxVehiclePhysXConstraintState*) _address;
    return (jfloat) _self->restitution;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraintState__1setRestitution(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehiclePhysXConstraintState* _self = (physx::vehicle2::PxVehiclePhysXConstraintState*) _address;
    _self->restitution = value;
}

// PxVehiclePhysXMaterialFriction
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehiclePhysXMaterialFriction__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehiclePhysXMaterialFriction);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehiclePhysXMaterialFriction__1PxVehiclePhysXMaterialFriction(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehiclePhysXMaterialFriction();
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehiclePhysXMaterialFriction__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXMaterialFriction* self = (physx::vehicle2::PxVehiclePhysXMaterialFriction*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXMaterialFriction__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehiclePhysXMaterialFriction*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehiclePhysXMaterialFriction__1getMaterial(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXMaterialFriction* _self = (physx::vehicle2::PxVehiclePhysXMaterialFriction*) _address;
    return (jlong) _self->material;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXMaterialFriction__1setMaterial(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehiclePhysXMaterialFriction* _self = (physx::vehicle2::PxVehiclePhysXMaterialFriction*) _address;
    _self->material = (physx::PxMaterial*) value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehiclePhysXMaterialFriction__1getFriction(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXMaterialFriction* _self = (physx::vehicle2::PxVehiclePhysXMaterialFriction*) _address;
    return (jfloat) _self->friction;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXMaterialFriction__1setFriction(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehiclePhysXMaterialFriction* _self = (physx::vehicle2::PxVehiclePhysXMaterialFriction*) _address;
    _self->friction = value;
}

// PxVehiclePhysXMaterialFrictionParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehiclePhysXMaterialFrictionParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehiclePhysXMaterialFrictionParams);
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehiclePhysXMaterialFrictionParams__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXMaterialFrictionParams* self = (physx::vehicle2::PxVehiclePhysXMaterialFrictionParams*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXMaterialFrictionParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehiclePhysXMaterialFrictionParams*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehiclePhysXMaterialFrictionParams__1getMaterialFrictions(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXMaterialFrictionParams* _self = (physx::vehicle2::PxVehiclePhysXMaterialFrictionParams*) _address;
    return (jlong) _self->materialFrictions;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXMaterialFrictionParams__1setMaterialFrictions(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehiclePhysXMaterialFrictionParams* _self = (physx::vehicle2::PxVehiclePhysXMaterialFrictionParams*) _address;
    _self->materialFrictions = (physx::vehicle2::PxVehiclePhysXMaterialFriction*) value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehiclePhysXMaterialFrictionParams__1getNbMaterialFrictions(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXMaterialFrictionParams* _self = (physx::vehicle2::PxVehiclePhysXMaterialFrictionParams*) _address;
    return (jint) _self->nbMaterialFrictions;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXMaterialFrictionParams__1setNbMaterialFrictions(JNIEnv*, jclass, jlong _address, jint value) {
    physx::vehicle2::PxVehiclePhysXMaterialFrictionParams* _self = (physx::vehicle2::PxVehiclePhysXMaterialFrictionParams*) _address;
    _self->nbMaterialFrictions = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehiclePhysXMaterialFrictionParams__1getDefaultFriction(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXMaterialFrictionParams* _self = (physx::vehicle2::PxVehiclePhysXMaterialFrictionParams*) _address;
    return (jfloat) _self->defaultFriction;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXMaterialFrictionParams__1setDefaultFriction(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehiclePhysXMaterialFrictionParams* _self = (physx::vehicle2::PxVehiclePhysXMaterialFrictionParams*) _address;
    _self->defaultFriction = value;
}

// PxVehiclePhysXRoadGeometryQueryParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehiclePhysXRoadGeometryQueryParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehiclePhysXRoadGeometryQueryParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehiclePhysXRoadGeometryQueryParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    physx::vehicle2::PxVehiclePhysXRoadGeometryQueryParams* self = (physx::vehicle2::PxVehiclePhysXRoadGeometryQueryParams*) _address;
    static thread_local physx::vehicle2::PxVehiclePhysXRoadGeometryQueryParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehiclePhysXRoadGeometryQueryParams__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXRoadGeometryQueryParams* self = (physx::vehicle2::PxVehiclePhysXRoadGeometryQueryParams*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXRoadGeometryQueryParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehiclePhysXRoadGeometryQueryParams*) _address;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehiclePhysXRoadGeometryQueryParams__1getRoadGeometryQueryType(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXRoadGeometryQueryParams* _self = (physx::vehicle2::PxVehiclePhysXRoadGeometryQueryParams*) _address;
    return (jint) _self->roadGeometryQueryType;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXRoadGeometryQueryParams__1setRoadGeometryQueryType(JNIEnv*, jclass, jlong _address, jint value) {
    physx::vehicle2::PxVehiclePhysXRoadGeometryQueryParams* _self = (physx::vehicle2::PxVehiclePhysXRoadGeometryQueryParams*) _address;
    _self->roadGeometryQueryType = (PxVehiclePhysXRoadGeometryQueryTypeEnum) value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehiclePhysXRoadGeometryQueryParams__1getFilterData(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXRoadGeometryQueryParams* _self = (physx::vehicle2::PxVehiclePhysXRoadGeometryQueryParams*) _address;
    return (jlong) &_self->filterData;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXRoadGeometryQueryParams__1setFilterData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehiclePhysXRoadGeometryQueryParams* _self = (physx::vehicle2::PxVehiclePhysXRoadGeometryQueryParams*) _address;
    _self->filterData = *((physx::PxQueryFilterData*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehiclePhysXRoadGeometryQueryParams__1getFilterCallback(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXRoadGeometryQueryParams* _self = (physx::vehicle2::PxVehiclePhysXRoadGeometryQueryParams*) _address;
    return (jlong) _self->filterCallback;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXRoadGeometryQueryParams__1setFilterCallback(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehiclePhysXRoadGeometryQueryParams* _self = (physx::vehicle2::PxVehiclePhysXRoadGeometryQueryParams*) _address;
    _self->filterCallback = (physx::PxQueryFilterCallback*) value;
}

// PxVehiclePhysXSimulationContext
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehiclePhysXSimulationContext__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehiclePhysXSimulationContext);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehiclePhysXSimulationContext__1PxVehiclePhysXSimulationContext(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehiclePhysXSimulationContext();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehiclePhysXSimulationContext__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    physx::vehicle2::PxVehiclePhysXSimulationContext* self = (physx::vehicle2::PxVehiclePhysXSimulationContext*) _address;
    static thread_local physx::vehicle2::PxVehiclePhysXSimulationContext _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehiclePhysXSimulationContext__1getPhysxUnitCylinderSweepMesh(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXSimulationContext* _self = (physx::vehicle2::PxVehiclePhysXSimulationContext*) _address;
    return (jlong) _self->physxUnitCylinderSweepMesh;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXSimulationContext__1setPhysxUnitCylinderSweepMesh(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehiclePhysXSimulationContext* _self = (physx::vehicle2::PxVehiclePhysXSimulationContext*) _address;
    _self->physxUnitCylinderSweepMesh = (physx::PxConvexMesh*) value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehiclePhysXSimulationContext__1getPhysxScene(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXSimulationContext* _self = (physx::vehicle2::PxVehiclePhysXSimulationContext*) _address;
    return (jlong) _self->physxScene;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXSimulationContext__1setPhysxScene(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehiclePhysXSimulationContext* _self = (physx::vehicle2::PxVehiclePhysXSimulationContext*) _address;
    _self->physxScene = (physx::PxScene*) value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehiclePhysXSimulationContext__1getPhysxActorUpdateMode(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXSimulationContext* _self = (physx::vehicle2::PxVehiclePhysXSimulationContext*) _address;
    return (jint) _self->physxActorUpdateMode;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXSimulationContext__1setPhysxActorUpdateMode(JNIEnv*, jclass, jlong _address, jint value) {
    physx::vehicle2::PxVehiclePhysXSimulationContext* _self = (physx::vehicle2::PxVehiclePhysXSimulationContext*) _address;
    _self->physxActorUpdateMode = (PxVehiclePhysXActorUpdateModeEnum) value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehiclePhysXSimulationContext__1getPhysxActorWakeCounterResetValue(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXSimulationContext* _self = (physx::vehicle2::PxVehiclePhysXSimulationContext*) _address;
    return (jfloat) _self->physxActorWakeCounterResetValue;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXSimulationContext__1setPhysxActorWakeCounterResetValue(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehiclePhysXSimulationContext* _self = (physx::vehicle2::PxVehiclePhysXSimulationContext*) _address;
    _self->physxActorWakeCounterResetValue = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehiclePhysXSimulationContext__1getPhysxActorWakeCounterThreshold(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXSimulationContext* _self = (physx::vehicle2::PxVehiclePhysXSimulationContext*) _address;
    return (jfloat) _self->physxActorWakeCounterThreshold;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXSimulationContext__1setPhysxActorWakeCounterThreshold(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehiclePhysXSimulationContext* _self = (physx::vehicle2::PxVehiclePhysXSimulationContext*) _address;
    _self->physxActorWakeCounterThreshold = value;
}

// PxVehiclePhysXSteerState
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehiclePhysXSteerState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehiclePhysXSteerState);
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXSteerState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXSteerState* self = (physx::vehicle2::PxVehiclePhysXSteerState*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXSteerState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehiclePhysXSteerState*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehiclePhysXSteerState__1getPreviousSteerCommand(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXSteerState* _self = (physx::vehicle2::PxVehiclePhysXSteerState*) _address;
    return (jfloat) _self->previousSteerCommand;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXSteerState__1setPreviousSteerCommand(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehiclePhysXSteerState* _self = (physx::vehicle2::PxVehiclePhysXSteerState*) _address;
    _self->previousSteerCommand = value;
}

// PxVehiclePhysXSuspensionLimitConstraintParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehiclePhysXSuspensionLimitConstraintParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehiclePhysXSuspensionLimitConstraintParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehiclePhysXSuspensionLimitConstraintParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    physx::vehicle2::PxVehiclePhysXSuspensionLimitConstraintParams* self = (physx::vehicle2::PxVehiclePhysXSuspensionLimitConstraintParams*) _address;
    static thread_local physx::vehicle2::PxVehiclePhysXSuspensionLimitConstraintParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehiclePhysXSuspensionLimitConstraintParams__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXSuspensionLimitConstraintParams* self = (physx::vehicle2::PxVehiclePhysXSuspensionLimitConstraintParams*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXSuspensionLimitConstraintParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehiclePhysXSuspensionLimitConstraintParams*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehiclePhysXSuspensionLimitConstraintParams__1getRestitution(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXSuspensionLimitConstraintParams* _self = (physx::vehicle2::PxVehiclePhysXSuspensionLimitConstraintParams*) _address;
    return (jfloat) _self->restitution;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXSuspensionLimitConstraintParams__1setRestitution(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehiclePhysXSuspensionLimitConstraintParams* _self = (physx::vehicle2::PxVehiclePhysXSuspensionLimitConstraintParams*) _address;
    _self->restitution = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehiclePhysXSuspensionLimitConstraintParams__1getDirectionForSuspensionLimitConstraint(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehiclePhysXSuspensionLimitConstraintParams* _self = (physx::vehicle2::PxVehiclePhysXSuspensionLimitConstraintParams*) _address;
    return (jint) _self->directionForSuspensionLimitConstraint;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehiclePhysXSuspensionLimitConstraintParams__1setDirectionForSuspensionLimitConstraint(JNIEnv*, jclass, jlong _address, jint value) {
    physx::vehicle2::PxVehiclePhysXSuspensionLimitConstraintParams* _self = (physx::vehicle2::PxVehiclePhysXSuspensionLimitConstraintParams*) _address;
    _self->directionForSuspensionLimitConstraint = (PxVehiclePhysXSuspensionLimitConstraintParamsDirectionSpecifierEnum) value;
}

// PxVehiclePvdContext
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehiclePvdContext__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehiclePvdContext);
}

// PxVehicleRigidBodyParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleRigidBodyParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleRigidBodyParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleRigidBodyParams__1PxVehicleRigidBodyParams(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleRigidBodyParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleRigidBodyParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    physx::vehicle2::PxVehicleRigidBodyParams* self = (physx::vehicle2::PxVehicleRigidBodyParams*) _address;
    static thread_local physx::vehicle2::PxVehicleRigidBodyParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleRigidBodyParams__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleRigidBodyParams* self = (physx::vehicle2::PxVehicleRigidBodyParams*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleRigidBodyParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleRigidBodyParams*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleRigidBodyParams__1getMass(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleRigidBodyParams* _self = (physx::vehicle2::PxVehicleRigidBodyParams*) _address;
    return (jfloat) _self->mass;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleRigidBodyParams__1setMass(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleRigidBodyParams* _self = (physx::vehicle2::PxVehicleRigidBodyParams*) _address;
    _self->mass = value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleRigidBodyParams__1getMoi(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleRigidBodyParams* _self = (physx::vehicle2::PxVehicleRigidBodyParams*) _address;
    return (jlong) &_self->moi;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleRigidBodyParams__1setMoi(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleRigidBodyParams* _self = (physx::vehicle2::PxVehicleRigidBodyParams*) _address;
    _self->moi = *((physx::PxVec3*) value);
}

// PxVehicleRigidBodyState
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleRigidBodyState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleRigidBodyState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleRigidBodyState__1PxVehicleRigidBodyState(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleRigidBodyState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleRigidBodyState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleRigidBodyState* self = (physx::vehicle2::PxVehicleRigidBodyState*) _address;
    self->setToDefault();
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleRigidBodyState__1getVerticalSpeed(JNIEnv*, jclass, jlong _address, jlong frame) {
    physx::vehicle2::PxVehicleRigidBodyState* self = (physx::vehicle2::PxVehicleRigidBodyState*) _address;
    return (jfloat) self->getVerticalSpeed(*((physx::vehicle2::PxVehicleFrame*) frame));
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleRigidBodyState__1getLateralSpeed(JNIEnv*, jclass, jlong _address, jlong frame) {
    physx::vehicle2::PxVehicleRigidBodyState* self = (physx::vehicle2::PxVehicleRigidBodyState*) _address;
    return (jfloat) self->getLateralSpeed(*((physx::vehicle2::PxVehicleFrame*) frame));
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleRigidBodyState__1getLongitudinalSpeed(JNIEnv*, jclass, jlong _address, jlong frame) {
    physx::vehicle2::PxVehicleRigidBodyState* self = (physx::vehicle2::PxVehicleRigidBodyState*) _address;
    return (jfloat) self->getLongitudinalSpeed(*((physx::vehicle2::PxVehicleFrame*) frame));
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleRigidBodyState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleRigidBodyState*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleRigidBodyState__1getPose(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleRigidBodyState* _self = (physx::vehicle2::PxVehicleRigidBodyState*) _address;
    return (jlong) &_self->pose;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleRigidBodyState__1setPose(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleRigidBodyState* _self = (physx::vehicle2::PxVehicleRigidBodyState*) _address;
    _self->pose = *((physx::PxTransform*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleRigidBodyState__1getLinearVelocity(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleRigidBodyState* _self = (physx::vehicle2::PxVehicleRigidBodyState*) _address;
    return (jlong) &_self->linearVelocity;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleRigidBodyState__1setLinearVelocity(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleRigidBodyState* _self = (physx::vehicle2::PxVehicleRigidBodyState*) _address;
    _self->linearVelocity = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleRigidBodyState__1getAngularVelocity(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleRigidBodyState* _self = (physx::vehicle2::PxVehicleRigidBodyState*) _address;
    return (jlong) &_self->angularVelocity;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleRigidBodyState__1setAngularVelocity(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleRigidBodyState* _self = (physx::vehicle2::PxVehicleRigidBodyState*) _address;
    _self->angularVelocity = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleRigidBodyState__1getPreviousLinearVelocity(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleRigidBodyState* _self = (physx::vehicle2::PxVehicleRigidBodyState*) _address;
    return (jlong) &_self->previousLinearVelocity;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleRigidBodyState__1setPreviousLinearVelocity(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleRigidBodyState* _self = (physx::vehicle2::PxVehicleRigidBodyState*) _address;
    _self->previousLinearVelocity = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleRigidBodyState__1getPreviousAngularVelocity(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleRigidBodyState* _self = (physx::vehicle2::PxVehicleRigidBodyState*) _address;
    return (jlong) &_self->previousAngularVelocity;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleRigidBodyState__1setPreviousAngularVelocity(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleRigidBodyState* _self = (physx::vehicle2::PxVehicleRigidBodyState*) _address;
    _self->previousAngularVelocity = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleRigidBodyState__1getExternalForce(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleRigidBodyState* _self = (physx::vehicle2::PxVehicleRigidBodyState*) _address;
    return (jlong) &_self->externalForce;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleRigidBodyState__1setExternalForce(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleRigidBodyState* _self = (physx::vehicle2::PxVehicleRigidBodyState*) _address;
    _self->externalForce = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleRigidBodyState__1getExternalTorque(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleRigidBodyState* _self = (physx::vehicle2::PxVehicleRigidBodyState*) _address;
    return (jlong) &_self->externalTorque;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleRigidBodyState__1setExternalTorque(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleRigidBodyState* _self = (physx::vehicle2::PxVehicleRigidBodyState*) _address;
    _self->externalTorque = *((physx::PxVec3*) value);
}

// PxVehicleRoadGeometryState
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleRoadGeometryState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleRoadGeometryState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleRoadGeometryState__1PxVehicleRoadGeometryState(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleRoadGeometryState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleRoadGeometryState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleRoadGeometryState* self = (physx::vehicle2::PxVehicleRoadGeometryState*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleRoadGeometryState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleRoadGeometryState*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleRoadGeometryState__1getPlane(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleRoadGeometryState* _self = (physx::vehicle2::PxVehicleRoadGeometryState*) _address;
    return (jlong) &_self->plane;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleRoadGeometryState__1setPlane(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleRoadGeometryState* _self = (physx::vehicle2::PxVehicleRoadGeometryState*) _address;
    _self->plane = *((physx::PxPlane*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleRoadGeometryState__1getFriction(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleRoadGeometryState* _self = (physx::vehicle2::PxVehicleRoadGeometryState*) _address;
    return (jfloat) _self->friction;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleRoadGeometryState__1setFriction(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleRoadGeometryState* _self = (physx::vehicle2::PxVehicleRoadGeometryState*) _address;
    _self->friction = value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleRoadGeometryState__1getVelocity(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleRoadGeometryState* _self = (physx::vehicle2::PxVehicleRoadGeometryState*) _address;
    return (jlong) &_self->velocity;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleRoadGeometryState__1setVelocity(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleRoadGeometryState* _self = (physx::vehicle2::PxVehicleRoadGeometryState*) _address;
    _self->velocity = *((physx::PxVec3*) value);
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleRoadGeometryState__1getHitState(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleRoadGeometryState* _self = (physx::vehicle2::PxVehicleRoadGeometryState*) _address;
    return (jboolean) _self->hitState;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleRoadGeometryState__1setHitState(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::vehicle2::PxVehicleRoadGeometryState* _self = (physx::vehicle2::PxVehicleRoadGeometryState*) _address;
    _self->hitState = value;
}

// PxVehicleScale
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleScale__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleScale);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleScale__1PxVehicleScale(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleScale();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleScale__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleScale* self = (physx::vehicle2::PxVehicleScale*) _address;
    self->setToDefault();
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleScale__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleScale* self = (physx::vehicle2::PxVehicleScale*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleScale__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleScale*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleScale__1getScale(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleScale* _self = (physx::vehicle2::PxVehicleScale*) _address;
    return (jfloat) _self->scale;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleScale__1setScale(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleScale* _self = (physx::vehicle2::PxVehicleScale*) _address;
    _self->scale = value;
}

// PxVehicleSimulationContext
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleSimulationContext__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleSimulationContext);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSimulationContext__1PxVehicleSimulationContext(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleSimulationContext();
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleSimulationContext__1getType(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSimulationContext* self = (physx::vehicle2::PxVehicleSimulationContext*) _address;
    return (jint) self->getType();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSimulationContext__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSimulationContext* self = (physx::vehicle2::PxVehicleSimulationContext*) _address;
    self->setToDefault();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSimulationContext__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    physx::vehicle2::PxVehicleSimulationContext* self = (physx::vehicle2::PxVehicleSimulationContext*) _address;
    static thread_local physx::vehicle2::PxVehicleSimulationContext _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSimulationContext__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleSimulationContext*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSimulationContext__1getGravity(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSimulationContext* _self = (physx::vehicle2::PxVehicleSimulationContext*) _address;
    return (jlong) &_self->gravity;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSimulationContext__1setGravity(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleSimulationContext* _self = (physx::vehicle2::PxVehicleSimulationContext*) _address;
    _self->gravity = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSimulationContext__1getFrame(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSimulationContext* _self = (physx::vehicle2::PxVehicleSimulationContext*) _address;
    return (jlong) &_self->frame;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSimulationContext__1setFrame(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleSimulationContext* _self = (physx::vehicle2::PxVehicleSimulationContext*) _address;
    _self->frame = *((physx::vehicle2::PxVehicleFrame*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSimulationContext__1getScale(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSimulationContext* _self = (physx::vehicle2::PxVehicleSimulationContext*) _address;
    return (jlong) &_self->scale;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSimulationContext__1setScale(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleSimulationContext* _self = (physx::vehicle2::PxVehicleSimulationContext*) _address;
    _self->scale = *((physx::vehicle2::PxVehicleScale*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSimulationContext__1getTireSlipParams(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSimulationContext* _self = (physx::vehicle2::PxVehicleSimulationContext*) _address;
    return (jlong) &_self->tireSlipParams;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSimulationContext__1setTireSlipParams(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleSimulationContext* _self = (physx::vehicle2::PxVehicleSimulationContext*) _address;
    _self->tireSlipParams = *((physx::vehicle2::PxVehicleTireSlipParams*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSimulationContext__1getTireStickyParams(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSimulationContext* _self = (physx::vehicle2::PxVehicleSimulationContext*) _address;
    return (jlong) &_self->tireStickyParams;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSimulationContext__1setTireStickyParams(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleSimulationContext* _self = (physx::vehicle2::PxVehicleSimulationContext*) _address;
    _self->tireStickyParams = *((physx::vehicle2::PxVehicleTireStickyParams*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleSimulationContext__1getThresholdForwardSpeedForWheelAngleIntegration(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSimulationContext* _self = (physx::vehicle2::PxVehicleSimulationContext*) _address;
    return (jfloat) _self->thresholdForwardSpeedForWheelAngleIntegration;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSimulationContext__1setThresholdForwardSpeedForWheelAngleIntegration(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleSimulationContext* _self = (physx::vehicle2::PxVehicleSimulationContext*) _address;
    _self->thresholdForwardSpeedForWheelAngleIntegration = value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSimulationContext__1getPvdContext(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSimulationContext* _self = (physx::vehicle2::PxVehicleSimulationContext*) _address;
    return (jlong) &_self->pvdContext;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSimulationContext__1setPvdContext(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleSimulationContext* _self = (physx::vehicle2::PxVehicleSimulationContext*) _address;
    _self->pvdContext = *((physx::vehicle2::PxVehiclePvdContext*) value);
}

// PxVehicleSteerCommandResponseParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleSteerCommandResponseParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleSteerCommandResponseParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSteerCommandResponseParams__1PxVehicleSteerCommandResponseParams(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleSteerCommandResponseParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSteerCommandResponseParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    physx::vehicle2::PxVehicleSteerCommandResponseParams* self = (physx::vehicle2::PxVehicleSteerCommandResponseParams*) _address;
    static thread_local physx::vehicle2::PxVehicleSteerCommandResponseParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleSteerCommandResponseParams__1isValid(JNIEnv*, jclass, jlong _address, jlong axleDesc) {
    physx::vehicle2::PxVehicleSteerCommandResponseParams* self = (physx::vehicle2::PxVehicleSteerCommandResponseParams*) _address;
    return (jboolean) self->isValid(*((physx::vehicle2::PxVehicleAxleDescription*) axleDesc));
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSteerCommandResponseParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleSteerCommandResponseParams*) _address;
}

// PxVehicleSuspensionComplianceParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleSuspensionComplianceParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleSuspensionComplianceParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSuspensionComplianceParams__1PxVehicleSuspensionComplianceParams(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleSuspensionComplianceParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSuspensionComplianceParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    physx::vehicle2::PxVehicleSuspensionComplianceParams* self = (physx::vehicle2::PxVehicleSuspensionComplianceParams*) _address;
    static thread_local physx::vehicle2::PxVehicleSuspensionComplianceParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleSuspensionComplianceParams__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionComplianceParams* self = (physx::vehicle2::PxVehicleSuspensionComplianceParams*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionComplianceParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleSuspensionComplianceParams*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSuspensionComplianceParams__1getWheelToeAngle(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionComplianceParams* _self = (physx::vehicle2::PxVehicleSuspensionComplianceParams*) _address;
    return (jlong) &_self->wheelToeAngle;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionComplianceParams__1setWheelToeAngle(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleSuspensionComplianceParams* _self = (physx::vehicle2::PxVehicleSuspensionComplianceParams*) _address;
    _self->wheelToeAngle = *((PxVehicleFixedSizeLookupTableFloat_3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSuspensionComplianceParams__1getWheelCamberAngle(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionComplianceParams* _self = (physx::vehicle2::PxVehicleSuspensionComplianceParams*) _address;
    return (jlong) &_self->wheelCamberAngle;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionComplianceParams__1setWheelCamberAngle(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleSuspensionComplianceParams* _self = (physx::vehicle2::PxVehicleSuspensionComplianceParams*) _address;
    _self->wheelCamberAngle = *((PxVehicleFixedSizeLookupTableFloat_3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSuspensionComplianceParams__1getSuspForceAppPoint(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionComplianceParams* _self = (physx::vehicle2::PxVehicleSuspensionComplianceParams*) _address;
    return (jlong) &_self->suspForceAppPoint;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionComplianceParams__1setSuspForceAppPoint(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleSuspensionComplianceParams* _self = (physx::vehicle2::PxVehicleSuspensionComplianceParams*) _address;
    _self->suspForceAppPoint = *((PxVehicleFixedSizeLookupTableVec3_3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSuspensionComplianceParams__1getTireForceAppPoint(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionComplianceParams* _self = (physx::vehicle2::PxVehicleSuspensionComplianceParams*) _address;
    return (jlong) &_self->tireForceAppPoint;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionComplianceParams__1setTireForceAppPoint(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleSuspensionComplianceParams* _self = (physx::vehicle2::PxVehicleSuspensionComplianceParams*) _address;
    _self->tireForceAppPoint = *((PxVehicleFixedSizeLookupTableVec3_3*) value);
}

// PxVehicleSuspensionComplianceState
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleSuspensionComplianceState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleSuspensionComplianceState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSuspensionComplianceState__1PxVehicleSuspensionComplianceState(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleSuspensionComplianceState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionComplianceState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionComplianceState* self = (physx::vehicle2::PxVehicleSuspensionComplianceState*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionComplianceState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleSuspensionComplianceState*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleSuspensionComplianceState__1getToe(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionComplianceState* _self = (physx::vehicle2::PxVehicleSuspensionComplianceState*) _address;
    return (jfloat) _self->toe;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionComplianceState__1setToe(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleSuspensionComplianceState* _self = (physx::vehicle2::PxVehicleSuspensionComplianceState*) _address;
    _self->toe = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleSuspensionComplianceState__1getCamber(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionComplianceState* _self = (physx::vehicle2::PxVehicleSuspensionComplianceState*) _address;
    return (jfloat) _self->camber;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionComplianceState__1setCamber(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleSuspensionComplianceState* _self = (physx::vehicle2::PxVehicleSuspensionComplianceState*) _address;
    _self->camber = value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSuspensionComplianceState__1getTireForceAppPoint(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionComplianceState* _self = (physx::vehicle2::PxVehicleSuspensionComplianceState*) _address;
    return (jlong) &_self->tireForceAppPoint;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionComplianceState__1setTireForceAppPoint(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleSuspensionComplianceState* _self = (physx::vehicle2::PxVehicleSuspensionComplianceState*) _address;
    _self->tireForceAppPoint = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSuspensionComplianceState__1getSuspForceAppPoint(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionComplianceState* _self = (physx::vehicle2::PxVehicleSuspensionComplianceState*) _address;
    return (jlong) &_self->suspForceAppPoint;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionComplianceState__1setSuspForceAppPoint(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleSuspensionComplianceState* _self = (physx::vehicle2::PxVehicleSuspensionComplianceState*) _address;
    _self->suspForceAppPoint = *((physx::PxVec3*) value);
}

// PxVehicleSuspensionForce
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleSuspensionForce__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleSuspensionForce);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSuspensionForce__1PxVehicleSuspensionForce(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleSuspensionForce();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionForce__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionForce* self = (physx::vehicle2::PxVehicleSuspensionForce*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionForce__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleSuspensionForce*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSuspensionForce__1getForce(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionForce* _self = (physx::vehicle2::PxVehicleSuspensionForce*) _address;
    return (jlong) &_self->force;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionForce__1setForce(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleSuspensionForce* _self = (physx::vehicle2::PxVehicleSuspensionForce*) _address;
    _self->force = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSuspensionForce__1getTorque(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionForce* _self = (physx::vehicle2::PxVehicleSuspensionForce*) _address;
    return (jlong) &_self->torque;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionForce__1setTorque(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleSuspensionForce* _self = (physx::vehicle2::PxVehicleSuspensionForce*) _address;
    _self->torque = *((physx::PxVec3*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleSuspensionForce__1getNormalForce(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionForce* _self = (physx::vehicle2::PxVehicleSuspensionForce*) _address;
    return (jfloat) _self->normalForce;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionForce__1setNormalForce(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleSuspensionForce* _self = (physx::vehicle2::PxVehicleSuspensionForce*) _address;
    _self->normalForce = value;
}

// PxVehicleSuspensionForceParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleSuspensionForceParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleSuspensionForceParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSuspensionForceParams__1PxVehicleSuspensionForceParams(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleSuspensionForceParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSuspensionForceParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    physx::vehicle2::PxVehicleSuspensionForceParams* self = (physx::vehicle2::PxVehicleSuspensionForceParams*) _address;
    static thread_local physx::vehicle2::PxVehicleSuspensionForceParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleSuspensionForceParams__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionForceParams* self = (physx::vehicle2::PxVehicleSuspensionForceParams*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionForceParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleSuspensionForceParams*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleSuspensionForceParams__1getStiffness(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionForceParams* _self = (physx::vehicle2::PxVehicleSuspensionForceParams*) _address;
    return (jfloat) _self->stiffness;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionForceParams__1setStiffness(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleSuspensionForceParams* _self = (physx::vehicle2::PxVehicleSuspensionForceParams*) _address;
    _self->stiffness = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleSuspensionForceParams__1getDamping(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionForceParams* _self = (physx::vehicle2::PxVehicleSuspensionForceParams*) _address;
    return (jfloat) _self->damping;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionForceParams__1setDamping(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleSuspensionForceParams* _self = (physx::vehicle2::PxVehicleSuspensionForceParams*) _address;
    _self->damping = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleSuspensionForceParams__1getSprungMass(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionForceParams* _self = (physx::vehicle2::PxVehicleSuspensionForceParams*) _address;
    return (jfloat) _self->sprungMass;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionForceParams__1setSprungMass(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleSuspensionForceParams* _self = (physx::vehicle2::PxVehicleSuspensionForceParams*) _address;
    _self->sprungMass = value;
}

// PxVehicleSuspensionParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleSuspensionParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleSuspensionParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSuspensionParams__1PxVehicleSuspensionParams(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleSuspensionParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSuspensionParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    physx::vehicle2::PxVehicleSuspensionParams* self = (physx::vehicle2::PxVehicleSuspensionParams*) _address;
    static thread_local physx::vehicle2::PxVehicleSuspensionParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleSuspensionParams__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionParams* self = (physx::vehicle2::PxVehicleSuspensionParams*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleSuspensionParams*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSuspensionParams__1getSuspensionAttachment(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionParams* _self = (physx::vehicle2::PxVehicleSuspensionParams*) _address;
    return (jlong) &_self->suspensionAttachment;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionParams__1setSuspensionAttachment(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleSuspensionParams* _self = (physx::vehicle2::PxVehicleSuspensionParams*) _address;
    _self->suspensionAttachment = *((physx::PxTransform*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSuspensionParams__1getSuspensionTravelDir(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionParams* _self = (physx::vehicle2::PxVehicleSuspensionParams*) _address;
    return (jlong) &_self->suspensionTravelDir;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionParams__1setSuspensionTravelDir(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleSuspensionParams* _self = (physx::vehicle2::PxVehicleSuspensionParams*) _address;
    _self->suspensionTravelDir = *((physx::PxVec3*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleSuspensionParams__1getSuspensionTravelDist(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionParams* _self = (physx::vehicle2::PxVehicleSuspensionParams*) _address;
    return (jfloat) _self->suspensionTravelDist;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionParams__1setSuspensionTravelDist(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleSuspensionParams* _self = (physx::vehicle2::PxVehicleSuspensionParams*) _address;
    _self->suspensionTravelDist = value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSuspensionParams__1getWheelAttachment(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionParams* _self = (physx::vehicle2::PxVehicleSuspensionParams*) _address;
    return (jlong) &_self->wheelAttachment;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionParams__1setWheelAttachment(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleSuspensionParams* _self = (physx::vehicle2::PxVehicleSuspensionParams*) _address;
    _self->wheelAttachment = *((physx::PxTransform*) value);
}

// PxVehicleSuspensionState
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleSuspensionState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleSuspensionState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSuspensionState__1PxVehicleSuspensionState(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleSuspensionState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionState__1setToDefault(JNIEnv*, jclass, jlong _address, jfloat _jounce, jfloat _separation) {
    physx::vehicle2::PxVehicleSuspensionState* self = (physx::vehicle2::PxVehicleSuspensionState*) _address;
    self->setToDefault(_jounce, _separation);
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleSuspensionState*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleSuspensionState__1getJounce(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionState* _self = (physx::vehicle2::PxVehicleSuspensionState*) _address;
    return (jfloat) _self->jounce;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionState__1setJounce(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleSuspensionState* _self = (physx::vehicle2::PxVehicleSuspensionState*) _address;
    _self->jounce = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleSuspensionState__1getJounceSpeed(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionState* _self = (physx::vehicle2::PxVehicleSuspensionState*) _address;
    return (jfloat) _self->jounceSpeed;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionState__1setJounceSpeed(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleSuspensionState* _self = (physx::vehicle2::PxVehicleSuspensionState*) _address;
    _self->jounceSpeed = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleSuspensionState__1getSeparation(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionState* _self = (physx::vehicle2::PxVehicleSuspensionState*) _address;
    return (jfloat) _self->separation;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionState__1setSeparation(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleSuspensionState* _self = (physx::vehicle2::PxVehicleSuspensionState*) _address;
    _self->separation = value;
}

// PxVehicleSuspensionStateCalculationParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleSuspensionStateCalculationParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleSuspensionStateCalculationParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSuspensionStateCalculationParams__1PxVehicleSuspensionStateCalculationParams(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleSuspensionStateCalculationParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleSuspensionStateCalculationParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    physx::vehicle2::PxVehicleSuspensionStateCalculationParams* self = (physx::vehicle2::PxVehicleSuspensionStateCalculationParams*) _address;
    static thread_local physx::vehicle2::PxVehicleSuspensionStateCalculationParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleSuspensionStateCalculationParams__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionStateCalculationParams* self = (physx::vehicle2::PxVehicleSuspensionStateCalculationParams*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionStateCalculationParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleSuspensionStateCalculationParams*) _address;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleSuspensionStateCalculationParams__1getSuspensionJounceCalculationType(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionStateCalculationParams* _self = (physx::vehicle2::PxVehicleSuspensionStateCalculationParams*) _address;
    return (jint) _self->suspensionJounceCalculationType;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionStateCalculationParams__1setSuspensionJounceCalculationType(JNIEnv*, jclass, jlong _address, jint value) {
    physx::vehicle2::PxVehicleSuspensionStateCalculationParams* _self = (physx::vehicle2::PxVehicleSuspensionStateCalculationParams*) _address;
    _self->suspensionJounceCalculationType = (PxVehicleSuspensionJounceCalculationTypeEnum) value;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleSuspensionStateCalculationParams__1getLimitSuspensionExpansionVelocity(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleSuspensionStateCalculationParams* _self = (physx::vehicle2::PxVehicleSuspensionStateCalculationParams*) _address;
    return (jboolean) _self->limitSuspensionExpansionVelocity;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleSuspensionStateCalculationParams__1setLimitSuspensionExpansionVelocity(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::vehicle2::PxVehicleSuspensionStateCalculationParams* _self = (physx::vehicle2::PxVehicleSuspensionStateCalculationParams*) _address;
    _self->limitSuspensionExpansionVelocity = value;
}

// PxVehicleTankDriveDifferentialParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTankDriveDifferentialParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleTankDriveDifferentialParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTankDriveDifferentialParams__1_1placement_1new_1PxVehicleTankDriveDifferentialParams(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::vehicle2::PxVehicleTankDriveDifferentialParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTankDriveDifferentialParams__1PxVehicleTankDriveDifferentialParams(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleTankDriveDifferentialParams();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTankDriveDifferentialParams__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTankDriveDifferentialParams* self = (physx::vehicle2::PxVehicleTankDriveDifferentialParams*) _address;
    self->setToDefault();
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTankDriveDifferentialParams__1getNbWheelsInTrack(JNIEnv*, jclass, jlong _address, jint i) {
    physx::vehicle2::PxVehicleTankDriveDifferentialParams* self = (physx::vehicle2::PxVehicleTankDriveDifferentialParams*) _address;
    return (jint) self->getNbWheelsInTrack(i);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTankDriveDifferentialParams__1getWheelsInTrack(JNIEnv*, jclass, jlong _address, jint i) {
    physx::vehicle2::PxVehicleTankDriveDifferentialParams* self = (physx::vehicle2::PxVehicleTankDriveDifferentialParams*) _address;
    static thread_local PxU32ConstPtr _cache = self->getWheelsInTrack(i);
    _cache = self->getWheelsInTrack(i);
    return (jlong) &_cache;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTankDriveDifferentialParams__1getWheelInTrack(JNIEnv*, jclass, jlong _address, jint j, jint i) {
    physx::vehicle2::PxVehicleTankDriveDifferentialParams* self = (physx::vehicle2::PxVehicleTankDriveDifferentialParams*) _address;
    return (jint) self->getWheelInTrack(j, i);
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTankDriveDifferentialParams__1getThrustControllerIndex(JNIEnv*, jclass, jlong _address, jint i) {
    physx::vehicle2::PxVehicleTankDriveDifferentialParams* self = (physx::vehicle2::PxVehicleTankDriveDifferentialParams*) _address;
    return (jint) self->getThrustControllerIndex(i);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTankDriveDifferentialParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    physx::vehicle2::PxVehicleTankDriveDifferentialParams* self = (physx::vehicle2::PxVehicleTankDriveDifferentialParams*) _address;
    static thread_local physx::vehicle2::PxVehicleTankDriveDifferentialParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTankDriveDifferentialParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleTankDriveDifferentialParams*) _address;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTankDriveDifferentialParams__1getNbTracks(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTankDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleTankDriveDifferentialParams*) _address;
    return (jint) _self->nbTracks;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTankDriveDifferentialParams__1setNbTracks(JNIEnv*, jclass, jlong _address, jint value) {
    physx::vehicle2::PxVehicleTankDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleTankDriveDifferentialParams*) _address;
    _self->nbTracks = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTankDriveDifferentialParams__1getThrustIdPerTrack(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleTankDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleTankDriveDifferentialParams*) _address;
    return (jint) _self->thrustIdPerTrack[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTankDriveDifferentialParams__1setThrustIdPerTrack(JNIEnv*, jclass, jlong _address, jint _index, jint value) {
    physx::vehicle2::PxVehicleTankDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleTankDriveDifferentialParams*) _address;
    _self->thrustIdPerTrack[_index] = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTankDriveDifferentialParams__1getNbWheelsPerTrack(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleTankDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleTankDriveDifferentialParams*) _address;
    return (jint) _self->nbWheelsPerTrack[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTankDriveDifferentialParams__1setNbWheelsPerTrack(JNIEnv*, jclass, jlong _address, jint _index, jint value) {
    physx::vehicle2::PxVehicleTankDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleTankDriveDifferentialParams*) _address;
    _self->nbWheelsPerTrack[_index] = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTankDriveDifferentialParams__1getTrackToWheelIds(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleTankDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleTankDriveDifferentialParams*) _address;
    return (jint) _self->trackToWheelIds[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTankDriveDifferentialParams__1setTrackToWheelIds(JNIEnv*, jclass, jlong _address, jint _index, jint value) {
    physx::vehicle2::PxVehicleTankDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleTankDriveDifferentialParams*) _address;
    _self->trackToWheelIds[_index] = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTankDriveDifferentialParams__1getWheelIdsInTrackOrder(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleTankDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleTankDriveDifferentialParams*) _address;
    return (jint) _self->wheelIdsInTrackOrder[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTankDriveDifferentialParams__1setWheelIdsInTrackOrder(JNIEnv*, jclass, jlong _address, jint _index, jint value) {
    physx::vehicle2::PxVehicleTankDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleTankDriveDifferentialParams*) _address;
    _self->wheelIdsInTrackOrder[_index] = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTankDriveDifferentialParams__1getNbWheelsInTracks(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTankDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleTankDriveDifferentialParams*) _address;
    return (jint) _self->nbWheelsInTracks;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTankDriveDifferentialParams__1setNbWheelsInTracks(JNIEnv*, jclass, jlong _address, jint value) {
    physx::vehicle2::PxVehicleTankDriveDifferentialParams* _self = (physx::vehicle2::PxVehicleTankDriveDifferentialParams*) _address;
    _self->nbWheelsInTracks = value;
}

// PxVehicleTankDriveTransmissionCommandState
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTankDriveTransmissionCommandState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleTankDriveTransmissionCommandState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTankDriveTransmissionCommandState__1PxVehicleTankDriveTransmissionCommandState(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleTankDriveTransmissionCommandState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTankDriveTransmissionCommandState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTankDriveTransmissionCommandState* self = (physx::vehicle2::PxVehicleTankDriveTransmissionCommandState*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTankDriveTransmissionCommandState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleTankDriveTransmissionCommandState*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleTankDriveTransmissionCommandState__1getThrusts(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleTankDriveTransmissionCommandState* _self = (physx::vehicle2::PxVehicleTankDriveTransmissionCommandState*) _address;
    return (jfloat) _self->thrusts[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTankDriveTransmissionCommandState__1setThrusts(JNIEnv*, jclass, jlong _address, jint _index, jfloat value) {
    physx::vehicle2::PxVehicleTankDriveTransmissionCommandState* _self = (physx::vehicle2::PxVehicleTankDriveTransmissionCommandState*) _address;
    _self->thrusts[_index] = value;
}

// PxVehicleTireAxisStickyParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTireAxisStickyParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleTireAxisStickyParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTireAxisStickyParams__1_1placement_1new_1PxVehicleTireAxisStickyParams(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::vehicle2::PxVehicleTireAxisStickyParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTireAxisStickyParams__1PxVehicleTireAxisStickyParams(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleTireAxisStickyParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTireAxisStickyParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    physx::vehicle2::PxVehicleTireAxisStickyParams* self = (physx::vehicle2::PxVehicleTireAxisStickyParams*) _address;
    static thread_local physx::vehicle2::PxVehicleTireAxisStickyParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleTireAxisStickyParams__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireAxisStickyParams* self = (physx::vehicle2::PxVehicleTireAxisStickyParams*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireAxisStickyParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleTireAxisStickyParams*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleTireAxisStickyParams__1getThresholdSpeed(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireAxisStickyParams* _self = (physx::vehicle2::PxVehicleTireAxisStickyParams*) _address;
    return (jfloat) _self->thresholdSpeed;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireAxisStickyParams__1setThresholdSpeed(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleTireAxisStickyParams* _self = (physx::vehicle2::PxVehicleTireAxisStickyParams*) _address;
    _self->thresholdSpeed = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleTireAxisStickyParams__1getThresholdTime(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireAxisStickyParams* _self = (physx::vehicle2::PxVehicleTireAxisStickyParams*) _address;
    return (jfloat) _self->thresholdTime;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireAxisStickyParams__1setThresholdTime(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleTireAxisStickyParams* _self = (physx::vehicle2::PxVehicleTireAxisStickyParams*) _address;
    _self->thresholdTime = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleTireAxisStickyParams__1getDamping(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireAxisStickyParams* _self = (physx::vehicle2::PxVehicleTireAxisStickyParams*) _address;
    return (jfloat) _self->damping;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireAxisStickyParams__1setDamping(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleTireAxisStickyParams* _self = (physx::vehicle2::PxVehicleTireAxisStickyParams*) _address;
    _self->damping = value;
}

// PxVehicleTireCamberAngleState
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTireCamberAngleState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleTireCamberAngleState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTireCamberAngleState__1PxVehicleTireCamberAngleState(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleTireCamberAngleState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireCamberAngleState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireCamberAngleState* self = (physx::vehicle2::PxVehicleTireCamberAngleState*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireCamberAngleState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleTireCamberAngleState*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleTireCamberAngleState__1getCamberAngle(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireCamberAngleState* _self = (physx::vehicle2::PxVehicleTireCamberAngleState*) _address;
    return (jfloat) _self->camberAngle;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireCamberAngleState__1setCamberAngle(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleTireCamberAngleState* _self = (physx::vehicle2::PxVehicleTireCamberAngleState*) _address;
    _self->camberAngle = value;
}

// PxVehicleTireDirectionState
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTireDirectionState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleTireDirectionState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTireDirectionState__1PxVehicleTireDirectionState(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleTireDirectionState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireDirectionState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireDirectionState* self = (physx::vehicle2::PxVehicleTireDirectionState*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireDirectionState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleTireDirectionState*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTireDirectionState__1getDirections(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleTireDirectionState* _self = (physx::vehicle2::PxVehicleTireDirectionState*) _address;
    return (jlong) &_self->directions[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireDirectionState__1setDirections(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    physx::vehicle2::PxVehicleTireDirectionState* _self = (physx::vehicle2::PxVehicleTireDirectionState*) _address;
    _self->directions[_index] = *((physx::PxVec3*) value);
}

// PxVehicleTireForce
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTireForce__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleTireForce);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTireForce__1PxVehicleTireForce(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleTireForce();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireForce__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireForce* self = (physx::vehicle2::PxVehicleTireForce*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireForce__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleTireForce*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTireForce__1getForces(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleTireForce* _self = (physx::vehicle2::PxVehicleTireForce*) _address;
    return (jlong) &_self->forces[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireForce__1setForces(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    physx::vehicle2::PxVehicleTireForce* _self = (physx::vehicle2::PxVehicleTireForce*) _address;
    _self->forces[_index] = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTireForce__1getTorques(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleTireForce* _self = (physx::vehicle2::PxVehicleTireForce*) _address;
    return (jlong) &_self->torques[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireForce__1setTorques(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    physx::vehicle2::PxVehicleTireForce* _self = (physx::vehicle2::PxVehicleTireForce*) _address;
    _self->torques[_index] = *((physx::PxVec3*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleTireForce__1getAligningMoment(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireForce* _self = (physx::vehicle2::PxVehicleTireForce*) _address;
    return (jfloat) _self->aligningMoment;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireForce__1setAligningMoment(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleTireForce* _self = (physx::vehicle2::PxVehicleTireForce*) _address;
    _self->aligningMoment = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleTireForce__1getWheelTorque(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireForce* _self = (physx::vehicle2::PxVehicleTireForce*) _address;
    return (jfloat) _self->wheelTorque;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireForce__1setWheelTorque(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleTireForce* _self = (physx::vehicle2::PxVehicleTireForce*) _address;
    _self->wheelTorque = value;
}

// PxVehicleTireForceParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTireForceParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleTireForceParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTireForceParams__1PxVehicleTireForceParams(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleTireForceParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTireForceParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    physx::vehicle2::PxVehicleTireForceParams* self = (physx::vehicle2::PxVehicleTireForceParams*) _address;
    static thread_local physx::vehicle2::PxVehicleTireForceParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleTireForceParams__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireForceParams* self = (physx::vehicle2::PxVehicleTireForceParams*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireForceParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleTireForceParams*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleTireForceParams__1getLatStiffX(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireForceParams* _self = (physx::vehicle2::PxVehicleTireForceParams*) _address;
    return (jfloat) _self->latStiffX;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireForceParams__1setLatStiffX(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleTireForceParams* _self = (physx::vehicle2::PxVehicleTireForceParams*) _address;
    _self->latStiffX = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleTireForceParams__1getLatStiffY(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireForceParams* _self = (physx::vehicle2::PxVehicleTireForceParams*) _address;
    return (jfloat) _self->latStiffY;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireForceParams__1setLatStiffY(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleTireForceParams* _self = (physx::vehicle2::PxVehicleTireForceParams*) _address;
    _self->latStiffY = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleTireForceParams__1getLongStiff(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireForceParams* _self = (physx::vehicle2::PxVehicleTireForceParams*) _address;
    return (jfloat) _self->longStiff;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireForceParams__1setLongStiff(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleTireForceParams* _self = (physx::vehicle2::PxVehicleTireForceParams*) _address;
    _self->longStiff = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleTireForceParams__1getCamberStiff(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireForceParams* _self = (physx::vehicle2::PxVehicleTireForceParams*) _address;
    return (jfloat) _self->camberStiff;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireForceParams__1setCamberStiff(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleTireForceParams* _self = (physx::vehicle2::PxVehicleTireForceParams*) _address;
    _self->camberStiff = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleTireForceParams__1getRestLoad(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireForceParams* _self = (physx::vehicle2::PxVehicleTireForceParams*) _address;
    return (jfloat) _self->restLoad;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireForceParams__1setRestLoad(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleTireForceParams* _self = (physx::vehicle2::PxVehicleTireForceParams*) _address;
    _self->restLoad = value;
}

// PxVehicleTireForceParamsExt
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTireForceParamsExt__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxVehicleTireForceParamsExt);
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireForceParamsExt__1setFrictionVsSlip(JNIEnv*, jclass, jlong tireForceParams, jint i, jint j, jfloat value) {
    PxVehicleTireForceParamsExt::setFrictionVsSlip((physx::vehicle2::PxVehicleTireForceParams*) tireForceParams, i, j, value);
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireForceParamsExt__1setLoadFilter(JNIEnv*, jclass, jlong tireForceParams, jint i, jint j, jfloat value) {
    PxVehicleTireForceParamsExt::setLoadFilter((physx::vehicle2::PxVehicleTireForceParams*) tireForceParams, i, j, value);
}

// PxVehicleTireGripState
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTireGripState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleTireGripState);
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireGripState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireGripState* self = (physx::vehicle2::PxVehicleTireGripState*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireGripState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleTireGripState*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleTireGripState__1getLoad(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireGripState* _self = (physx::vehicle2::PxVehicleTireGripState*) _address;
    return (jfloat) _self->load;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireGripState__1setLoad(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleTireGripState* _self = (physx::vehicle2::PxVehicleTireGripState*) _address;
    _self->load = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleTireGripState__1getFriction(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireGripState* _self = (physx::vehicle2::PxVehicleTireGripState*) _address;
    return (jfloat) _self->friction;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireGripState__1setFriction(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleTireGripState* _self = (physx::vehicle2::PxVehicleTireGripState*) _address;
    _self->friction = value;
}

// PxVehicleTireSlipParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTireSlipParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleTireSlipParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTireSlipParams__1_1placement_1new_1PxVehicleTireSlipParams(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::vehicle2::PxVehicleTireSlipParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTireSlipParams__1PxVehicleTireSlipParams(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleTireSlipParams();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireSlipParams__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireSlipParams* self = (physx::vehicle2::PxVehicleTireSlipParams*) _address;
    self->setToDefault();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTireSlipParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    physx::vehicle2::PxVehicleTireSlipParams* self = (physx::vehicle2::PxVehicleTireSlipParams*) _address;
    static thread_local physx::vehicle2::PxVehicleTireSlipParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleTireSlipParams__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireSlipParams* self = (physx::vehicle2::PxVehicleTireSlipParams*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireSlipParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleTireSlipParams*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleTireSlipParams__1getMinLatSlipDenominator(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireSlipParams* _self = (physx::vehicle2::PxVehicleTireSlipParams*) _address;
    return (jfloat) _self->minLatSlipDenominator;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireSlipParams__1setMinLatSlipDenominator(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleTireSlipParams* _self = (physx::vehicle2::PxVehicleTireSlipParams*) _address;
    _self->minLatSlipDenominator = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleTireSlipParams__1getMinPassiveLongSlipDenominator(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireSlipParams* _self = (physx::vehicle2::PxVehicleTireSlipParams*) _address;
    return (jfloat) _self->minPassiveLongSlipDenominator;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireSlipParams__1setMinPassiveLongSlipDenominator(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleTireSlipParams* _self = (physx::vehicle2::PxVehicleTireSlipParams*) _address;
    _self->minPassiveLongSlipDenominator = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleTireSlipParams__1getMinActiveLongSlipDenominator(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireSlipParams* _self = (physx::vehicle2::PxVehicleTireSlipParams*) _address;
    return (jfloat) _self->minActiveLongSlipDenominator;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireSlipParams__1setMinActiveLongSlipDenominator(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleTireSlipParams* _self = (physx::vehicle2::PxVehicleTireSlipParams*) _address;
    _self->minActiveLongSlipDenominator = value;
}

// PxVehicleTireSlipState
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTireSlipState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleTireSlipState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTireSlipState__1PxVehicleTireSlipState(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleTireSlipState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireSlipState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireSlipState* self = (physx::vehicle2::PxVehicleTireSlipState*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireSlipState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleTireSlipState*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleTireSlipState__1getSlips(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleTireSlipState* _self = (physx::vehicle2::PxVehicleTireSlipState*) _address;
    return (jfloat) _self->slips[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireSlipState__1setSlips(JNIEnv*, jclass, jlong _address, jint _index, jfloat value) {
    physx::vehicle2::PxVehicleTireSlipState* _self = (physx::vehicle2::PxVehicleTireSlipState*) _address;
    _self->slips[_index] = value;
}

// PxVehicleTireSpeedState
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTireSpeedState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleTireSpeedState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTireSpeedState__1PxVehicleTireSpeedState(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleTireSpeedState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireSpeedState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireSpeedState* self = (physx::vehicle2::PxVehicleTireSpeedState*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireSpeedState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleTireSpeedState*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleTireSpeedState__1getSpeedStates(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleTireSpeedState* _self = (physx::vehicle2::PxVehicleTireSpeedState*) _address;
    return (jfloat) _self->speedStates[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireSpeedState__1setSpeedStates(JNIEnv*, jclass, jlong _address, jint _index, jfloat value) {
    physx::vehicle2::PxVehicleTireSpeedState* _self = (physx::vehicle2::PxVehicleTireSpeedState*) _address;
    _self->speedStates[_index] = value;
}

// PxVehicleTireStickyParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTireStickyParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleTireStickyParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTireStickyParams__1_1placement_1new_1PxVehicleTireStickyParams(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::vehicle2::PxVehicleTireStickyParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTireStickyParams__1PxVehicleTireStickyParams(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleTireStickyParams();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireStickyParams__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireStickyParams* self = (physx::vehicle2::PxVehicleTireStickyParams*) _address;
    self->setToDefault();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTireStickyParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    physx::vehicle2::PxVehicleTireStickyParams* self = (physx::vehicle2::PxVehicleTireStickyParams*) _address;
    static thread_local physx::vehicle2::PxVehicleTireStickyParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleTireStickyParams__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireStickyParams* self = (physx::vehicle2::PxVehicleTireStickyParams*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireStickyParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleTireStickyParams*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTireStickyParams__1getStickyParams(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleTireStickyParams* _self = (physx::vehicle2::PxVehicleTireStickyParams*) _address;
    return (jlong) &_self->stickyParams[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireStickyParams__1setStickyParams(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    physx::vehicle2::PxVehicleTireStickyParams* _self = (physx::vehicle2::PxVehicleTireStickyParams*) _address;
    _self->stickyParams[_index] = *((physx::vehicle2::PxVehicleTireAxisStickyParams*) value);
}

// PxVehicleTireStickyState
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTireStickyState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleTireStickyState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTireStickyState__1PxVehicleTireStickyState(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleTireStickyState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireStickyState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleTireStickyState* self = (physx::vehicle2::PxVehicleTireStickyState*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireStickyState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleTireStickyState*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleTireStickyState__1getLowSpeedTime(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleTireStickyState* _self = (physx::vehicle2::PxVehicleTireStickyState*) _address;
    return (jfloat) _self->lowSpeedTime[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireStickyState__1setLowSpeedTime(JNIEnv*, jclass, jlong _address, jint _index, jfloat value) {
    physx::vehicle2::PxVehicleTireStickyState* _self = (physx::vehicle2::PxVehicleTireStickyState*) _address;
    _self->lowSpeedTime[_index] = value;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleTireStickyState__1getActiveStatus(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleTireStickyState* _self = (physx::vehicle2::PxVehicleTireStickyState*) _address;
    return (jboolean) _self->activeStatus[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTireStickyState__1setActiveStatus(JNIEnv*, jclass, jlong _address, jint _index, jboolean value) {
    physx::vehicle2::PxVehicleTireStickyState* _self = (physx::vehicle2::PxVehicleTireStickyState*) _address;
    _self->activeStatus[_index] = value;
}

// PxVehicleTorqueCurveLookupTable
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTorqueCurveLookupTable__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(PxVehicleTorqueCurveLookupTable);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleTorqueCurveLookupTable__1PxVehicleTorqueCurveLookupTable(JNIEnv*, jclass) {
    return (jlong) new PxVehicleTorqueCurveLookupTable();
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleTorqueCurveLookupTable__1addPair(JNIEnv*, jclass, jlong _address, jfloat x, jfloat y) {
    PxVehicleTorqueCurveLookupTable* self = (PxVehicleTorqueCurveLookupTable*) _address;
    return (jboolean) self->addPair(x, y);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleTorqueCurveLookupTable__1interpolate(JNIEnv*, jclass, jlong _address, jfloat x) {
    PxVehicleTorqueCurveLookupTable* self = (PxVehicleTorqueCurveLookupTable*) _address;
    return (jfloat) self->interpolate(x);
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTorqueCurveLookupTable__1clear(JNIEnv*, jclass, jlong _address) {
    PxVehicleTorqueCurveLookupTable* self = (PxVehicleTorqueCurveLookupTable*) _address;
    self->clear();
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleTorqueCurveLookupTable__1isValid(JNIEnv*, jclass, jlong _address) {
    PxVehicleTorqueCurveLookupTable* self = (PxVehicleTorqueCurveLookupTable*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleTorqueCurveLookupTable__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxVehicleTorqueCurveLookupTable*) _address;
}

// PxVehicleWheelActuationState
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleWheelActuationState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleWheelActuationState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleWheelActuationState__1PxVehicleWheelActuationState(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleWheelActuationState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleWheelActuationState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleWheelActuationState* self = (physx::vehicle2::PxVehicleWheelActuationState*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleWheelActuationState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleWheelActuationState*) _address;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleWheelActuationState__1getIsBrakeApplied(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleWheelActuationState* _self = (physx::vehicle2::PxVehicleWheelActuationState*) _address;
    return (jboolean) _self->isBrakeApplied;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleWheelActuationState__1setIsBrakeApplied(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::vehicle2::PxVehicleWheelActuationState* _self = (physx::vehicle2::PxVehicleWheelActuationState*) _address;
    _self->isBrakeApplied = value;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleWheelActuationState__1getIsDriveApplied(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleWheelActuationState* _self = (physx::vehicle2::PxVehicleWheelActuationState*) _address;
    return (jboolean) _self->isDriveApplied;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleWheelActuationState__1setIsDriveApplied(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::vehicle2::PxVehicleWheelActuationState* _self = (physx::vehicle2::PxVehicleWheelActuationState*) _address;
    _self->isDriveApplied = value;
}

// PxVehicleWheelConstraintGroupState
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleWheelConstraintGroupState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleWheelConstraintGroupState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleWheelConstraintGroupState__1PxVehicleWheelConstraintGroupState(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleWheelConstraintGroupState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleWheelConstraintGroupState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleWheelConstraintGroupState* self = (physx::vehicle2::PxVehicleWheelConstraintGroupState*) _address;
    self->setToDefault();
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleWheelConstraintGroupState__1getNbConstraintGroups(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleWheelConstraintGroupState* self = (physx::vehicle2::PxVehicleWheelConstraintGroupState*) _address;
    return (jint) self->getNbConstraintGroups();
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleWheelConstraintGroupState__1getNbWheelsInConstraintGroup(JNIEnv*, jclass, jlong _address, jint i) {
    physx::vehicle2::PxVehicleWheelConstraintGroupState* self = (physx::vehicle2::PxVehicleWheelConstraintGroupState*) _address;
    return (jint) self->getNbWheelsInConstraintGroup(i);
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleWheelConstraintGroupState__1getWheelInConstraintGroup(JNIEnv*, jclass, jlong _address, jint j, jint i) {
    physx::vehicle2::PxVehicleWheelConstraintGroupState* self = (physx::vehicle2::PxVehicleWheelConstraintGroupState*) _address;
    return (jint) self->getWheelInConstraintGroup(j, i);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleWheelConstraintGroupState__1getMultiplierInConstraintGroup(JNIEnv*, jclass, jlong _address, jint j, jint i) {
    physx::vehicle2::PxVehicleWheelConstraintGroupState* self = (physx::vehicle2::PxVehicleWheelConstraintGroupState*) _address;
    return (jfloat) self->getMultiplierInConstraintGroup(j, i);
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleWheelConstraintGroupState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleWheelConstraintGroupState*) _address;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleWheelConstraintGroupState__1getNbGroups(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleWheelConstraintGroupState* _self = (physx::vehicle2::PxVehicleWheelConstraintGroupState*) _address;
    return (jint) _self->nbGroups;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleWheelConstraintGroupState__1setNbGroups(JNIEnv*, jclass, jlong _address, jint value) {
    physx::vehicle2::PxVehicleWheelConstraintGroupState* _self = (physx::vehicle2::PxVehicleWheelConstraintGroupState*) _address;
    _self->nbGroups = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleWheelConstraintGroupState__1getNbWheelsPerGroup(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleWheelConstraintGroupState* _self = (physx::vehicle2::PxVehicleWheelConstraintGroupState*) _address;
    return (jint) _self->nbWheelsPerGroup[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleWheelConstraintGroupState__1setNbWheelsPerGroup(JNIEnv*, jclass, jlong _address, jint _index, jint value) {
    physx::vehicle2::PxVehicleWheelConstraintGroupState* _self = (physx::vehicle2::PxVehicleWheelConstraintGroupState*) _address;
    _self->nbWheelsPerGroup[_index] = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleWheelConstraintGroupState__1getGroupToWheelIds(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleWheelConstraintGroupState* _self = (physx::vehicle2::PxVehicleWheelConstraintGroupState*) _address;
    return (jint) _self->groupToWheelIds[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleWheelConstraintGroupState__1setGroupToWheelIds(JNIEnv*, jclass, jlong _address, jint _index, jint value) {
    physx::vehicle2::PxVehicleWheelConstraintGroupState* _self = (physx::vehicle2::PxVehicleWheelConstraintGroupState*) _address;
    _self->groupToWheelIds[_index] = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleWheelConstraintGroupState__1getWheelIdsInGroupOrder(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleWheelConstraintGroupState* _self = (physx::vehicle2::PxVehicleWheelConstraintGroupState*) _address;
    return (jint) _self->wheelIdsInGroupOrder[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleWheelConstraintGroupState__1setWheelIdsInGroupOrder(JNIEnv*, jclass, jlong _address, jint _index, jint value) {
    physx::vehicle2::PxVehicleWheelConstraintGroupState* _self = (physx::vehicle2::PxVehicleWheelConstraintGroupState*) _address;
    _self->wheelIdsInGroupOrder[_index] = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleWheelConstraintGroupState__1getWheelMultipliersInGroupOrder(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::vehicle2::PxVehicleWheelConstraintGroupState* _self = (physx::vehicle2::PxVehicleWheelConstraintGroupState*) _address;
    return (jfloat) _self->wheelMultipliersInGroupOrder[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleWheelConstraintGroupState__1setWheelMultipliersInGroupOrder(JNIEnv*, jclass, jlong _address, jint _index, jfloat value) {
    physx::vehicle2::PxVehicleWheelConstraintGroupState* _self = (physx::vehicle2::PxVehicleWheelConstraintGroupState*) _address;
    _self->wheelMultipliersInGroupOrder[_index] = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleWheelConstraintGroupState__1getNbWheelsInGroups(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleWheelConstraintGroupState* _self = (physx::vehicle2::PxVehicleWheelConstraintGroupState*) _address;
    return (jint) _self->nbWheelsInGroups;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleWheelConstraintGroupState__1setNbWheelsInGroups(JNIEnv*, jclass, jlong _address, jint value) {
    physx::vehicle2::PxVehicleWheelConstraintGroupState* _self = (physx::vehicle2::PxVehicleWheelConstraintGroupState*) _address;
    _self->nbWheelsInGroups = value;
}

// PxVehicleWheelLocalPose
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleWheelLocalPose__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleWheelLocalPose);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleWheelLocalPose__1PxVehicleWheelLocalPose(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleWheelLocalPose();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleWheelLocalPose__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleWheelLocalPose* self = (physx::vehicle2::PxVehicleWheelLocalPose*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleWheelLocalPose__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleWheelLocalPose*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleWheelLocalPose__1getLocalPose(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleWheelLocalPose* _self = (physx::vehicle2::PxVehicleWheelLocalPose*) _address;
    return (jlong) &_self->localPose;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleWheelLocalPose__1setLocalPose(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::vehicle2::PxVehicleWheelLocalPose* _self = (physx::vehicle2::PxVehicleWheelLocalPose*) _address;
    _self->localPose = *((physx::PxTransform*) value);
}

// PxVehicleWheelParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleWheelParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleWheelParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleWheelParams__1PxVehicleWheelParams(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleWheelParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleWheelParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    physx::vehicle2::PxVehicleWheelParams* self = (physx::vehicle2::PxVehicleWheelParams*) _address;
    static thread_local physx::vehicle2::PxVehicleWheelParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PxVehicleWheelParams__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleWheelParams* self = (physx::vehicle2::PxVehicleWheelParams*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleWheelParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleWheelParams*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleWheelParams__1getRadius(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleWheelParams* _self = (physx::vehicle2::PxVehicleWheelParams*) _address;
    return (jfloat) _self->radius;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleWheelParams__1setRadius(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleWheelParams* _self = (physx::vehicle2::PxVehicleWheelParams*) _address;
    _self->radius = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleWheelParams__1getHalfWidth(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleWheelParams* _self = (physx::vehicle2::PxVehicleWheelParams*) _address;
    return (jfloat) _self->halfWidth;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleWheelParams__1setHalfWidth(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleWheelParams* _self = (physx::vehicle2::PxVehicleWheelParams*) _address;
    _self->halfWidth = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleWheelParams__1getMass(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleWheelParams* _self = (physx::vehicle2::PxVehicleWheelParams*) _address;
    return (jfloat) _self->mass;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleWheelParams__1setMass(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleWheelParams* _self = (physx::vehicle2::PxVehicleWheelParams*) _address;
    _self->mass = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleWheelParams__1getMoi(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleWheelParams* _self = (physx::vehicle2::PxVehicleWheelParams*) _address;
    return (jfloat) _self->moi;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleWheelParams__1setMoi(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleWheelParams* _self = (physx::vehicle2::PxVehicleWheelParams*) _address;
    _self->moi = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleWheelParams__1getDampingRate(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleWheelParams* _self = (physx::vehicle2::PxVehicleWheelParams*) _address;
    return (jfloat) _self->dampingRate;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleWheelParams__1setDampingRate(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleWheelParams* _self = (physx::vehicle2::PxVehicleWheelParams*) _address;
    _self->dampingRate = value;
}

// PxVehicleWheelRigidBody1dState
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleWheelRigidBody1dState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::vehicle2::PxVehicleWheelRigidBody1dState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PxVehicleWheelRigidBody1dState__1PxVehicleWheelRigidBody1dState(JNIEnv*, jclass) {
    return (jlong) new physx::vehicle2::PxVehicleWheelRigidBody1dState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleWheelRigidBody1dState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleWheelRigidBody1dState* self = (physx::vehicle2::PxVehicleWheelRigidBody1dState*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleWheelRigidBody1dState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::vehicle2::PxVehicleWheelRigidBody1dState*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleWheelRigidBody1dState__1getRotationSpeed(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleWheelRigidBody1dState* _self = (physx::vehicle2::PxVehicleWheelRigidBody1dState*) _address;
    return (jfloat) _self->rotationSpeed;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleWheelRigidBody1dState__1setRotationSpeed(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleWheelRigidBody1dState* _self = (physx::vehicle2::PxVehicleWheelRigidBody1dState*) _address;
    _self->rotationSpeed = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleWheelRigidBody1dState__1getCorrectedRotationSpeed(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleWheelRigidBody1dState* _self = (physx::vehicle2::PxVehicleWheelRigidBody1dState*) _address;
    return (jfloat) _self->correctedRotationSpeed;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleWheelRigidBody1dState__1setCorrectedRotationSpeed(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleWheelRigidBody1dState* _self = (physx::vehicle2::PxVehicleWheelRigidBody1dState*) _address;
    _self->correctedRotationSpeed = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_PxVehicleWheelRigidBody1dState__1getRotationAngle(JNIEnv*, jclass, jlong _address) {
    physx::vehicle2::PxVehicleWheelRigidBody1dState* _self = (physx::vehicle2::PxVehicleWheelRigidBody1dState*) _address;
    return (jfloat) _self->rotationAngle;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PxVehicleWheelRigidBody1dState__1setRotationAngle(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::vehicle2::PxVehicleWheelRigidBody1dState* _self = (physx::vehicle2::PxVehicleWheelRigidBody1dState*) _address;
    _self->rotationAngle = value;
}

// BaseVehicleParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_BaseVehicleParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(snippetvehicle2::BaseVehicleParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleParams__1BaseVehicleParams(JNIEnv*, jclass) {
    return (jlong) new snippetvehicle2::BaseVehicleParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    snippetvehicle2::BaseVehicleParams* self = (snippetvehicle2::BaseVehicleParams*) _address;
    static thread_local snippetvehicle2::BaseVehicleParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_BaseVehicleParams__1isValid(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::BaseVehicleParams* self = (snippetvehicle2::BaseVehicleParams*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (snippetvehicle2::BaseVehicleParams*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleParams__1getAxleDescription(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    return (jlong) &_self->axleDescription;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleParams__1setAxleDescription(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    _self->axleDescription = *((physx::vehicle2::PxVehicleAxleDescription*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleParams__1getFrame(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    return (jlong) &_self->frame;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleParams__1setFrame(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    _self->frame = *((physx::vehicle2::PxVehicleFrame*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleParams__1getScale(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    return (jlong) &_self->scale;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleParams__1setScale(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    _self->scale = *((physx::vehicle2::PxVehicleScale*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleParams__1getSuspensionStateCalculationParams(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    return (jlong) &_self->suspensionStateCalculationParams;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleParams__1setSuspensionStateCalculationParams(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    _self->suspensionStateCalculationParams = *((physx::vehicle2::PxVehicleSuspensionStateCalculationParams*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleParams__1getBrakeResponseParams(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    return (jlong) &_self->brakeResponseParams[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleParams__1setBrakeResponseParams(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    _self->brakeResponseParams[_index] = *((physx::vehicle2::PxVehicleBrakeCommandResponseParams*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleParams__1getSteerResponseParams(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    return (jlong) &_self->steerResponseParams;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleParams__1setSteerResponseParams(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    _self->steerResponseParams = *((physx::vehicle2::PxVehicleSteerCommandResponseParams*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleParams__1getAckermannParams(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    return (jlong) &_self->ackermannParams[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleParams__1setAckermannParams(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    _self->ackermannParams[_index] = *((physx::vehicle2::PxVehicleAckermannParams*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleParams__1getSuspensionParams(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    return (jlong) &_self->suspensionParams[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleParams__1setSuspensionParams(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    _self->suspensionParams[_index] = *((physx::vehicle2::PxVehicleSuspensionParams*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleParams__1getSuspensionComplianceParams(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    return (jlong) &_self->suspensionComplianceParams[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleParams__1setSuspensionComplianceParams(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    _self->suspensionComplianceParams[_index] = *((physx::vehicle2::PxVehicleSuspensionComplianceParams*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleParams__1getSuspensionForceParams(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    return (jlong) &_self->suspensionForceParams[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleParams__1setSuspensionForceParams(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    _self->suspensionForceParams[_index] = *((physx::vehicle2::PxVehicleSuspensionForceParams*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleParams__1getAntiRollForceParams(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    return (jlong) &_self->antiRollForceParams[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleParams__1setAntiRollForceParams(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    _self->antiRollForceParams[_index] = *((physx::vehicle2::PxVehicleAntiRollForceParams*) value);
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_BaseVehicleParams__1getNbAntiRollForceParams(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    return (jint) _self->nbAntiRollForceParams;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleParams__1setNbAntiRollForceParams(JNIEnv*, jclass, jlong _address, jint value) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    _self->nbAntiRollForceParams = value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleParams__1getTireForceParams(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    return (jlong) &_self->tireForceParams[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleParams__1setTireForceParams(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    _self->tireForceParams[_index] = *((physx::vehicle2::PxVehicleTireForceParams*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleParams__1getWheelParams(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    return (jlong) &_self->wheelParams[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleParams__1setWheelParams(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    _self->wheelParams[_index] = *((physx::vehicle2::PxVehicleWheelParams*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleParams__1getRigidBodyParams(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    return (jlong) &_self->rigidBodyParams;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleParams__1setRigidBodyParams(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::BaseVehicleParams* _self = (snippetvehicle2::BaseVehicleParams*) _address;
    _self->rigidBodyParams = *((physx::vehicle2::PxVehicleRigidBodyParams*) value);
}

// BaseVehicleState
JNIEXPORT jint JNICALL Java_physx_vehicle2_BaseVehicleState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(snippetvehicle2::BaseVehicleState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleState__1BaseVehicleState(JNIEnv*, jclass) {
    return (jlong) new snippetvehicle2::BaseVehicleState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::BaseVehicleState* self = (snippetvehicle2::BaseVehicleState*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (snippetvehicle2::BaseVehicleState*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_BaseVehicleState__1getBrakeCommandResponseStates(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    return (jfloat) _self->brakeCommandResponseStates[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleState__1setBrakeCommandResponseStates(JNIEnv*, jclass, jlong _address, jint _index, jfloat value) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    _self->brakeCommandResponseStates[_index] = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_BaseVehicleState__1getSteerCommandResponseStates(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    return (jfloat) _self->steerCommandResponseStates[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleState__1setSteerCommandResponseStates(JNIEnv*, jclass, jlong _address, jint _index, jfloat value) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    _self->steerCommandResponseStates[_index] = value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleState__1getActuationStates(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    return (jlong) &_self->actuationStates[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleState__1setActuationStates(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    _self->actuationStates[_index] = *((physx::vehicle2::PxVehicleWheelActuationState*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleState__1getRoadGeomStates(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    return (jlong) &_self->roadGeomStates[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleState__1setRoadGeomStates(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    _self->roadGeomStates[_index] = *((physx::vehicle2::PxVehicleRoadGeometryState*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleState__1getSuspensionStates(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    return (jlong) &_self->suspensionStates[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleState__1setSuspensionStates(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    _self->suspensionStates[_index] = *((physx::vehicle2::PxVehicleSuspensionState*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleState__1getSuspensionComplianceStates(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    return (jlong) &_self->suspensionComplianceStates[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleState__1setSuspensionComplianceStates(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    _self->suspensionComplianceStates[_index] = *((physx::vehicle2::PxVehicleSuspensionComplianceState*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleState__1getSuspensionForces(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    return (jlong) &_self->suspensionForces[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleState__1setSuspensionForces(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    _self->suspensionForces[_index] = *((physx::vehicle2::PxVehicleSuspensionForce*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleState__1getAntiRollTorque(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    return (jlong) &_self->antiRollTorque;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleState__1setAntiRollTorque(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    _self->antiRollTorque = *((physx::vehicle2::PxVehicleAntiRollTorque*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleState__1getTireGripStates(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    return (jlong) &_self->tireGripStates[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleState__1setTireGripStates(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    _self->tireGripStates[_index] = *((physx::vehicle2::PxVehicleTireGripState*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleState__1getTireDirectionStates(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    return (jlong) &_self->tireDirectionStates[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleState__1setTireDirectionStates(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    _self->tireDirectionStates[_index] = *((physx::vehicle2::PxVehicleTireDirectionState*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleState__1getTireSpeedStates(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    return (jlong) &_self->tireSpeedStates[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleState__1setTireSpeedStates(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    _self->tireSpeedStates[_index] = *((physx::vehicle2::PxVehicleTireSpeedState*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleState__1getTireSlipStates(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    return (jlong) &_self->tireSlipStates[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleState__1setTireSlipStates(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    _self->tireSlipStates[_index] = *((physx::vehicle2::PxVehicleTireSlipState*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleState__1getTireCamberAngleStates(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    return (jlong) &_self->tireCamberAngleStates[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleState__1setTireCamberAngleStates(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    _self->tireCamberAngleStates[_index] = *((physx::vehicle2::PxVehicleTireCamberAngleState*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleState__1getTireStickyStates(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    return (jlong) &_self->tireStickyStates[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleState__1setTireStickyStates(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    _self->tireStickyStates[_index] = *((physx::vehicle2::PxVehicleTireStickyState*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleState__1getTireForces(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    return (jlong) &_self->tireForces[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleState__1setTireForces(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    _self->tireForces[_index] = *((physx::vehicle2::PxVehicleTireForce*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleState__1getWheelRigidBody1dStates(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    return (jlong) &_self->wheelRigidBody1dStates[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleState__1setWheelRigidBody1dStates(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    _self->wheelRigidBody1dStates[_index] = *((physx::vehicle2::PxVehicleWheelRigidBody1dState*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleState__1getWheelLocalPoses(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    return (jlong) &_self->wheelLocalPoses[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleState__1setWheelLocalPoses(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    _self->wheelLocalPoses[_index] = *((physx::vehicle2::PxVehicleWheelLocalPose*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicleState__1getRigidBodyState(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    return (jlong) &_self->rigidBodyState;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicleState__1setRigidBodyState(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::BaseVehicleState* _self = (snippetvehicle2::BaseVehicleState*) _address;
    _self->rigidBodyState = *((physx::vehicle2::PxVehicleRigidBodyState*) value);
}

// PhysXIntegrationParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(snippetvehicle2::PhysXIntegrationParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1PhysXIntegrationParams(JNIEnv*, jclass) {
    return (jlong) new snippetvehicle2::PhysXIntegrationParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    snippetvehicle2::PhysXIntegrationParams* self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    static thread_local snippetvehicle2::PhysXIntegrationParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1isValid(JNIEnv*, jclass, jlong _address, jlong axleDesc) {
    snippetvehicle2::PhysXIntegrationParams* self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    return (jboolean) self->isValid(*((physx::vehicle2::PxVehicleAxleDescription*) axleDesc));
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1create(JNIEnv*, jclass, jlong _address, jlong axleDesc, jlong roadQueryFilterData, jlong roadQueryFilterCallback, jlong materialFrictions, jint nbMaterialFrictions, jfloat defaultFriction, jlong physxActorCMassLocalPose, jlong actorGeometry, jlong physxActorBoxShapeLocalPose, jint roadGeometryQueryType) {
    snippetvehicle2::PhysXIntegrationParams* self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    self->create(*((physx::vehicle2::PxVehicleAxleDescription*) axleDesc), *((physx::PxQueryFilterData*) roadQueryFilterData), (physx::PxQueryFilterCallback*) roadQueryFilterCallback, (physx::vehicle2::PxVehiclePhysXMaterialFriction*) materialFrictions, nbMaterialFrictions, defaultFriction, *((physx::PxTransform*) physxActorCMassLocalPose), *((physx::PxGeometry*) actorGeometry), *((physx::PxTransform*) physxActorBoxShapeLocalPose), (PxVehiclePhysXRoadGeometryQueryTypeEnum) roadGeometryQueryType);
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (snippetvehicle2::PhysXIntegrationParams*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1getPhysxRoadGeometryQueryParams(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::PhysXIntegrationParams* _self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    return (jlong) &_self->physxRoadGeometryQueryParams;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1setPhysxRoadGeometryQueryParams(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::PhysXIntegrationParams* _self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    _self->physxRoadGeometryQueryParams = *((physx::vehicle2::PxVehiclePhysXRoadGeometryQueryParams*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1getPhysxMaterialFrictionParams(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::PhysXIntegrationParams* _self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    return (jlong) &_self->physxMaterialFrictionParams[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1setPhysxMaterialFrictionParams(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    snippetvehicle2::PhysXIntegrationParams* _self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    _self->physxMaterialFrictionParams[_index] = *((physx::vehicle2::PxVehiclePhysXMaterialFrictionParams*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1getPhysxSuspensionLimitConstraintParams(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::PhysXIntegrationParams* _self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    return (jlong) &_self->physxSuspensionLimitConstraintParams[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1setPhysxSuspensionLimitConstraintParams(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    snippetvehicle2::PhysXIntegrationParams* _self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    _self->physxSuspensionLimitConstraintParams[_index] = *((physx::vehicle2::PxVehiclePhysXSuspensionLimitConstraintParams*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1getPhysxActorCMassLocalPose(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::PhysXIntegrationParams* _self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    return (jlong) &_self->physxActorCMassLocalPose;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1setPhysxActorCMassLocalPose(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::PhysXIntegrationParams* _self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    _self->physxActorCMassLocalPose = *((physx::PxTransform*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1getPhysxActorGeometry(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::PhysXIntegrationParams* _self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    return (jlong) _self->physxActorGeometry;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1setPhysxActorGeometry(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::PhysXIntegrationParams* _self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    _self->physxActorGeometry = (physx::PxGeometry*) value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1getPhysxActorBoxShapeLocalPose(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::PhysXIntegrationParams* _self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    return (jlong) &_self->physxActorBoxShapeLocalPose;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1setPhysxActorBoxShapeLocalPose(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::PhysXIntegrationParams* _self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    _self->physxActorBoxShapeLocalPose = *((physx::PxTransform*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1getPhysxWheelShapeLocalPoses(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::PhysXIntegrationParams* _self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    return (jlong) &_self->physxWheelShapeLocalPoses[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1setPhysxWheelShapeLocalPoses(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    snippetvehicle2::PhysXIntegrationParams* _self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    _self->physxWheelShapeLocalPoses[_index] = *((physx::PxTransform*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1getPhysxActorShapeFlags(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::PhysXIntegrationParams* _self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    return (jlong) &_self->physxActorShapeFlags;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1setPhysxActorShapeFlags(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::PhysXIntegrationParams* _self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    _self->physxActorShapeFlags = *((physx::PxShapeFlags*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1getPhysxActorSimulationFilterData(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::PhysXIntegrationParams* _self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    return (jlong) &_self->physxActorSimulationFilterData;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1setPhysxActorSimulationFilterData(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::PhysXIntegrationParams* _self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    _self->physxActorSimulationFilterData = *((physx::PxFilterData*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1getPhysxActorQueryFilterData(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::PhysXIntegrationParams* _self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    return (jlong) &_self->physxActorQueryFilterData;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1setPhysxActorQueryFilterData(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::PhysXIntegrationParams* _self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    _self->physxActorQueryFilterData = *((physx::PxFilterData*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1getPhysxActorWheelShapeFlags(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::PhysXIntegrationParams* _self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    return (jlong) &_self->physxActorWheelShapeFlags;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1setPhysxActorWheelShapeFlags(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::PhysXIntegrationParams* _self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    _self->physxActorWheelShapeFlags = *((physx::PxShapeFlags*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1getPhysxActorWheelSimulationFilterData(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::PhysXIntegrationParams* _self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    return (jlong) &_self->physxActorWheelSimulationFilterData;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1setPhysxActorWheelSimulationFilterData(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::PhysXIntegrationParams* _self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    _self->physxActorWheelSimulationFilterData = *((physx::PxFilterData*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1getPhysxActorWheelQueryFilterData(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::PhysXIntegrationParams* _self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    return (jlong) &_self->physxActorWheelQueryFilterData;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PhysXIntegrationParams__1setPhysxActorWheelQueryFilterData(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::PhysXIntegrationParams* _self = (snippetvehicle2::PhysXIntegrationParams*) _address;
    _self->physxActorWheelQueryFilterData = *((physx::PxFilterData*) value);
}

// PhysXIntegrationState
JNIEXPORT jint JNICALL Java_physx_vehicle2_PhysXIntegrationState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(snippetvehicle2::PhysXIntegrationState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PhysXIntegrationState__1PhysXIntegrationState(JNIEnv*, jclass) {
    return (jlong) new snippetvehicle2::PhysXIntegrationState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PhysXIntegrationState__1destroyState(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::PhysXIntegrationState* self = (snippetvehicle2::PhysXIntegrationState*) _address;
    self->destroyState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PhysXIntegrationState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::PhysXIntegrationState* self = (snippetvehicle2::PhysXIntegrationState*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PhysXIntegrationState__1create(JNIEnv*, jclass, jlong _address, jlong baseParams, jlong physxParams, jlong physics, jlong params, jlong defaultMaterial) {
    snippetvehicle2::PhysXIntegrationState* self = (snippetvehicle2::PhysXIntegrationState*) _address;
    self->create(*((snippetvehicle2::BaseVehicleParams*) baseParams), *((snippetvehicle2::PhysXIntegrationParams*) physxParams), *((physx::PxPhysics*) physics), *((physx::PxCookingParams*) params), *((physx::PxMaterial*) defaultMaterial));
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PhysXIntegrationState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (snippetvehicle2::PhysXIntegrationState*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PhysXIntegrationState__1getPhysxActor(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::PhysXIntegrationState* _self = (snippetvehicle2::PhysXIntegrationState*) _address;
    return (jlong) &_self->physxActor;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PhysXIntegrationState__1setPhysxActor(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::PhysXIntegrationState* _self = (snippetvehicle2::PhysXIntegrationState*) _address;
    _self->physxActor = *((physx::vehicle2::PxVehiclePhysXActor*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PhysXIntegrationState__1getPhysxSteerState(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::PhysXIntegrationState* _self = (snippetvehicle2::PhysXIntegrationState*) _address;
    return (jlong) &_self->physxSteerState;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PhysXIntegrationState__1setPhysxSteerState(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::PhysXIntegrationState* _self = (snippetvehicle2::PhysXIntegrationState*) _address;
    _self->physxSteerState = *((physx::vehicle2::PxVehiclePhysXSteerState*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PhysXIntegrationState__1getPhysxConstraints(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::PhysXIntegrationState* _self = (snippetvehicle2::PhysXIntegrationState*) _address;
    return (jlong) &_self->physxConstraints;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PhysXIntegrationState__1setPhysxConstraints(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::PhysXIntegrationState* _self = (snippetvehicle2::PhysXIntegrationState*) _address;
    _self->physxConstraints = *((physx::vehicle2::PxVehiclePhysXConstraints*) value);
}

// DirectDrivetrainParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_DirectDrivetrainParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(snippetvehicle2::DirectDrivetrainParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_DirectDrivetrainParams__1DirectDrivetrainParams(JNIEnv*, jclass) {
    return (jlong) new snippetvehicle2::DirectDrivetrainParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_DirectDrivetrainParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    snippetvehicle2::DirectDrivetrainParams* self = (snippetvehicle2::DirectDrivetrainParams*) _address;
    static thread_local snippetvehicle2::DirectDrivetrainParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_DirectDrivetrainParams__1isValid(JNIEnv*, jclass, jlong _address, jlong axleDesc) {
    snippetvehicle2::DirectDrivetrainParams* self = (snippetvehicle2::DirectDrivetrainParams*) _address;
    return (jboolean) self->isValid(*((physx::vehicle2::PxVehicleAxleDescription*) axleDesc));
}
JNIEXPORT void JNICALL Java_physx_vehicle2_DirectDrivetrainParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (snippetvehicle2::DirectDrivetrainParams*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_DirectDrivetrainParams__1getDirectDriveThrottleResponseParams(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::DirectDrivetrainParams* _self = (snippetvehicle2::DirectDrivetrainParams*) _address;
    return (jlong) &_self->directDriveThrottleResponseParams;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_DirectDrivetrainParams__1setDirectDriveThrottleResponseParams(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::DirectDrivetrainParams* _self = (snippetvehicle2::DirectDrivetrainParams*) _address;
    _self->directDriveThrottleResponseParams = *((physx::vehicle2::PxVehicleDirectDriveThrottleCommandResponseParams*) value);
}

// DirectDrivetrainState
JNIEXPORT jint JNICALL Java_physx_vehicle2_DirectDrivetrainState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(snippetvehicle2::DirectDrivetrainState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_DirectDrivetrainState__1DirectDrivetrainState(JNIEnv*, jclass) {
    return (jlong) new snippetvehicle2::DirectDrivetrainState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_DirectDrivetrainState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::DirectDrivetrainState* self = (snippetvehicle2::DirectDrivetrainState*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_DirectDrivetrainState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (snippetvehicle2::DirectDrivetrainState*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle2_DirectDrivetrainState__1getDirectDriveThrottleResponseStates(JNIEnv*, jclass, jlong _address, jint _index) {
    snippetvehicle2::DirectDrivetrainState* _self = (snippetvehicle2::DirectDrivetrainState*) _address;
    return (jfloat) _self->directDriveThrottleResponseStates[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle2_DirectDrivetrainState__1setDirectDriveThrottleResponseStates(JNIEnv*, jclass, jlong _address, jint _index, jfloat value) {
    snippetvehicle2::DirectDrivetrainState* _self = (snippetvehicle2::DirectDrivetrainState*) _address;
    _self->directDriveThrottleResponseStates[_index] = value;
}

// EngineDrivetrainParams
JNIEXPORT jint JNICALL Java_physx_vehicle2_EngineDrivetrainParams__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(snippetvehicle2::EngineDrivetrainParams);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_EngineDrivetrainParams__1EngineDrivetrainParams(JNIEnv*, jclass) {
    return (jlong) new snippetvehicle2::EngineDrivetrainParams();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_EngineDrivetrainParams__1transformAndScale(JNIEnv*, jclass, jlong _address, jlong srcFrame, jlong trgFrame, jlong srcScale, jlong trgScale) {
    snippetvehicle2::EngineDrivetrainParams* self = (snippetvehicle2::EngineDrivetrainParams*) _address;
    static thread_local snippetvehicle2::EngineDrivetrainParams _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    _cache = self->transformAndScale(*((physx::vehicle2::PxVehicleFrame*) srcFrame), *((physx::vehicle2::PxVehicleFrame*) trgFrame), *((physx::vehicle2::PxVehicleScale*) srcScale), *((physx::vehicle2::PxVehicleScale*) trgScale));
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_EngineDrivetrainParams__1isValid(JNIEnv*, jclass, jlong _address, jlong axleDesc) {
    snippetvehicle2::EngineDrivetrainParams* self = (snippetvehicle2::EngineDrivetrainParams*) _address;
    return (jboolean) self->isValid(*((physx::vehicle2::PxVehicleAxleDescription*) axleDesc));
}
JNIEXPORT void JNICALL Java_physx_vehicle2_EngineDrivetrainParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (snippetvehicle2::EngineDrivetrainParams*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_EngineDrivetrainParams__1getAutoboxParams(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::EngineDrivetrainParams* _self = (snippetvehicle2::EngineDrivetrainParams*) _address;
    return (jlong) &_self->autoboxParams;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_EngineDrivetrainParams__1setAutoboxParams(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::EngineDrivetrainParams* _self = (snippetvehicle2::EngineDrivetrainParams*) _address;
    _self->autoboxParams = *((physx::vehicle2::PxVehicleAutoboxParams*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_EngineDrivetrainParams__1getClutchCommandResponseParams(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::EngineDrivetrainParams* _self = (snippetvehicle2::EngineDrivetrainParams*) _address;
    return (jlong) &_self->clutchCommandResponseParams;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_EngineDrivetrainParams__1setClutchCommandResponseParams(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::EngineDrivetrainParams* _self = (snippetvehicle2::EngineDrivetrainParams*) _address;
    _self->clutchCommandResponseParams = *((physx::vehicle2::PxVehicleClutchCommandResponseParams*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_EngineDrivetrainParams__1getEngineParams(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::EngineDrivetrainParams* _self = (snippetvehicle2::EngineDrivetrainParams*) _address;
    return (jlong) &_self->engineParams;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_EngineDrivetrainParams__1setEngineParams(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::EngineDrivetrainParams* _self = (snippetvehicle2::EngineDrivetrainParams*) _address;
    _self->engineParams = *((physx::vehicle2::PxVehicleEngineParams*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_EngineDrivetrainParams__1getGearBoxParams(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::EngineDrivetrainParams* _self = (snippetvehicle2::EngineDrivetrainParams*) _address;
    return (jlong) &_self->gearBoxParams;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_EngineDrivetrainParams__1setGearBoxParams(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::EngineDrivetrainParams* _self = (snippetvehicle2::EngineDrivetrainParams*) _address;
    _self->gearBoxParams = *((physx::vehicle2::PxVehicleGearboxParams*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_EngineDrivetrainParams__1getMultiWheelDifferentialParams(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::EngineDrivetrainParams* _self = (snippetvehicle2::EngineDrivetrainParams*) _address;
    return (jlong) &_self->multiWheelDifferentialParams;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_EngineDrivetrainParams__1setMultiWheelDifferentialParams(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::EngineDrivetrainParams* _self = (snippetvehicle2::EngineDrivetrainParams*) _address;
    _self->multiWheelDifferentialParams = *((physx::vehicle2::PxVehicleMultiWheelDriveDifferentialParams*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_EngineDrivetrainParams__1getFourWheelDifferentialParams(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::EngineDrivetrainParams* _self = (snippetvehicle2::EngineDrivetrainParams*) _address;
    return (jlong) &_self->fourWheelDifferentialParams;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_EngineDrivetrainParams__1setFourWheelDifferentialParams(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::EngineDrivetrainParams* _self = (snippetvehicle2::EngineDrivetrainParams*) _address;
    _self->fourWheelDifferentialParams = *((physx::vehicle2::PxVehicleFourWheelDriveDifferentialParams*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_EngineDrivetrainParams__1getTankDifferentialParams(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::EngineDrivetrainParams* _self = (snippetvehicle2::EngineDrivetrainParams*) _address;
    return (jlong) &_self->tankDifferentialParams;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_EngineDrivetrainParams__1setTankDifferentialParams(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::EngineDrivetrainParams* _self = (snippetvehicle2::EngineDrivetrainParams*) _address;
    _self->tankDifferentialParams = *((physx::vehicle2::PxVehicleTankDriveDifferentialParams*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_EngineDrivetrainParams__1getClutchParams(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::EngineDrivetrainParams* _self = (snippetvehicle2::EngineDrivetrainParams*) _address;
    return (jlong) &_self->clutchParams;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_EngineDrivetrainParams__1setClutchParams(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::EngineDrivetrainParams* _self = (snippetvehicle2::EngineDrivetrainParams*) _address;
    _self->clutchParams = *((physx::vehicle2::PxVehicleClutchParams*) value);
}

// EngineDrivetrainState
JNIEXPORT jint JNICALL Java_physx_vehicle2_EngineDrivetrainState__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(snippetvehicle2::EngineDrivetrainState);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_EngineDrivetrainState__1EngineDrivetrainState(JNIEnv*, jclass) {
    return (jlong) new snippetvehicle2::EngineDrivetrainState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_EngineDrivetrainState__1setToDefault(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::EngineDrivetrainState* self = (snippetvehicle2::EngineDrivetrainState*) _address;
    self->setToDefault();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_EngineDrivetrainState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (snippetvehicle2::EngineDrivetrainState*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_EngineDrivetrainState__1getThrottleCommandResponseState(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::EngineDrivetrainState* _self = (snippetvehicle2::EngineDrivetrainState*) _address;
    return (jlong) &_self->throttleCommandResponseState;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_EngineDrivetrainState__1setThrottleCommandResponseState(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::EngineDrivetrainState* _self = (snippetvehicle2::EngineDrivetrainState*) _address;
    _self->throttleCommandResponseState = *((physx::vehicle2::PxVehicleEngineDriveThrottleCommandResponseState*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_EngineDrivetrainState__1getAutoboxState(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::EngineDrivetrainState* _self = (snippetvehicle2::EngineDrivetrainState*) _address;
    return (jlong) &_self->autoboxState;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_EngineDrivetrainState__1setAutoboxState(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::EngineDrivetrainState* _self = (snippetvehicle2::EngineDrivetrainState*) _address;
    _self->autoboxState = *((physx::vehicle2::PxVehicleAutoboxState*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_EngineDrivetrainState__1getClutchCommandResponseState(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::EngineDrivetrainState* _self = (snippetvehicle2::EngineDrivetrainState*) _address;
    return (jlong) &_self->clutchCommandResponseState;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_EngineDrivetrainState__1setClutchCommandResponseState(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::EngineDrivetrainState* _self = (snippetvehicle2::EngineDrivetrainState*) _address;
    _self->clutchCommandResponseState = *((physx::vehicle2::PxVehicleClutchCommandResponseState*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_EngineDrivetrainState__1getDifferentialState(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::EngineDrivetrainState* _self = (snippetvehicle2::EngineDrivetrainState*) _address;
    return (jlong) &_self->differentialState;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_EngineDrivetrainState__1setDifferentialState(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::EngineDrivetrainState* _self = (snippetvehicle2::EngineDrivetrainState*) _address;
    _self->differentialState = *((physx::vehicle2::PxVehicleDifferentialState*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_EngineDrivetrainState__1getWheelConstraintGroupState(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::EngineDrivetrainState* _self = (snippetvehicle2::EngineDrivetrainState*) _address;
    return (jlong) &_self->wheelConstraintGroupState;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_EngineDrivetrainState__1setWheelConstraintGroupState(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::EngineDrivetrainState* _self = (snippetvehicle2::EngineDrivetrainState*) _address;
    _self->wheelConstraintGroupState = *((physx::vehicle2::PxVehicleWheelConstraintGroupState*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_EngineDrivetrainState__1getEngineState(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::EngineDrivetrainState* _self = (snippetvehicle2::EngineDrivetrainState*) _address;
    return (jlong) &_self->engineState;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_EngineDrivetrainState__1setEngineState(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::EngineDrivetrainState* _self = (snippetvehicle2::EngineDrivetrainState*) _address;
    _self->engineState = *((physx::vehicle2::PxVehicleEngineState*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_EngineDrivetrainState__1getGearboxState(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::EngineDrivetrainState* _self = (snippetvehicle2::EngineDrivetrainState*) _address;
    return (jlong) &_self->gearboxState;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_EngineDrivetrainState__1setGearboxState(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::EngineDrivetrainState* _self = (snippetvehicle2::EngineDrivetrainState*) _address;
    _self->gearboxState = *((physx::vehicle2::PxVehicleGearboxState*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_EngineDrivetrainState__1getClutchState(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::EngineDrivetrainState* _self = (snippetvehicle2::EngineDrivetrainState*) _address;
    return (jlong) &_self->clutchState;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_EngineDrivetrainState__1setClutchState(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::EngineDrivetrainState* _self = (snippetvehicle2::EngineDrivetrainState*) _address;
    _self->clutchState = *((physx::vehicle2::PxVehicleClutchSlipState*) value);
}

// BaseVehicle
JNIEXPORT jint JNICALL Java_physx_vehicle2_BaseVehicle__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(snippetvehicle2::BaseVehicle);
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_BaseVehicle__1initialize(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::BaseVehicle* self = (snippetvehicle2::BaseVehicle*) _address;
    return (jboolean) self->initialize();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicle__1destroyState(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::BaseVehicle* self = (snippetvehicle2::BaseVehicle*) _address;
    self->destroyState();
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicle__1initComponentSequence(JNIEnv*, jclass, jlong _address, jboolean addPhysXBeginEndComponents) {
    snippetvehicle2::BaseVehicle* self = (snippetvehicle2::BaseVehicle*) _address;
    self->initComponentSequence(addPhysXBeginEndComponents);
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicle__1step(JNIEnv*, jclass, jlong _address, jfloat dt, jlong context) {
    snippetvehicle2::BaseVehicle* self = (snippetvehicle2::BaseVehicle*) _address;
    self->step(dt, *((physx::vehicle2::PxVehicleSimulationContext*) context));
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicle__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (snippetvehicle2::BaseVehicle*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicle__1getBaseParams(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::BaseVehicle* _self = (snippetvehicle2::BaseVehicle*) _address;
    return (jlong) &_self->baseParams;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicle__1setBaseParams(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::BaseVehicle* _self = (snippetvehicle2::BaseVehicle*) _address;
    _self->baseParams = *((snippetvehicle2::BaseVehicleParams*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicle__1getBaseState(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::BaseVehicle* _self = (snippetvehicle2::BaseVehicle*) _address;
    return (jlong) &_self->baseState;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicle__1setBaseState(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::BaseVehicle* _self = (snippetvehicle2::BaseVehicle*) _address;
    _self->baseState = *((snippetvehicle2::BaseVehicleState*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_BaseVehicle__1getComponentSequence(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::BaseVehicle* _self = (snippetvehicle2::BaseVehicle*) _address;
    return (jlong) &_self->componentSequence;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicle__1setComponentSequence(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::BaseVehicle* _self = (snippetvehicle2::BaseVehicle*) _address;
    _self->componentSequence = *((physx::vehicle2::PxVehicleComponentSequence*) value);
}
JNIEXPORT jbyte JNICALL Java_physx_vehicle2_BaseVehicle__1getComponentSequenceSubstepGroupHandle(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::BaseVehicle* _self = (snippetvehicle2::BaseVehicle*) _address;
    return (jbyte) _self->componentSequenceSubstepGroupHandle;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_BaseVehicle__1setComponentSequenceSubstepGroupHandle(JNIEnv*, jclass, jlong _address, jbyte value) {
    snippetvehicle2::BaseVehicle* _self = (snippetvehicle2::BaseVehicle*) _address;
    _self->componentSequenceSubstepGroupHandle = value;
}

// PhysXActorVehicle
JNIEXPORT jint JNICALL Java_physx_vehicle2_PhysXActorVehicle__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(snippetvehicle2::PhysXActorVehicle);
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_PhysXActorVehicle__1initialize(JNIEnv*, jclass, jlong _address, jlong physics, jlong params, jlong defaultMaterial) {
    snippetvehicle2::PhysXActorVehicle* self = (snippetvehicle2::PhysXActorVehicle*) _address;
    return (jboolean) self->initialize(*((physx::PxPhysics*) physics), *((physx::PxCookingParams*) params), *((physx::PxMaterial*) defaultMaterial));
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PhysXActorVehicle__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (snippetvehicle2::PhysXActorVehicle*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PhysXActorVehicle__1getPhysXParams(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::PhysXActorVehicle* _self = (snippetvehicle2::PhysXActorVehicle*) _address;
    return (jlong) &_self->physXParams;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PhysXActorVehicle__1setPhysXParams(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::PhysXActorVehicle* _self = (snippetvehicle2::PhysXActorVehicle*) _address;
    _self->physXParams = *((snippetvehicle2::PhysXIntegrationParams*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PhysXActorVehicle__1getPhysXState(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::PhysXActorVehicle* _self = (snippetvehicle2::PhysXActorVehicle*) _address;
    return (jlong) &_self->physXState;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PhysXActorVehicle__1setPhysXState(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::PhysXActorVehicle* _self = (snippetvehicle2::PhysXActorVehicle*) _address;
    _self->physXState = *((snippetvehicle2::PhysXIntegrationState*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_PhysXActorVehicle__1getCommandState(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::PhysXActorVehicle* _self = (snippetvehicle2::PhysXActorVehicle*) _address;
    return (jlong) &_self->commandState;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_PhysXActorVehicle__1setCommandState(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::PhysXActorVehicle* _self = (snippetvehicle2::PhysXActorVehicle*) _address;
    _self->commandState = *((physx::vehicle2::PxVehicleCommandState*) value);
}

// DirectDriveVehicle
JNIEXPORT jint JNICALL Java_physx_vehicle2_DirectDriveVehicle__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(snippetvehicle2::DirectDriveVehicle);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_DirectDriveVehicle__1DirectDriveVehicle(JNIEnv*, jclass) {
    return (jlong) new snippetvehicle2::DirectDriveVehicle();
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_DirectDriveVehicle__1initialize__JJJJ(JNIEnv*, jclass, jlong _address, jlong physics, jlong params, jlong defaultMaterial) {
    snippetvehicle2::DirectDriveVehicle* self = (snippetvehicle2::DirectDriveVehicle*) _address;
    return (jboolean) self->initialize(*((physx::PxPhysics*) physics), *((physx::PxCookingParams*) params), *((physx::PxMaterial*) defaultMaterial));
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_DirectDriveVehicle__1initialize__JJJJZ(JNIEnv*, jclass, jlong _address, jlong physics, jlong params, jlong defaultMaterial, jboolean addPhysXBeginEndComponents) {
    snippetvehicle2::DirectDriveVehicle* self = (snippetvehicle2::DirectDriveVehicle*) _address;
    return (jboolean) self->initialize(*((physx::PxPhysics*) physics), *((physx::PxCookingParams*) params), *((physx::PxMaterial*) defaultMaterial), addPhysXBeginEndComponents);
}
JNIEXPORT void JNICALL Java_physx_vehicle2_DirectDriveVehicle__1initComponentSequence(JNIEnv*, jclass, jlong _address, jboolean addPhysXBeginEndComponents) {
    snippetvehicle2::DirectDriveVehicle* self = (snippetvehicle2::DirectDriveVehicle*) _address;
    self->initComponentSequence(addPhysXBeginEndComponents);
}
JNIEXPORT void JNICALL Java_physx_vehicle2_DirectDriveVehicle__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (snippetvehicle2::DirectDriveVehicle*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_DirectDriveVehicle__1getDirectDriveParams(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::DirectDriveVehicle* _self = (snippetvehicle2::DirectDriveVehicle*) _address;
    return (jlong) &_self->directDriveParams;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_DirectDriveVehicle__1setDirectDriveParams(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::DirectDriveVehicle* _self = (snippetvehicle2::DirectDriveVehicle*) _address;
    _self->directDriveParams = *((snippetvehicle2::DirectDrivetrainParams*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_DirectDriveVehicle__1getDirectDriveState(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::DirectDriveVehicle* _self = (snippetvehicle2::DirectDriveVehicle*) _address;
    return (jlong) &_self->directDriveState;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_DirectDriveVehicle__1setDirectDriveState(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::DirectDriveVehicle* _self = (snippetvehicle2::DirectDriveVehicle*) _address;
    _self->directDriveState = *((snippetvehicle2::DirectDrivetrainState*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_DirectDriveVehicle__1getTransmissionCommandState(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::DirectDriveVehicle* _self = (snippetvehicle2::DirectDriveVehicle*) _address;
    return (jlong) &_self->transmissionCommandState;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_DirectDriveVehicle__1setTransmissionCommandState(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::DirectDriveVehicle* _self = (snippetvehicle2::DirectDriveVehicle*) _address;
    _self->transmissionCommandState = *((physx::vehicle2::PxVehicleDirectDriveTransmissionCommandState*) value);
}

// EngineDriveVehicle
JNIEXPORT jint JNICALL Java_physx_vehicle2_EngineDriveVehicle__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(snippetvehicle2::EngineDriveVehicle);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_EngineDriveVehicle__1EngineDriveVehicle(JNIEnv*, jclass) {
    return (jlong) new snippetvehicle2::EngineDriveVehicle();
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_EngineDriveVehicle__1initialize__JJJJI(JNIEnv*, jclass, jlong _address, jlong physics, jlong params, jlong defaultMaterial, jint differentialType) {
    snippetvehicle2::EngineDriveVehicle* self = (snippetvehicle2::EngineDriveVehicle*) _address;
    return (jboolean) self->initialize(*((physx::PxPhysics*) physics), *((physx::PxCookingParams*) params), *((physx::PxMaterial*) defaultMaterial), (EngineDriveVehicleEnum) differentialType);
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle2_EngineDriveVehicle__1initialize__JJJJIZ(JNIEnv*, jclass, jlong _address, jlong physics, jlong params, jlong defaultMaterial, jint differentialType, jboolean addPhysXBeginEndComponents) {
    snippetvehicle2::EngineDriveVehicle* self = (snippetvehicle2::EngineDriveVehicle*) _address;
    return (jboolean) self->initialize(*((physx::PxPhysics*) physics), *((physx::PxCookingParams*) params), *((physx::PxMaterial*) defaultMaterial), (EngineDriveVehicleEnum) differentialType, addPhysXBeginEndComponents);
}
JNIEXPORT void JNICALL Java_physx_vehicle2_EngineDriveVehicle__1initComponentSequence(JNIEnv*, jclass, jlong _address, jboolean addPhysXBeginEndComponents) {
    snippetvehicle2::EngineDriveVehicle* self = (snippetvehicle2::EngineDriveVehicle*) _address;
    self->initComponentSequence(addPhysXBeginEndComponents);
}
JNIEXPORT void JNICALL Java_physx_vehicle2_EngineDriveVehicle__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (snippetvehicle2::EngineDriveVehicle*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_EngineDriveVehicle__1getEngineDriveParams(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::EngineDriveVehicle* _self = (snippetvehicle2::EngineDriveVehicle*) _address;
    return (jlong) &_self->engineDriveParams;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_EngineDriveVehicle__1setEngineDriveParams(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::EngineDriveVehicle* _self = (snippetvehicle2::EngineDriveVehicle*) _address;
    _self->engineDriveParams = *((snippetvehicle2::EngineDrivetrainParams*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_EngineDriveVehicle__1getEngineDriveState(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::EngineDriveVehicle* _self = (snippetvehicle2::EngineDriveVehicle*) _address;
    return (jlong) &_self->engineDriveState;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_EngineDriveVehicle__1setEngineDriveState(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::EngineDriveVehicle* _self = (snippetvehicle2::EngineDriveVehicle*) _address;
    _self->engineDriveState = *((snippetvehicle2::EngineDrivetrainState*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_EngineDriveVehicle__1getTransmissionCommandState(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::EngineDriveVehicle* _self = (snippetvehicle2::EngineDriveVehicle*) _address;
    return (jlong) &_self->transmissionCommandState;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_EngineDriveVehicle__1setTransmissionCommandState(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::EngineDriveVehicle* _self = (snippetvehicle2::EngineDriveVehicle*) _address;
    _self->transmissionCommandState = *((physx::vehicle2::PxVehicleEngineDriveTransmissionCommandState*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle2_EngineDriveVehicle__1getTankDriveTransmissionCommandState(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::EngineDriveVehicle* _self = (snippetvehicle2::EngineDriveVehicle*) _address;
    return (jlong) &_self->tankDriveTransmissionCommandState;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_EngineDriveVehicle__1setTankDriveTransmissionCommandState(JNIEnv*, jclass, jlong _address, jlong value) {
    snippetvehicle2::EngineDriveVehicle* _self = (snippetvehicle2::EngineDriveVehicle*) _address;
    _self->tankDriveTransmissionCommandState = *((physx::vehicle2::PxVehicleTankDriveTransmissionCommandState*) value);
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_EngineDriveVehicle__1getDifferentialType(JNIEnv*, jclass, jlong _address) {
    snippetvehicle2::EngineDriveVehicle* _self = (snippetvehicle2::EngineDriveVehicle*) _address;
    return (jint) _self->differentialType;
}
JNIEXPORT void JNICALL Java_physx_vehicle2_EngineDriveVehicle__1setDifferentialType(JNIEnv*, jclass, jlong _address, jint value) {
    snippetvehicle2::EngineDriveVehicle* _self = (snippetvehicle2::EngineDriveVehicle*) _address;
    _self->differentialType = (EngineDriveVehicleEnum) value;
}

// PxVehicleAxesEnum
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleAxesEnum__1getePosX(JNIEnv*, jclass) {
    return PxVehicleAxesEnum::ePosX;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleAxesEnum__1geteNegX(JNIEnv*, jclass) {
    return PxVehicleAxesEnum::eNegX;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleAxesEnum__1getePosY(JNIEnv*, jclass) {
    return PxVehicleAxesEnum::ePosY;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleAxesEnum__1geteNegY(JNIEnv*, jclass) {
    return PxVehicleAxesEnum::eNegY;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleAxesEnum__1getePosZ(JNIEnv*, jclass) {
    return PxVehicleAxesEnum::ePosZ;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleAxesEnum__1geteNegZ(JNIEnv*, jclass) {
    return PxVehicleAxesEnum::eNegZ;
}

// PxVehicleClutchAccuracyModeEnum
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleClutchAccuracyModeEnum__1geteESTIMATE(JNIEnv*, jclass) {
    return PxVehicleClutchAccuracyModeEnum::eESTIMATE;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleClutchAccuracyModeEnum__1geteBEST_1POSSIBLE(JNIEnv*, jclass) {
    return PxVehicleClutchAccuracyModeEnum::eBEST_POSSIBLE;
}

// PxVehicleCommandNonLinearResponseParamsEnum
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleCommandNonLinearResponseParamsEnum__1geteMAX_1NB_1COMMAND_1VALUES(JNIEnv*, jclass) {
    return PxVehicleCommandNonLinearResponseParamsEnum::eMAX_NB_COMMAND_VALUES;
}

// PxVehicleCommandValueResponseTableEnum
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleCommandValueResponseTableEnum__1geteMAX_1NB_1SPEED_1RESPONSES(JNIEnv*, jclass) {
    return PxVehicleCommandValueResponseTableEnum::eMAX_NB_SPEED_RESPONSES;
}

// PxVehicleDirectDriveTransmissionCommandStateEnum
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleDirectDriveTransmissionCommandStateEnum__1geteREVERSE(JNIEnv*, jclass) {
    return PxVehicleDirectDriveTransmissionCommandStateEnum::eREVERSE;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleDirectDriveTransmissionCommandStateEnum__1geteNEUTRAL(JNIEnv*, jclass) {
    return PxVehicleDirectDriveTransmissionCommandStateEnum::eNEUTRAL;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleDirectDriveTransmissionCommandStateEnum__1geteFORWARD(JNIEnv*, jclass) {
    return PxVehicleDirectDriveTransmissionCommandStateEnum::eFORWARD;
}

// PxVehicleEngineDriveTransmissionCommandStateEnum
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleEngineDriveTransmissionCommandStateEnum__1geteAUTOMATIC_1GEAR(JNIEnv*, jclass) {
    return PxVehicleEngineDriveTransmissionCommandStateEnum::eAUTOMATIC_GEAR;
}

// PxVehicleGearboxParamsEnum
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleGearboxParamsEnum__1geteMAX_1NB_1GEARS(JNIEnv*, jclass) {
    return PxVehicleGearboxParamsEnum::eMAX_NB_GEARS;
}

// PxVehicleLimitsEnum
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleLimitsEnum__1geteMAX_1NB_1WHEELS(JNIEnv*, jclass) {
    return PxVehicleLimitsEnum::eMAX_NB_WHEELS;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleLimitsEnum__1geteMAX_1NB_1AXLES(JNIEnv*, jclass) {
    return PxVehicleLimitsEnum::eMAX_NB_AXLES;
}

// PxVehiclePhysXActorUpdateModeEnum
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehiclePhysXActorUpdateModeEnum__1geteAPPLY_1VELOCITY(JNIEnv*, jclass) {
    return PxVehiclePhysXActorUpdateModeEnum::eAPPLY_VELOCITY;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehiclePhysXActorUpdateModeEnum__1geteAPPLY_1ACCELERATION(JNIEnv*, jclass) {
    return PxVehiclePhysXActorUpdateModeEnum::eAPPLY_ACCELERATION;
}

// PxVehiclePhysXConstraintLimitsEnum
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraintLimitsEnum__1geteNB_1DOFS_1PER_1PXCONSTRAINT(JNIEnv*, jclass) {
    return PxVehiclePhysXConstraintLimitsEnum::eNB_DOFS_PER_PXCONSTRAINT;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraintLimitsEnum__1geteNB_1DOFS_1PER_1WHEEL(JNIEnv*, jclass) {
    return PxVehiclePhysXConstraintLimitsEnum::eNB_DOFS_PER_WHEEL;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraintLimitsEnum__1geteNB_1WHEELS_1PER_1PXCONSTRAINT(JNIEnv*, jclass) {
    return PxVehiclePhysXConstraintLimitsEnum::eNB_WHEELS_PER_PXCONSTRAINT;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehiclePhysXConstraintLimitsEnum__1geteNB_1CONSTRAINTS_1PER_1VEHICLE(JNIEnv*, jclass) {
    return PxVehiclePhysXConstraintLimitsEnum::eNB_CONSTRAINTS_PER_VEHICLE;
}

// PxVehiclePhysXRoadGeometryQueryTypeEnum
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehiclePhysXRoadGeometryQueryTypeEnum__1geteNONE(JNIEnv*, jclass) {
    return PxVehiclePhysXRoadGeometryQueryTypeEnum::eNONE;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehiclePhysXRoadGeometryQueryTypeEnum__1geteRAYCAST(JNIEnv*, jclass) {
    return PxVehiclePhysXRoadGeometryQueryTypeEnum::eRAYCAST;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehiclePhysXRoadGeometryQueryTypeEnum__1geteSWEEP(JNIEnv*, jclass) {
    return PxVehiclePhysXRoadGeometryQueryTypeEnum::eSWEEP;
}

// PxVehiclePhysXSuspensionLimitConstraintParamsDirectionSpecifierEnum
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehiclePhysXSuspensionLimitConstraintParamsDirectionSpecifierEnum__1geteSUSPENSION(JNIEnv*, jclass) {
    return PxVehiclePhysXSuspensionLimitConstraintParamsDirectionSpecifierEnum::eSUSPENSION;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehiclePhysXSuspensionLimitConstraintParamsDirectionSpecifierEnum__1geteROAD_1GEOMETRY_1NORMAL(JNIEnv*, jclass) {
    return PxVehiclePhysXSuspensionLimitConstraintParamsDirectionSpecifierEnum::eROAD_GEOMETRY_NORMAL;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehiclePhysXSuspensionLimitConstraintParamsDirectionSpecifierEnum__1geteNONE(JNIEnv*, jclass) {
    return PxVehiclePhysXSuspensionLimitConstraintParamsDirectionSpecifierEnum::eNONE;
}

// PxVehicleSimulationContextTypeEnum
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleSimulationContextTypeEnum__1geteDEFAULT(JNIEnv*, jclass) {
    return PxVehicleSimulationContextTypeEnum::eDEFAULT;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleSimulationContextTypeEnum__1getePHYSX(JNIEnv*, jclass) {
    return PxVehicleSimulationContextTypeEnum::ePHYSX;
}

// PxVehicleSuspensionJounceCalculationTypeEnum
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleSuspensionJounceCalculationTypeEnum__1geteRAYCAST(JNIEnv*, jclass) {
    return PxVehicleSuspensionJounceCalculationTypeEnum::eRAYCAST;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleSuspensionJounceCalculationTypeEnum__1geteSWEEP(JNIEnv*, jclass) {
    return PxVehicleSuspensionJounceCalculationTypeEnum::eSWEEP;
}

// PxVehicleTireDirectionModesEnum
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTireDirectionModesEnum__1geteLONGITUDINAL(JNIEnv*, jclass) {
    return PxVehicleTireDirectionModesEnum::eLONGITUDINAL;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_PxVehicleTireDirectionModesEnum__1geteLATERAL(JNIEnv*, jclass) {
    return PxVehicleTireDirectionModesEnum::eLATERAL;
}

// EngineDriveVehicleEnum
JNIEXPORT jint JNICALL Java_physx_vehicle2_EngineDriveVehicleEnum__1geteDIFFTYPE_1FOURWHEELDRIVE(JNIEnv*, jclass) {
    return EngineDriveVehicleEnum::eDIFFTYPE_FOURWHEELDRIVE;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_EngineDriveVehicleEnum__1geteDIFFTYPE_1MULTIWHEELDRIVE(JNIEnv*, jclass) {
    return EngineDriveVehicleEnum::eDIFFTYPE_MULTIWHEELDRIVE;
}
JNIEXPORT jint JNICALL Java_physx_vehicle2_EngineDriveVehicleEnum__1geteDIFFTYPE_1TANKDRIVE(JNIEnv*, jclass) {
    return EngineDriveVehicleEnum::eDIFFTYPE_TANKDRIVE;
}

} // /extern "C"
