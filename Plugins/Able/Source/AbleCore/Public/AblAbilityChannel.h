#pragma once
#include "CoreMinimal.h"
#include "EAblAbilityTaskResult.h"
#include "AblAbilityChannel.generated.h"

class UAblAbilityContext;
class UAblAbilityInstance;
class UAblBoneBlendWeightAsset;

USTRUCT(BlueprintType)
struct ABLECORE_API FAblAbilityChannel {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsAdditive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAblBoneBlendWeightAsset* BoneBlendWeightAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAblAbilityInstance* ActiveAbilityInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAblAbilityInstance*> PassiveAbilityInstances;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAblAbilityContext*> PendingContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TEnumAsByte<EAblAbilityTaskResult>> PendingResult;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAblAbilityContext*> AsyncContexts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAblAbilityInstance*> FadingAbilities;
    
public:
    FAblAbilityChannel();
};

