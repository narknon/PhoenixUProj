#pragma once
#include "CoreMinimal.h"
#include "MunitionImpactData.h"
#include "SpellImpactSignatureDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSpellImpactSignature, AActor*, Target, FMunitionImpactData, MunitionImpactData);

