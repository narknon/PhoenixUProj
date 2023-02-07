#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DbSingleColumnInfo.h"
#include "Engine/EngineTypes.h"
#include "Engine/TriggerBox.h"
#include "EFocusTriggerType.h"
#include "SocialActionTypes.h"
#include "SocialSemanticIDs.h"
#include "FocusTrigger.generated.h"

class AActor;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class AFocusTrigger : public ATriggerBox {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EFocusTriggerType> FocusTriggerType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StartInactive;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> TheFocusActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo AttachToDBID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector TheAttachOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector TheFocusOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TheFocusProbablity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TheActionProbablity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlayerFocusProbablity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlayerActionProbablity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo TheReaction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo TheEmotion;
    
public:
    AFocusTrigger();
    UFUNCTION(BlueprintCallable)
    void SetTheReaction(SocialActionTypes InSocialAction);
    
    UFUNCTION(BlueprintCallable)
    void SetTheFocusProbablity(float InProbability);
    
    UFUNCTION(BlueprintCallable)
    void SetTheFocusOffset(FVector InFocusOffset);
    
    UFUNCTION(BlueprintCallable)
    void SetTheFocusActor(AActor* InFocusActor);
    
    UFUNCTION(BlueprintCallable)
    void SetTheEmotion(SocialSemanticIDs InEmotion);
    
    UFUNCTION(BlueprintCallable)
    void SetTheActionProbablity(float InProbability);
    
    UFUNCTION(BlueprintCallable)
    void SetPlayerFocusProbablity(float InProbability);
    
    UFUNCTION(BlueprintCallable)
    void SetPlayerActionProbablity(float InProbability);
    
    UFUNCTION(BlueprintCallable)
    void SetAbsoluteExtents(const FVector& InAbsoluteExtents);
    
    UFUNCTION(BlueprintCallable)
    void Deactivate();
    
protected:
    UFUNCTION(BlueprintCallable)
    void ActorOverlapEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void ActorOverlapBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& OverlapInfo);
    
public:
    UFUNCTION(BlueprintCallable)
    void Activate();
    
};

