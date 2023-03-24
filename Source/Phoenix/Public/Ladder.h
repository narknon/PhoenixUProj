#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ladder.generated.h"

UCLASS(Blueprintable)
class ALadder : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPlayerClimbingEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPlayerMountTopEnabled;
    
public:
    ALadder(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    float GetMeshHeight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetLadderTopZ() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    int32 GetLadderHeight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetLadderBottomZ() const;
    
    UFUNCTION(BlueprintCallable)
    void EnablePlayerMountTop();
    
    UFUNCTION(BlueprintCallable)
    void EnablePlayerClimbing();
    
    UFUNCTION(BlueprintCallable)
    void DisablePlayerMountTop();
    
    UFUNCTION(BlueprintCallable)
    void DisablePlayerClimbing();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool CanPlayerClimbLadder() const;
    
};

