#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "EModExternalInputMethod.h"
#include "ModTarget.h"
#include "SelectableName.h"
#include "GameplayPropertyMod.generated.h"

class UModExtension;
class UModFilter;
class UObject;

UCLASS(Abstract, Blueprintable)
class GAMEPLAYMODS_API UGameplayPropertyMod : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FModTarget ModTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEvaluateInputOnAddOnly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EModExternalInputMethod ExternalInputSource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSelectableName ExternalInputFunction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag ExternalInputTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LifeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyOnceOnly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDelayedRemoveAfterUse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStackable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UModFilter*> ModAddFilters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UModFilter*> ModApplyFilters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UModExtension*> ModExtensions;
    
    UGameplayPropertyMod();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnModRemoved_BP(UObject* InTargetObject) const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnModApplied_BP(UObject* InTargetObject, bool bFirstTime) const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnModAdded_BP(UObject* InTargetObject) const;
    
};

