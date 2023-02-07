#pragma once
#include "CoreMinimal.h"
#include "SelectableName.h"
#include "ModFilter_ItemProperty_Base.h"
#include "ModFilter_ItemProperty_Custom.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UModFilter_ItemProperty_Custom : public UModFilter_ItemProperty_Base {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSelectableName ItemType;
    
public:
    UModFilter_ItemProperty_Custom();
};

