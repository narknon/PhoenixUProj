#pragma once
#include "CoreMinimal.h"
#include "StencilManagerMatchActor.h"
#include "StencilManagerMatchActorHasStaticMesh.generated.h"

class UStaticMesh;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class STENCILMANAGER_API UStencilManagerMatchActorHasStaticMesh : public UStencilManagerMatchActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMesh> Mesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludeChildActors;
    
    UStencilManagerMatchActorHasStaticMesh();
};

