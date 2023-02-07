#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GlobalLightingBlendableList.h"
#include "GlobalLightingMasterStack.h"
#include "GlobalLightingSingleton.generated.h"

class UWorld;
class UWorldBaseHeightSingleton;

UCLASS(Blueprintable, Transient)
class GLOBALLIGHTRIG_API UGlobalLightingSingleton : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UWorld>, FGlobalLightingMasterStack> MasterMap;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UWorld>, FGlobalLightingBlendableList> BlendableListMap;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UWorld>, UWorldBaseHeightSingleton*> WorldBaseHeightMap;
    
public:
    UGlobalLightingSingleton();
    UFUNCTION(BlueprintCallable)
    static void RegisterGlobalLightingObject(UObject* BlendableLightingObject);
    
    UFUNCTION(BlueprintCallable)
    static void IsRegisteredGlobalLightingObject(UObject* BlendableLightingObject, bool& registered);
    
    UFUNCTION(BlueprintCallable)
    static void DeregisterGlobalLightingObject(UObject* BlendableLightingObject);
    
};

