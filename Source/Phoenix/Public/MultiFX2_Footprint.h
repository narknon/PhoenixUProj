#pragma once
#include "CoreMinimal.h"
#include "MultiFX2_Filtered.h"
#include "EFootprintTypes.h"
#include "MultiFX2_FootprintInfo.h"
#include "MultiFX2_Footprint.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_Footprint : public UMultiFX2_Filtered {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EFootprintTypes, FMultiFX2_FootprintInfo> InfoMap;
    
public:
    UMultiFX2_Footprint();
};

