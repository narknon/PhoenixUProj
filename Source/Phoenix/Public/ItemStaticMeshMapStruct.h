#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ItemStaticMeshMapStruct.generated.h"

class UStaticMesh;

USTRUCT(BlueprintType)
struct FItemStaticMeshMapStruct : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* StaticMesh;
    
    PHOENIX_API FItemStaticMeshMapStruct();
};

