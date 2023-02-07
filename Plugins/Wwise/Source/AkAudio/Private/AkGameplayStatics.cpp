#include "AkGameplayStatics.h"

class AActor;
class UAkAudioBank;
class UAkAudioEvent;
class UAkAudioType;
class UAkAuxBus;
class UAkComponent;
class UAkMediaAsset;
class UAkPortalComponent;
class UAkRtpc;
class UAkStateValue;
class UAkSwitchValue;
class UAkTrigger;
class UObject;
class USceneComponent;

void UAkGameplayStatics::UseReverbVolumes(bool inUseReverbVolumes, AActor* Actor) {
}

void UAkGameplayStatics::UseEarlyReflections(AActor* Actor, UAkAuxBus* AuxBus, int32 Order, float BusSendGain, float MaxPathLength, bool SpotReflectors, const FString& AuxBusName) {
}

void UAkGameplayStatics::UnloadBankByName(const FString& BankName) {
}

void UAkGameplayStatics::UnloadBankAsync(UAkAudioBank* Bank, const FOnAkBankCallback& BankUnloadedCallback) {
}

void UAkGameplayStatics::UnloadBank(UAkAudioBank* Bank, const FString& BankName, FLatentActionInfo LatentInfo, UObject* WorldContextObject) {
}

void UAkGameplayStatics::StopProfilerCapture() {
}

void UAkGameplayStatics::StopOutputCapture() {
}

void UAkGameplayStatics::StopAllAmbientSounds(UObject* WorldContextObject) {
}

void UAkGameplayStatics::StopAll() {
}

void UAkGameplayStatics::StopActor(AActor* Actor) {
}

void UAkGameplayStatics::StartProfilerCapture(const FString& Filename) {
}

void UAkGameplayStatics::StartOutputCapture(const FString& Filename) {
}

void UAkGameplayStatics::StartAllAmbientSounds(UObject* WorldContextObject) {
}

UAkComponent* UAkGameplayStatics::SpawnAkComponentAtLocation(UObject* WorldContextObject, UAkAudioEvent* AkEvent, FVector Location, FRotator Orientation, bool AutoPost, const FString& EventName, bool AutoDestroy) {
    return NULL;
}

void UAkGameplayStatics::SetSwitch(UAkSwitchValue* SwitchValue, AActor* Actor, FName SwitchGroup, FName SwitchState) {
}

void UAkGameplayStatics::SetState(UAkStateValue* StateValue, FName stateGroup, FName State) {
}

void UAkGameplayStatics::SetSpeakerAngles(const TArray<float>& SpeakerAngles, float HeightAngle, const FString& DeviceShareset) {
}

void UAkGameplayStatics::SetRTPCValue(UAkRtpc* RTPCValue, float Value, int32 InterpolationTimeMs, AActor* Actor, FName RTPC) {
}

void UAkGameplayStatics::SetReflectionsOrder(int32 Order, bool RefreshPaths) {
}

void UAkGameplayStatics::SetPortalToPortalObstruction(UAkPortalComponent* PortalComponent0, UAkPortalComponent* PortalComponent1, float ObstructionValue) {
}

void UAkGameplayStatics::SetPortalObstructionAndOcclusion(UAkPortalComponent* PortalComponent, float ObstructionValue, float OcclusionValue) {
}

void UAkGameplayStatics::SetPanningRule(PanningRule PanRule) {
}

void UAkGameplayStatics::SetOutputBusVolume(float BusVolume, AActor* Actor) {
}

void UAkGameplayStatics::SetOcclusionScalingFactor(float ScalingFactor) {
}

void UAkGameplayStatics::SetOcclusionRefreshInterval(float RefreshInterval, AActor* Actor) {
}

void UAkGameplayStatics::SetMultiplePositions(UAkComponent* GameObjectAkComponent, TArray<FTransform> Positions, AkMultiPositionType MultiPositionType) {
}

void UAkGameplayStatics::SetMultipleChannelMaskEmitterPositions(UAkComponent* GameObjectAkComponent, TArray<FAkChannelMask> ChannelMasks, TArray<FTransform> Positions, AkMultiPositionType MultiPositionType) {
}

void UAkGameplayStatics::SetMultipleChannelEmitterPositions(UAkComponent* GameObjectAkComponent, TArray<AkChannelConfiguration> ChannelMasks, TArray<FTransform> Positions, AkMultiPositionType MultiPositionType) {
}

void UAkGameplayStatics::SetGameObjectToPortalObstruction(UAkComponent* GameObjectAkComponent, UAkPortalComponent* PortalComponent, float ObstructionValue) {
}

void UAkGameplayStatics::SetDefaultOcclusionRefreshInterval(AActor* Actor, float RefreshInterval) {
}

void UAkGameplayStatics::SetCurrentAudioCultureAsync(const FString& AudioCulture, const FOnSetCurrentAudioCultureCallback& Completed) {
}

void UAkGameplayStatics::SetCurrentAudioCulture(const FString& AudioCulture, FLatentActionInfo LatentInfo, UObject* WorldContextObject) {
}

void UAkGameplayStatics::SetBusConfig(const FString& BusName, AkChannelConfiguration ChannelConfiguration) {
}

