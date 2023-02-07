#pragma once
#include "CoreMinimal.h"
#include "GameplayPropertyEntry.h"
#include "PropertyList.generated.h"

USTRUCT(BlueprintType)
struct FPropertyList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FGameplayPropertyEntry> Properties;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bAutomaticallyAdded;
    
    GAMEPLAYMODS_API FPropertyList();
};

