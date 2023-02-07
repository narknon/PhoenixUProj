#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ModEntry.generated.h"

class UFunction;
class UGameplayModComponent;
class UGameplayPropertyMod;

USTRUCT(BlueprintType)
struct FModEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UGameplayPropertyMod* Modifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UFunction* InputValueProvider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UGameplayModComponent* OwnerModComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGuid Handle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float CurrentLifeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bRemove;
    
    GAMEPLAYMODS_API FModEntry();
};

