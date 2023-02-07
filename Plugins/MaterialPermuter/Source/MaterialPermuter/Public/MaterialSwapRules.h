#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapActorRules.h"
#include "MaterialSwapDependentRules.h"
#include "MaterialSwapMeshRules.h"
#include "MaterialSwapRules.generated.h"

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialSwapRules {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapMeshRules MeshRules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapActorRules ActorRules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapDependentRules DependentRules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFailOnNoMatches;
    
    FMaterialSwapRules();
};

