#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "HerbStaticMeshMapStruct.generated.h"

class UStaticMesh;

USTRUCT(BlueprintType)
struct FHerbStaticMeshMapStruct : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMesh> StaticMesh;
    
    PHOENIX_API FHerbStaticMeshMapStruct();
};

