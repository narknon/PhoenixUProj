#include "AvaAudioCachedRTPC.h"

class AActor;
class UAkGameObject;

void UAvaAudioCachedRTPC::AvaAudioSetGlobalState(FName StateName, FName StateValue, bool& bSuccess, bool bForce) {
}

void UAvaAudioCachedRTPC::AvaAudioSetGlobalRTPC(FName RTPCName, float RTPCValue, bool& bSuccess, int32 InterpolationTimeMilliseconds, float Threshold, bool bForce, bool bHoldMax) {
}

void UAvaAudioCachedRTPC::AvaAudioSetGameObjectRTPC(UAkGameObject* AudioObject, FName RTPCName, float RTPCValue, bool& bSuccess, int32 InterpolationTimeMilliseconds, float Threshold, bool bForce) {
}

void UAvaAudioCachedRTPC::AvaAudioSetActorRTPC(AActor* Actor, FName RTPCName, float RTPCValue, bool& bSuccess, int32 InterpolationTimeMilliseconds, float Threshold, bool bForce) {
}

void UAvaAudioCachedRTPC::AvaAudioResetGlobalState(FName StateName) {
}

void UAvaAudioCachedRTPC::AvaAudioResetGlobalRTPC(FName RTPCName) {
}

void UAvaAudioCachedRTPC::AvaAudioResetGameObjectRTPC(UAkGameObject* AudioObject, FName RTPCName) {
}

void UAvaAudioCachedRTPC::AvaAudioResetActorRTPC(AActor* Actor, FName RTPCName) {
}

void UAvaAudioCachedRTPC::AvaAudioGetGlobalState(FName StateName, bool& bSuccess, FName& StateValue) {
}

void UAvaAudioCachedRTPC::AvaAudioGetGlobalRTPC(FName RTPCName, bool& bSuccess, float& RTPCValue) {
}

void UAvaAudioCachedRTPC::AvaAudioGetGameObjectRTPC(UAkGameObject* AudioObject, FName RTPCName, bool& bSuccess, float& RTPCValue) {
}

void UAvaAudioCachedRTPC::AvaAudioGetActorRTPC(AActor* Actor, FName RTPCName, bool& bSuccess, float& RTPCValue) {
}

UAvaAudioCachedRTPC::UAvaAudioCachedRTPC() {
}

