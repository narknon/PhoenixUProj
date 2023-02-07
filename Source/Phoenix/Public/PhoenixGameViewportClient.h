#pragma once
#include "CoreMinimal.h"
#include "Engine/GameViewportClient.h"
#include "PhoenixGameViewportClient.generated.h"

UCLASS(Blueprintable, NonTransient)
class UPhoenixGameViewportClient : public UGameViewportClient {
    GENERATED_BODY()
public:
    UPhoenixGameViewportClient();
};

