#pragma once
#include "CoreMinimal.h"
#include "DuelTechnique_UIData.generated.h"

USTRUCT(BlueprintType)
struct PHOENIX_API FDuelTechnique_UIData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString TechniqueDesc;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ValueIsCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TechniqueID;
    
    FDuelTechnique_UIData();
};

