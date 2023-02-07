#pragma once
#include "CoreMinimal.h"
#include "ModTarget.generated.h"

USTRUCT(BlueprintType)
struct GAMEPLAYMODS_API FModTarget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bQueryBlueprints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* Class;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString PathToProperty;
    
    FModTarget();
};

