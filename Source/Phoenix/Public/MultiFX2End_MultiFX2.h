#pragma once
#include "CoreMinimal.h"
#include "FXEnd.h"
#include "MultiFX2End_MultiFX2.generated.h"

class UMultiFX2_Base;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2End_MultiFX2 : public UFXEnd {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> endFX;
    
public:
    UMultiFX2End_MultiFX2();
};

