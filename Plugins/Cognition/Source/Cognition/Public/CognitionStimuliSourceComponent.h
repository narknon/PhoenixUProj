#pragma once
#include "CoreMinimal.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "UObject/NoExportTypes.h"
#include "Styling/SlateColor.h"
#include "CalloutInformation.h"
#include "ECalloutActions.h"
#include "ECalloutBlipType.h"
#include "ECalloutType.h"
#include "ESocialCombatMode.h"
#include "CogGroupEvaluation.h"
#include "AISenseFOVDetails.h"
#include "CogTargetSceneComponent.h"
#include "CogGroupTargetPoint.h"
#include "CogGroupLookAtPoint.h"
#include "Templates/SubclassOf.h"
#include "CognitionStimuliSourceComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class COGNITION_API UCognitionStimuliSourceComponent : public UAIPerceptionStimuliSourceComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UAISense>, UAISenseSpecificDetails*> SenseSpecificDetails;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UCogGroupEvaluation*> TargetEvaluationArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FootprintRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TopOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BottomOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PriorityWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VsPlayerPriorityWeightBump;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FarDistance_Override;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FOV_Override;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESocialCombatMode SocialORCombatMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreLineOfSight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreScreenSpace;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpecialOnScreenTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisallowInteractInCombat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisallowAimTargeting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCogGroupTargetPoint* TargetPointClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCogGroupLookAtPoint* LookAtPointClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector CalloutOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAISenseFOVDetails*> TargetFOVDetails;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLockOnEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxLockOnDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRecordInteractLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowTargetWhileStandingOn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideMinAimDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinAimDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECalloutType CalloutType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECalloutBlipType CalloutBlipType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECalloutActions CalloutAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TargetText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateColor CalloutTextColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bGrayOutButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsTargetTextTranslatable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector CustomTargetPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector CustomLookAtPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ChargeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CalloutInteractDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UAISense>, UCogTargetSceneComponent*> SenseSpecificTargetSceneComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UCogGroupTargetPoint>, UCogTargetSceneComponent*> TargetPointSpecificTargetSceneComponents;
    
    UCognitionStimuliSourceComponent();
    UFUNCTION(BlueprintCallable)
    void SetPriorityWeight(float weight);
    
    UFUNCTION(BlueprintCallable)
    void SetIgnoreLineOfSight(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void SetFootprintRadius(float Radius);
    
    UFUNCTION(BlueprintCallable)
    void SetAutoRegisterAsSource(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    bool IsRegisteredForSense(TSubclassOf<UAISense> SenseToFind);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsOwned() const;
    
    UFUNCTION(BlueprintCallable)
    UAISenseSpecificDetails* GetSenseSpecificDetails(const TSubclassOf<UAISense> InSense);
    
    UFUNCTION(BlueprintCallable)
    float GetPriorityWeight();
    
    UFUNCTION(BlueprintCallable)
    bool GetIgnoreLineOfSight();
    
    UFUNCTION(BlueprintCallable)
    float GetFootprintRadius();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAutoRegisterAsSource() const;
    
    UFUNCTION(BlueprintCallable)
    void ChangeInformation(const FCalloutInformation& NewInformation);
    
    UFUNCTION(BlueprintCallable)
    float CalculateRadiusNeededToBePerceivedBy(float DistanceFromPerceiver, AController* PerceiverController, TSubclassOf<UAISense> SenseToUse, bool bIncludePerceiverRadius);
    
    UFUNCTION(BlueprintCallable)
    void AddRegisterAsSourceForSenses(const TSubclassOf<UAISense>& Sense);

    virtual void OnRegister() override;
    
};

