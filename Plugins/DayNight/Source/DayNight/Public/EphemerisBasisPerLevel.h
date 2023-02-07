#pragma once
#include "CoreMinimal.h"
#include "EphemerisBasisPerLevel.generated.h"

class UEphemerisBasis;

USTRUCT(BlueprintType)
struct FEphemerisBasisPerLevel {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LevelPartialMatch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEphemerisBasis* Basis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseSubString;
    
    DAYNIGHT_API FEphemerisBasisPerLevel();
};

