#pragma once
#include "CoreMinimal.h"
#include "MunitionToInstigatorData.generated.h"

class AActor;
class AMunitionType_Base;

USTRUCT(BlueprintType)
struct MUNITIONS_API FMunitionToInstigatorData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* InstigatorPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* VictimPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AMunitionType_Base* MunitionBasePtr;
    
    FMunitionToInstigatorData();
};

