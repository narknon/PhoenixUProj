#pragma once
#include "CoreMinimal.h"
#include "Swarmer.generated.h"

class UStaticMeshComponent;

USTRUCT(BlueprintType)
struct FSwarmer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* Mesh;
    
    PHOENIX_API FSwarmer();
};

