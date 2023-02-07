#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "TransfigurationResource.h"
#include "TransfigurableObjectInterface.generated.h"

UINTERFACE(Blueprintable)
class UTransfigurableObjectInterface : public UInterface {
    GENERATED_BODY()
};

class ITransfigurableObjectInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ReactivateObject();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ObjectVanished();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ObjectTransformationStarted();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ObjectTransformationConfirmed();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ObjectTransformationCancelled();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ObjectStreamedSpawnInConfirmed();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ObjectPhysicalResponseImpact(float ImpactIntensity, const FName SpellName, const FName ResponseConfigName, const FVector& ImpactLocation);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ObjectConjured();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsObjectContextValidForVanishment();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsObjectContextValidForTransformation();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TArray<FTransfigurationResource> GetAdditionalItemsReturned();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void FinalizeInitialAnimationState();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void DeactivateObject();
    
};

