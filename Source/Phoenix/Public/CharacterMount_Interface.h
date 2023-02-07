#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "OnClothTargetsEndDelegate.h"
#include "OnClothTargetsStartDelegate.h"
#include "CharacterMount_Interface.generated.h"

UINTERFACE(BlueprintType, MinimalAPI, meta=(CannotImplementInterfaceInBlueprint))
class UCharacterMount_Interface : public UInterface {
    GENERATED_BODY()
};

class ICharacterMount_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable)
    virtual void SetClothTargetsStartDelegate(const FOnClothTargetsStart& Delegate) PURE_VIRTUAL(SetClothTargetsStartDelegate,);
    
    UFUNCTION(BlueprintCallable)
    virtual void SetClothTargetsEndDelegate(const FOnClothTargetsEnd& Delegate) PURE_VIRTUAL(SetClothTargetsEndDelegate,);
    
};

