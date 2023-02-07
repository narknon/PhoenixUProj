#pragma once
#include "CoreMinimal.h"
#include "GearUI.generated.h"

USTRUCT(BlueprintType)
struct FGearUI {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SourceID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> Descriptions;
    
    PHOENIX_API FGearUI();
};

