#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InputCoreTypes.h"
#include "MastermindDebugCommandManager.h"
#include "PhoenixMMCommandImplementations.generated.h"

UCLASS(Blueprintable)
class UPhoenixMMCommandImplementations : public UMastermindDebugCommandManager {
    GENERATED_BODY()
public:
    UPhoenixMMCommandImplementations();
    UFUNCTION(BlueprintCallable, Exec)
    void ToggleWorldBounds();
    
    UFUNCTION(BlueprintCallable, Exec)
    static bool ToggleWImGUIMainWindow();
    
private:
    UFUNCTION(BlueprintCallable)
    void RunAtDungeonExitDelegate(FVector TargetLocation);
    
    UFUNCTION(BlueprintCallable)
    void RunAtDungeonDelegate(FVector TargetLocation);
    
public:
    UFUNCTION(BlueprintCallable, Exec)
    void ReleaseCamera();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QATargetNearestEnemy();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAStreamingRecordSession(const FString& SessionName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAStreamingForceUnload();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QASetPlayerStart(float locX, float locY, float locZ, float rotX, float rotY, float rotZ);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QASetPlayerRotation(float rotX, float rotY, float rotZ);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QARunForward(float Speed);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QARunAtDungeonExit();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QARunAtDungeonEntrance();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QARecordPlayerLocation(const FString& IdentifyingString);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAPressButtonConsole(const FString& ButtonName, float TimePressed);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAPlayerLookInDirection(float AroundY);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QALookAtActor(const FString& ActorName, float Target);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QALockPlayerPosition(bool Set, float X, float Y, float Z);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QALockPlayerAtCurrentPosition(bool Set);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QALocationLogRemoveLast();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QALocationLogDump();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QALocationLogClear();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QALocationLogAdd(const FString& LocationName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QALevelUp();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAKillNearestEnemy();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAKillEnemiesInRadius(float Radius);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAIsLevelLoaded();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAHoldMMUntilFinishedStreaming();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAGoToPosition(float X, float Y, float Z);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAGodMode();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAGivePlayerResource(const FString& ResourceType, float Amount);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAGivePlayer(const FString& Item);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAGetUpscaleMode();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAGetTODLocations(const FString& TODGroup);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAGetTime();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAGetScreenResolution();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAGetPSOProgress();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAGetPOIs(const FString& SearchString);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAGetPlayerWorldLocation();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAGetPlayerInformation();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAGetPlatform();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAGetOverlandTileInformation();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAGetOverlandLightProbeCaptureTimes();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAGetNearbyEnemies();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAGetNearbyActors();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAGetGameStateInformation();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAGetCL();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAGetCameraInformation();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAGetAverageFrametime(int32 FrameSampleCount, int32 SampleFrequencyMS);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAGetAllLocation(const FString& ActorName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QACameraLookInDirection(float AroundY, float AroundZ);
    
    UFUNCTION(BlueprintCallable, Exec)
    static bool InputKeyConsoleCommand(const FString& KeyStates, const FString& Button);
    
private:
    UFUNCTION(BlueprintCallable)
    void HoldStreamingUpdate();
    
    UFUNCTION(BlueprintCallable)
    void ButtonDelegate(FKey Key);
    
};

