#pragma once
#include "CoreMinimal.h"
#include "MeshRule.h"
#include "MeshOverride.generated.h"

class USkeletalMesh;

USTRUCT(BlueprintType)
struct FMeshOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMeshRule> Rules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeletalMesh* Mesh;
    
    CUSTOMIZABLECHARACTER_API FMeshOverride();
};