void UAkGameplayStatics::ResetRTPCValue(UAkRtpc* RTPCValue, int32 InterpolationTimeMs, AActor* Actor, FName RTPC) {
}

void UAkGameplayStatics::ReplaceMainOutput(const FAkOutputSettings& MainOutputSettings) {
}

void UAkGameplayStatics::RemoveOcclusionRefreshFromStack(AActor* Actor, int32 StackHandle) {
}

void UAkGameplayStatics::PostTrigger(UAkTrigger* TriggerValue, AActor* Actor, FName Trigger) {
}

void UAkGameplayStatics::PostEventByName(const FString& EventName, AActor* Actor, bool bStopWhenAttachedToDestroyed) {
}

int32 UAkGameplayStatics::PostEventAttached(UAkAudioEvent* AkEvent, AActor* Actor, FName AttachPointName, bool bStopWhenAttachedToDestroyed, const FString& EventName) {
    return 0;
}

void UAkGameplayStatics::PostEventAtLocationByName(const FString& EventName, FVector Location, FRotator Orientation, UObject* WorldContextObject) {
}

int32 UAkGameplayStatics::PostEventAtLocation(UAkAudioEvent* AkEvent, FVector Location, FRotator Orientation, const FString& EventName, UObject* WorldContextObject) {
    return 0;
}

int32 UAkGameplayStatics::PostEvent(UAkAudioEvent* AkEvent, AActor* Actor, int32 CallbackMask, const FOnAkPostEventCallback& PostEventCallback, const TArray<FAkExternalSourceInfo>& ExternalSources, bool bStopWhenAttachedToDestroyed, const FString& EventName) {
    return 0;
}

void UAkGameplayStatics::PostAndWaitForEndOfEventAsync(UAkAudioEvent* AkEvent, AActor* Actor, int32& PlayingID, bool bStopWhenAttachedToDestroyed, const TArray<FAkExternalSourceInfo>& ExternalSources, FLatentActionInfo LatentInfo) {
}

int32 UAkGameplayStatics::PostAndWaitForEndOfEvent(UAkAudioEvent* AkEvent, AActor* Actor, bool bStopWhenAttachedToDestroyed, const TArray<FAkExternalSourceInfo>& ExternalSources, const FString& EventName, FLatentActionInfo LatentInfo) {
    return 0;
}

void UAkGameplayStatics::LoadInitBank() {
}

void UAkGameplayStatics::LoadBanks(const TArray<UAkAudioBank*>& SoundBanks, bool SynchronizeSoundBanks) {
}

void UAkGameplayStatics::LoadBankByName(const FString& BankName) {
}

void UAkGameplayStatics::LoadBankAsync(UAkAudioBank* Bank, const FOnAkBankCallback& BankLoadedCallback) {
}

void UAkGameplayStatics::LoadBank(UAkAudioBank* Bank, const FString& BankName, FLatentActionInfo LatentInfo, UObject* WorldContextObject) {
}

bool UAkGameplayStatics::IsGame(UObject* WorldContextObject) {
    return false;
}

bool UAkGameplayStatics::IsEditor() {
    return false;
}

void UAkGameplayStatics::GetSpeakerAngles(TArray<float>& SpeakerAngles, float& HeightAngle, const FString& DeviceShareset) {
}

void UAkGameplayStatics::GetRTPCValue(UAkRtpc* RTPCValue, int32 PlayingID, ERTPCValueType InputValueType, float& Value, ERTPCValueType& OutputValueType, AActor* Actor, FName RTPC) {
}

float UAkGameplayStatics::GetOcclusionScalingFactor() {
    return 0.0f;
}

FString UAkGameplayStatics::GetCurrentAudioCulture() {
    return TEXT("");
}

TArray<FString> UAkGameplayStatics::GetAvailableAudioCultures() {
    return TArray<FString>();
}

UObject* UAkGameplayStatics::GetAkMediaAssetUserData(const UAkMediaAsset* Instance, const UClass* Type) {
    return NULL;
}

UAkComponent* UAkGameplayStatics::GetAkComponent(USceneComponent* AttachToComponent, bool& ComponentCreated, FName AttachPointName, FVector Location, TEnumAsByte<EAttachLocation::Type> LocationType) {
    return NULL;
}

UObject* UAkGameplayStatics::GetAkAudioTypeUserData(const UAkAudioType* Instance, const UClass* Type) {
    return NULL;
}

void UAkGameplayStatics::ExecuteActionOnPlayingID(AkActionOnEventType ActionType, int32 PlayingID, int32 TransitionDuration, EAkCurveInterpolation FadeCurve) {
}

void UAkGameplayStatics::ExecuteActionOnEvent(UAkAudioEvent* AkEvent, AkActionOnEventType ActionType, AActor* Actor, int32 TransitionDuration, EAkCurveInterpolation FadeCurve, int32 PlayingID) {
}

void UAkGameplayStatics::ClearBanks() {
}

void UAkGameplayStatics::CancelEventCallback(const FOnAkPostEventCallback& PostEventCallback) {
}

void UAkGameplayStatics::AddOutputCaptureMarker(const FString& MarkerText) {
}

int32 UAkGameplayStatics::AddOcclusionRefreshToStack(AActor* Actor, float RefreshInterval, int32 Priority) {
    return 0;
}

UAkGameplayStatics::UAkGameplayStatics() {
}

