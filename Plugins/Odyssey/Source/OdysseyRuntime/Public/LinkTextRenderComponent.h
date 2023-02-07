#pragma once
#include "CoreMinimal.h"
#include "Components/TextRenderComponent.h"
#include "LinkTextRenderComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ULinkTextRenderComponent : public UTextRenderComponent {
    GENERATED_BODY()
public:
    ULinkTextRenderComponent();
};

