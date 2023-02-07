#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterNameProperty.generated.h"

USTRUCT(BlueprintType)
struct FMaterialPermuterNameProperty {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    MATERIALPERMUTER_API FMaterialPermuterNameProperty();
};

