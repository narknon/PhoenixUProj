#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TutorialLayoutData.generated.h"

USTRUCT(BlueprintType)
struct FTutorialLayoutData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D Position;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D Alignment;
    
    PHOENIX_API FTutorialLayoutData();
};

