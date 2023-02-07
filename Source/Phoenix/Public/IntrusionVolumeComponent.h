#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "EventDateTime.h"
#include "CaughtByAuthorityFigureDelegate.h"
#include "StatList.h"
#include "IntrusionVolumeComponent.generated.h"

class AActor;
class ANPC_Character;
class USceneRig_Intrusion;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UIntrusionVolumeComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString OpeningTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ClosingTime;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCaughtByAuthorityFigure OnCaughtByAuthorityFigure;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRig_Intrusion* IntrusionSceneRig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStatList Stat;
    
    UIntrusionVolumeComponent();
    UFUNCTION(BlueprintCallable)
    FEventDateTime WhenWillPlayerBeDisallowed();
    
    UFUNCTION(BlueprintCallable)
    FEventDateTime WhenWillPlayerBeAllowed();
    
    UFUNCTION(BlueprintCallable)
    void PlayIntrusionSceneRig(ANPC_Character* InNPC);
    
    UFUNCTION(BlueprintCallable)
    void OnIntrusionPerceptionDone(ANPC_Character* InNPC);
    
    UFUNCTION(BlueprintCallable)
    void OnCaught();
    
    UFUNCTION(BlueprintCallable)
    void OnActorEndOverlap(AActor* SelfActor, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    void OnActorBeginOverlap(AActor* SelfActor, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPlayerInIntrusionArea();
    
    UFUNCTION(BlueprintCallable)
    bool IsPlayerAllowed();
    
    UFUNCTION(BlueprintCallable)
    void EnableIntrusion(bool Enable);
    
};

