#pragma once
#include "CoreMinimal.h"
#include "VariantMapHandle.h"
#include "VarMapHandleHandlerDynamicSignatureDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_OneParam(FVarMapHandleHandlerDynamicSignature, FVariantMapHandle, VariantMapHandle);

