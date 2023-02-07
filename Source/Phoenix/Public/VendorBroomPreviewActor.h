#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "VendorBroomPreviewActor.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FVendorBroomPreviewActor : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> BroomPreviewClass;
    
    PHOENIX_API FVendorBroomPreviewActor();
};

