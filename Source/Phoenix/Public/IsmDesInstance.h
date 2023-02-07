#pragma once
#include "CoreMinimal.h"
#include "IsmDesInstance.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FIsmDesInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* DA;
    
    PHOENIX_API FIsmDesInstance();
};

