#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupProcess.h"
#include "ActorMeshSetupProcessFiltered.generated.h"

class UActorMeshSetupMeshFilter;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class ACTORMESHSTATES_API UActorMeshSetupProcessFiltered : public UActorMeshSetupProcess {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorMeshSetupMeshFilter* MeshFilter;
    
    UActorMeshSetupProcessFiltered();
};

