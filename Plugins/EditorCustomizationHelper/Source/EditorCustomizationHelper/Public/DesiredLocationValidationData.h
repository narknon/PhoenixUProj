#pragma once
#include "CoreMinimal.h"
#include "DesiredLocationValidationData.generated.h"

USTRUCT(BlueprintType)
struct EDITORCUSTOMIZATIONHELPER_API FDesiredLocationValidationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DesiredLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLocationAvailable;
    
    FDesiredLocationValidationData();
};

