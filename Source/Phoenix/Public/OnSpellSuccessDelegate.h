#pragma once
#include "CoreMinimal.h"
#include "OnSpellSuccessDelegate.generated.h"

class AActor;
class ASpellTool;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnSpellSuccess, AActor*, Target, const ASpellTool*, Spell, FName, SpellType);

