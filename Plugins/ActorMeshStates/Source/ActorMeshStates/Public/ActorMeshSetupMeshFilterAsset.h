#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ActorMeshSetupMeshFilterAsset.generated.h"

class UActorMeshSetupMeshFilter;

UCLASS(Blueprintable)
class ACTORMESHSTATES_API UActorMeshSetupMeshFilterAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorMeshSetupMeshFilter* MeshFilter;
    
    UActorMeshSetupMeshFilterAsset();
};

