#pragma once
#include "CoreMinimal.h"
#include "ModFilter_UseItem_Base.h"
#include "Templates/SubclassOf.h"
#include "ModFilter_UseItem_IsPotion_Custom.generated.h"

class AConsumablePotionItemTool;

UCLASS(Blueprintable, EditInlineNew)
class UModFilter_UseItem_IsPotion_Custom : public UModFilter_UseItem_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AConsumablePotionItemTool> PotionType;
    
public:
    UModFilter_UseItem_IsPotion_Custom();
};

