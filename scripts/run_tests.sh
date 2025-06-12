#!/bin/bash
# Unit-тесты
cd /app && python -m pytest tests/unit --cov=core
# Интеграционные тесты
python -m pytest tests/integration
