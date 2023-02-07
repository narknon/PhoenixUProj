#pragma once
#include "CoreMinimal.h"
#include "BoolProvider.h"
#include "EBool_PlayerHouse.h"
#include "Bool_PlayerHouse.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UBool_PlayerHouse : public UBoolProvider {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EBool_PlayerHouse PlayerHouse;
    
    UBool_PlayerHouse();
};

