#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlendDomain.h"
#include "DynamicCharacterLightRigLight.h"
#include "DynamicLightAdaptationSettings.h"
#include "EDynamicCharacterLightRigChannel.h"
#include "Templates/SubclassOf.h"
#include "DynamicCharacterLightRig.generated.h"

class ADynamicCharacterLightRig;
class UObject;

UCLASS(Blueprintable)
class RENDERSETTINGS_API ADynamicCharacterLightRig : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DayTemperature;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NightTemperature;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDynamicCharacterLightRigLight> Lights;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDynamicCharacterLightRigChannel LightingChannel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDynamicLightAdaptationSettings AdaptationSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlendDomain BlendDomain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseAdaptationSettings;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bInitializedOwnerChannels;
    
public:
    ADynamicCharacterLightRig();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void LightRigEnabled(bool& Enabled);
    
    UFUNCTION(BlueprintCallable)
    static void GetDynamicLightRig(AActor* ToActor, ADynamicCharacterLightRig*& DynamicLightRig);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void Get(AActor* Actor, ADynamicCharacterLightRig*& DynamicLightRig);
    
    UFUNCTION(BlueprintCallable)
    void EnableLightRig(bool Enable);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DynamicLightRigCinematicEnable(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DynamicLightRigCinematicDisable(UObject* WorldContextObject, bool bDisable);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DynamicLightRigCinematicDiabled(UObject* WorldContextObject, bool& bDisabled);
    
    UFUNCTION(BlueprintCallable)
    void DisableLightRig();
    
    UFUNCTION(BlueprintCallable)
    static void AttachDynamicLightRig(AActor* ToActor, TSubclassOf<ADynamicCharacterLightRig> DynamicLightRigClass, ADynamicCharacterLightRig*& DynamicLightRig, FName AttachSocket);
    
};

