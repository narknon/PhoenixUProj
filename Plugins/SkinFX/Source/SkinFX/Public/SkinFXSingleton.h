#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SkinFXEffectDefinition.h"
#include "Templates/SubclassOf.h"
#include "SkinFXSingleton.generated.h"

class ASkinFXDefinition;
class USimpleDataSet;
class USkinFXLibrary;

UCLASS(Blueprintable, NotPlaceable, Transient)
class SKINFX_API ASkinFXSingleton : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkinFXLibrary* Library;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<ASkinFXDefinition>, FSkinFXEffectDefinition> Definitions;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USimpleDataSet* DataDependencies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bSignalledAllReady;
    
public:
    ASkinFXSingleton();
};

